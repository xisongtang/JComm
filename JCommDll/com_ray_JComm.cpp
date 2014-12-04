#include "com_ray_JComm.h"
#include <jni.h>

#include <windows.h>
#include <assert.h>
#include <stdlib.h>

struct cobj{
	jstring device;
	jlong baud;
	jint stop;
	jint data;
	jint parity;
	jint dtr;
	jint rts;
	jint flow;
	jint timeout;
	HANDLE handle;
};
static const char *deviceVarName = "device";
static const char *baudVarName = "baud";
static const char *stopVarName = "stop";
static const char *dataVarName = "data";
static const char *parityVarName = "parity";
static const char *dtrVarName = "dtr";
static const char *rtsVarName = "rts";
static const char *flowVarName = "flow";
static const char *handleVarName = "handle";
static const char *timeoutVarName = "timeout";

static HANDLE getHANDLE(JNIEnv *env, jobject obj)
{
	return reinterpret_cast<HANDLE>(env->GetLongField(obj, env->GetFieldID(env->GetObjectClass(obj), handleVarName, "J")));
}

static cobj* getCObj(JNIEnv *env, jobject obj)
{
	cobj *co = new cobj();

	jclass c = env->GetObjectClass(obj);
	jfieldID deviceID = env->GetFieldID(c, deviceVarName, "Ljava/lang/String;");
	co->device = (jstring)env->GetObjectField(obj, deviceID);
	jfieldID baudID  = env->GetFieldID(c, baudVarName, "J");
	co->baud = env->GetLongField(obj, baudID);
	jfieldID stopID  = env->GetFieldID(c, stopVarName, "I");
	co->stop = env->GetIntField(obj, stopID);
	jfieldID dataID  = env->GetFieldID(c, dataVarName, "I");
	co->data = env->GetIntField(obj, dataID);
	jfieldID parityID  = env->GetFieldID(c, parityVarName, "I");
	co->parity = env->GetIntField(obj, parityID);
	jfieldID dtrID  = env->GetFieldID(c, dtrVarName, "I");
	co->dtr = env->GetIntField(obj, dtrID);
	jfieldID rtsID  = env->GetFieldID(c, rtsVarName, "I");
	co->rts = env->GetIntField(obj, rtsID);
	jfieldID flowID  = env->GetFieldID(c, flowVarName, "I");
	co->flow = env->GetIntField(obj, flowID);
	jfieldID timeoutID  = env->GetFieldID(c, timeoutVarName, "I");
	co->timeout = env->GetIntField(obj, timeoutID);
	co->handle = getHANDLE(env, obj);
	return co;
}

static void release(cobj *obj)
{
	delete obj;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1setoption
  (JNIEnv *env, jobject obj)
{
	cobj *co = getCObj(env, obj);
	HANDLE h = co->handle;
	if (h == 0)
		return com_ray_JComm_ERROR_NOTOPEN;
	DCB pdcb;
	if (!GetCommState(h, &pdcb))
	{
		release(co);
		return com_ray_JComm_ERROR_UNKNOWN;
	}
	pdcb.BaudRate = co->baud;
	pdcb.fDtrControl = co->dtr;
	pdcb.fRtsControl = co->rts;
	pdcb.Parity = co->parity;
	pdcb.StopBits = co->stop;
	pdcb.ByteSize = co->data;
	switch (co->flow)
	{
	case com_ray_JComm_RS232_FLOW_NONE:
		pdcb.fOutxCtsFlow = FALSE;
		pdcb.fRtsControl = RTS_CONTROL_DISABLE;
		pdcb.fInX = FALSE;
		pdcb.fOutX = FALSE;
		break;
	case com_ray_JComm_RS232_FLOW_HW:
		pdcb.fOutxCtsFlow = TRUE;
		pdcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
		pdcb.fInX = FALSE;
		pdcb.fOutX = FALSE;
		break;
	case com_ray_JComm_RS232_FLOW_XON_XOFF:
		pdcb.fOutxCtsFlow = FALSE;
		pdcb.fRtsControl = RTS_CONTROL_DISABLE;
		pdcb.fInX = TRUE;
		pdcb.fOutX = TRUE;
		break;
	}
	if (!SetCommState(h, &pdcb))
	{
		release(co);
		return com_ray_JComm_ERROR_UNKNOWN;
	}
	release(co);
	return com_ray_JComm_ERROR_NOERROR;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1open
  (JNIEnv *env, jobject obj)
{
	cobj *co = getCObj(env, obj);
	HANDLE h = co->handle;
	const jchar *jcs = env->GetStringChars(co->device, NULL);
	jint clen = env->GetStringLength(co->device);
	char *name = (char *)malloc(clen * sizeof(char));
	for (int i = 0; i != clen; ++i)
		name[i] = jcs[i];
	h =  CreateFile(name, GENERIC_READ | GENERIC_WRITE,
		0,
	    NULL, OPEN_EXISTING, 0, NULL);
	if (h == (HANDLE) -1)
	{
		release(co);
		return com_ray_JComm_ERROR_CANTOPEN;
	}
	env->SetLongField(obj, env->GetFieldID(env->GetObjectClass(obj), handleVarName, "J"), reinterpret_cast<jlong>(h));
	release(co);
	return 0;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1close
  (JNIEnv *env, jobject obj)
{
	HANDLE handle = getHANDLE(env, obj);
	if (handle == 0)
		return com_ray_JComm_ERROR_NOTOPEN;

	if (CloseHandle(handle) == 0)
		return com_ray_JComm_ERROR_CLOSE;

	return com_ray_JComm_ERROR_NOERROR;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1write
  (JNIEnv *env, jobject obj, jbyteArray byteArray, jint wlen)
{
	HANDLE handle = getHANDLE(env, obj);
	if (handle == NULL)
		return com_ray_JComm_ERROR_NOTOPEN;	
	
	jbyte *bytes = env->GetByteArrayElements(byteArray, NULL);
	jint len = env->GetArrayLength(byteArray);
	assert(len >= wlen);
	long unsigned alen = 0;
	if (!WriteFile(handle, bytes, wlen, &alen, NULL))
		return com_ray_JComm_ERROR_WRITE;
	return alen;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1read
  (JNIEnv *env, jobject obj, jbyteArray byteArray)
{
	jbyte *bytes = env->GetByteArrayElements(byteArray, NULL);
	jint len = env->GetArrayLength(byteArray);
	HANDLE handle = getHANDLE(env, obj);
	if (handle == NULL)
		return com_ray_JComm_ERROR_NOTOPEN;

	unsigned char *uchars = new unsigned char[len];
	long unsigned rlen;
	if (!ReadFile(handle, uchars, len, &rlen, NULL)) 
	{
		delete uchars;
		return com_ray_JComm_ERROR_READ;
	}

	for (int i = 0; i != rlen; ++i)
		bytes[i] = uchars[i];
	env->SetByteArrayRegion(byteArray, 0, rlen, bytes);

	delete uchars;
	return rlen;
}

JNIEXPORT jint JNICALL Java_com_ray_JComm__1settimeout
  (JNIEnv *env, jobject obj, jint jtimeout)
{
	HANDLE h = getHANDLE(env, obj);
	COMMTIMEOUTS t;
	if (h == NULL)
		return com_ray_JComm_ERROR_NOTOPEN;

	GetCommTimeouts(h, &t);
	t.ReadIntervalTimeout = 0;
	t.ReadTotalTimeoutMultiplier = 0;
	t.ReadTotalTimeoutConstant = jtimeout;
	t.WriteTotalTimeoutMultiplier = 0;
	t.WriteTotalTimeoutConstant = jtimeout;

	SetCommTimeouts(h, &t);

	return com_ray_JComm_ERROR_NOERROR;
}
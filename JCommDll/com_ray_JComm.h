/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ray_JComm */

#ifndef _Included_com_ray_JComm
#define _Included_com_ray_JComm
#ifdef __cplusplus
extern "C" {
#endif
#undef com_ray_JComm_RS232_BAUD_110
#define com_ray_JComm_RS232_BAUD_110 110i64
#undef com_ray_JComm_RS232_BAUD_300
#define com_ray_JComm_RS232_BAUD_300 300i64
#undef com_ray_JComm_RS232_BAUD_600
#define com_ray_JComm_RS232_BAUD_600 600i64
#undef com_ray_JComm_RS232_BAUD_1200
#define com_ray_JComm_RS232_BAUD_1200 1200i64
#undef com_ray_JComm_RS232_BAUD_2400
#define com_ray_JComm_RS232_BAUD_2400 2400i64
#undef com_ray_JComm_RS232_BAUD_4800
#define com_ray_JComm_RS232_BAUD_4800 4800i64
#undef com_ray_JComm_RS232_BAUD_9600
#define com_ray_JComm_RS232_BAUD_9600 9600i64
#undef com_ray_JComm_RS232_BAUD_14400
#define com_ray_JComm_RS232_BAUD_14400 14400i64
#undef com_ray_JComm_RS232_BAUD_19200
#define com_ray_JComm_RS232_BAUD_19200 19200i64
#undef com_ray_JComm_RS232_BAUD_38400
#define com_ray_JComm_RS232_BAUD_38400 38400i64
#undef com_ray_JComm_RS232_BAUD_57600
#define com_ray_JComm_RS232_BAUD_57600 57600i64
#undef com_ray_JComm_RS232_BAUD_115200
#define com_ray_JComm_RS232_BAUD_115200 115200i64
#undef com_ray_JComm_RS232_BAUD_128000
#define com_ray_JComm_RS232_BAUD_128000 128000i64
#undef com_ray_JComm_RS232_BAUD_256000
#define com_ray_JComm_RS232_BAUD_256000 256000i64
#undef com_ray_JComm_RS232_DATA_5
#define com_ray_JComm_RS232_DATA_5 5L
#undef com_ray_JComm_RS232_DATA_6
#define com_ray_JComm_RS232_DATA_6 6L
#undef com_ray_JComm_RS232_DATA_7
#define com_ray_JComm_RS232_DATA_7 7L
#undef com_ray_JComm_RS232_DATA_8
#define com_ray_JComm_RS232_DATA_8 8L
#undef com_ray_JComm_RS232_PARITY_NONE
#define com_ray_JComm_RS232_PARITY_NONE 0L
#undef com_ray_JComm_RS232_PARITY_ODD
#define com_ray_JComm_RS232_PARITY_ODD 1L
#undef com_ray_JComm_RS232_PARITY_EVEN
#define com_ray_JComm_RS232_PARITY_EVEN 2L
#undef com_ray_JComm_RS232_PARITY_MARK
#define com_ray_JComm_RS232_PARITY_MARK 3L
#undef com_ray_JComm_RS232_PARITY_SPACE
#define com_ray_JComm_RS232_PARITY_SPACE 4L
#undef com_ray_JComm_RS232_STOP_1
#define com_ray_JComm_RS232_STOP_1 0L
#undef com_ray_JComm_RS232_STOP_1_5
#define com_ray_JComm_RS232_STOP_1_5 1L
#undef com_ray_JComm_RS232_STOP_2
#define com_ray_JComm_RS232_STOP_2 2L
#undef com_ray_JComm_RS232_DTR_DISABLE
#define com_ray_JComm_RS232_DTR_DISABLE 0L
#undef com_ray_JComm_RS232_DTR_ENABLE
#define com_ray_JComm_RS232_DTR_ENABLE 1L
#undef com_ray_JComm_RS232_DTR_HANDSHAKE
#define com_ray_JComm_RS232_DTR_HANDSHAKE 2L
#undef com_ray_JComm_RS232_RTS_DISABLE
#define com_ray_JComm_RS232_RTS_DISABLE 0L
#undef com_ray_JComm_RS232_RTS_ENABLE
#define com_ray_JComm_RS232_RTS_ENABLE 1L
#undef com_ray_JComm_RS232_RTS_HANDSHAKE
#define com_ray_JComm_RS232_RTS_HANDSHAKE 2L
#undef com_ray_JComm_RS232_RTS_TOGGLE
#define com_ray_JComm_RS232_RTS_TOGGLE 3L
#undef com_ray_JComm_RS232_FLOW_NONE
#define com_ray_JComm_RS232_FLOW_NONE 0L
#undef com_ray_JComm_RS232_FLOW_HW
#define com_ray_JComm_RS232_FLOW_HW 1L
#undef com_ray_JComm_RS232_FLOW_XON_XOFF
#define com_ray_JComm_RS232_FLOW_XON_XOFF 2L
#undef com_ray_JComm_ERROR_NOERROR
#define com_ray_JComm_ERROR_NOERROR 0L
#undef com_ray_JComm_ERROR_NODATA
#define com_ray_JComm_ERROR_NODATA -1L
#undef com_ray_JComm_ERROR_UNKNOWN
#define com_ray_JComm_ERROR_UNKNOWN -2L
#undef com_ray_JComm_ERROR_NOTOPEN
#define com_ray_JComm_ERROR_NOTOPEN -3L
#undef com_ray_JComm_ERROR_CANTOPEN
#define com_ray_JComm_ERROR_CANTOPEN -4L
#undef com_ray_JComm_ERROR_WRITE
#define com_ray_JComm_ERROR_WRITE -5L
#undef com_ray_JComm_ERROR_READ
#define com_ray_JComm_ERROR_READ -6L
#undef com_ray_JComm_ERROR_CLOSE
#define com_ray_JComm_ERROR_CLOSE -7L
/*
 * Class:     com_ray_JComm
 * Method:    _open
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1open
  (JNIEnv *, jobject);

/*
 * Class:     com_ray_JComm
 * Method:    _close
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1close
  (JNIEnv *, jobject);

/*
 * Class:     com_ray_JComm
 * Method:    _settimeout
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1settimeout
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_ray_JComm
 * Method:    _write
 * Signature: ([BI)I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1write
  (JNIEnv *, jobject, jbyteArray, jint);

/*
 * Class:     com_ray_JComm
 * Method:    _read
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1read
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     com_ray_JComm
 * Method:    _setoption
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_ray_JComm__1setoption
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
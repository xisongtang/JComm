import com.ray.JComm;
import java.io.IOException;
class main{
	public static void main(String[] args) throws IOException{
		JComm com = new JComm();
		com.setDevice("COM3");
		com.open();
		byte[] bytes = new byte[]{1, 2, 3, 4};
		System.out.println(com.write(bytes));
		bytes = com.read();
		System.out.println(new String(bytes));
		com.close()	;
	}
}
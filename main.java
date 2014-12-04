import com.ray.JComm;
import java.io.IOException;
class main{
	public static void main(String[] args) throws IOException{
		JComm com = new JComm();

		//get the active ports
		String[] names = JComm.getCommNames();
		System.out.println(names.length);
		for (int i = 0; i != names.length; ++i){
			System.out.println(names[i]);
		}

		//open, you can control many ports at the same time
		com.setDevice(names[0]);
		com.open();

		//write
		byte[] bytes = new byte[]{1, 2, 3, 4};
		System.out.println(com.write(bytes));

		//read
		bytes = com.read();
		System.out.println(new String(bytes));

		//close
		com.close();
	}
}
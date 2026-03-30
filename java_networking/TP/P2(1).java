package Pack;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class P2 {

	public static void main(String[] args) {
try {
	ServerSocket s = new ServerSocket(2002);
	
	Socket con = s.accept();
	ObjectInputStream in = new ObjectInputStream(con.getInputStream());
	String N = (String)in.readObject();
	String M = Integer.toString(Integer.parseInt(N)*2);
	System.out.println("M="+M);
	
	Socket c = new Socket("localhost", 2003);
	ObjectOutputStream out = new ObjectOutputStream(c.getOutputStream());
	out.writeObject(M);
	
	ObjectInputStream inp3= new ObjectInputStream(c.getInputStream());
	String S = (String)inp3.readObject();
	System.out.println("S="+S);
	ObjectOutputStream outp1 = new ObjectOutputStream(con.getOutputStream());
	outp1.writeObject(S);
	
	c.close();out.close();inp3.close();
	
	in.close();con.close();s.close();
	

			
		}
		catch(Exception e) {System.out.println("Exception: "+e.toString());}

	}

}

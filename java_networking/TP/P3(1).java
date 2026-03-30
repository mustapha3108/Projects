package Pack;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class P3 {

public static void main(String[] args) {
try {
	ServerSocket s = new ServerSocket(2003);
	Socket con = s.accept();
	ObjectInputStream in = new ObjectInputStream(con.getInputStream());
	String M = (String) in.readObject();
	String S = Integer.toString(Integer.parseInt(M)*3);
	System.out.println("S="+S);
	
	ObjectOutputStream out = new ObjectOutputStream(con.getOutputStream());
	out.writeObject(S);
	out.close();
	s.close();in.close();con.close();
			
		}
		catch(Exception e) {System.out.println("Exception: "+e.toString());}

	}

}

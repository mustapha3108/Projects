package tp2;

import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/*
public class p3 {
 
    public static void main(String[] args) {

        try{
            //server stuff
            ServerSocket server = new ServerSocket(2003);            
            Socket p2cnx = server.accept(); 

            //client stuff
            Socket sendtop4 = new Socket("p4ip", 2004);
            Socket sendtop2 = new Socket("p2ip", 2004);
            

            while (true) {

                //recieve from p2
                ObjectInputStream recp2 = new ObjectInputStream(p2cnx.getInputStream());  
                String p2message = (String)recp2.readObject();
                String number = Integer.toString(Integer.parseInt(p2message)*2);

                //send to p4
                ObjectOutputStream outp4 = new ObjectOutputStream(sendtop4.getOutputStream());
                outp4.writeObject(outp4);

                //recieve from p4
                ObjectInputStream recp4 = new ObjectInputStream(p2cnx.getInputStream());  
                String p4message = (String)recp4.readObject();
                number = Integer.toString(Integer.parseInt(p4message)*2);

                //send back to p2
                ObjectOutputStream outp2 = new ObjectOutputStream(sendtop2.getOutputStream());
                outp2.writeObject(number);
                
            }

            
        }
        catch (Exception e) {
           System.out.println("Exception");
        }
    }    
    
}



*/

public class P3 {

	public static void main(String[] args) {
try {
	ServerSocket s = new ServerSocket(2002);
	Socket con = s.accept();
	ObjectInputStream in = new ObjectInputStream(con.getInputStream());
	String N = (String)in.readObject();
	String M = Integer.toString(Integer.parseInt(N)*2);
	System.out.println("M="+M);
	
	Socket c = new Socket("10.172.99.161", 2003);
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

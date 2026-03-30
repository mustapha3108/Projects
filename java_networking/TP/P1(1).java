package TP;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class P1 {

	public static void main(String[] args) {
		try {
		Scanner sc = new Scanner(System.in);
		System.out.println("Donner N: ");
		String N = sc.next();
		
		Socket c = new Socket("localhost", 2002);
		ObjectOutputStream out = new ObjectOutputStream(c.getOutputStream());
		out.writeObject(N);
		
		ObjectInputStream inp2= new ObjectInputStream(c.getInputStream());
		String S = (String)inp2.readObject();
		System.out.println("S="+S);
		
		out.close();c.close();sc.close();inp2.close();
		
	
			
		}
		catch(Exception e) {System.out.println("Exception: "+e.toString());}

	}

}

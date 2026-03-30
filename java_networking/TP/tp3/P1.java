package tp3;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class P1 { // Client

	public static void main(String[] args) {
		try {
			DatagramSocket c = new DatagramSocket();
			
			while (true) {
				Scanner var1 = new Scanner(System.in);
				String ch = var1.nextLine();
				byte[] SendT = new byte[ch.length()];
				SendT=ch.getBytes();
				InetAddress ip = InetAddress.getByName("10.172.99.23");
				System.out.println(ip);
				DatagramPacket p = new DatagramPacket(SendT, SendT.length, ip, 9876);
				c.send(p);

				DatagramPacket q = new DatagramPacket(SendT,SendT.length);
				c.receive(q);
				ch = new String(q.getData());
				System.out.println("Receive:"+ch+" From:"+q.getAddress()+" Port:"+q.getPort());
			}

		}
		catch (Exception e) {System.out.println("Exception:"+e.toString());}

	}

}

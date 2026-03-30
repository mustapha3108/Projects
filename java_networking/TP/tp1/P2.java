import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class P2 { // Serveur

	public static void main(String[] args) {
		try {
		System.out.println("Creation de service sur le port 2004");
		ServerSocket s = new ServerSocket(6600);
		while(true) {
		System.out.println("Waiting .....");
		Socket connection = s.accept();
		System.out.println("Accpeted ....");
		ObjectInputStream in = new ObjectInputStream(connection.getInputStream());
		String ch = (String)in.readObject();
		System.out.println("Ch = "+ ch);

		Scanner sc = new Scanner(System.in);

        System.out.print("tapez le message: ");
        String mymessage = sc.nextLine();

		ObjectOutputStream out = new ObjectOutputStream(connection.getOutputStream());
		out.writeObject(mymessage);
        out.flush();

		sc.close();
		out.close();

		}
		//s.close();in.close();connection.close();
		}
		catch(Exception e) {
			System.out.println("Exception");
		}
	}

}

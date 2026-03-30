package crow;

import java.util.Scanner;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class p1 {
    public static void main(String[] args) {
        try{
            //scanner
            Scanner sc = new Scanner(System.in);

            //the receiver
            Socket receiver = new Socket("localhost", 2002);
            ObjectOutputStream recieveroutput = new ObjectOutputStream(receiver.getOutputStream());
            recieveroutput.flush();
            ObjectInputStream recieverinput = new ObjectInputStream(receiver.getInputStream());

            //message exchange
            while (true) {

                System.out.println("Enter an integer: ");
                Integer message = sc.nextInt();

                recieveroutput.writeObject(message);
                recieveroutput.flush();

                Integer ack = (Integer) recieverinput.readObject();

                System.out.println(ack);

            }
        }
        catch (Exception e) {
           System.out.println("Exception");
        }
    }
}

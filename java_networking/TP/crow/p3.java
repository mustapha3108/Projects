package crow;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class p3 {
    public static void main(String[] args) {
        try{
            //start server
            ServerSocket me = new ServerSocket(2003);

            //the sender
            Socket sender = me.accept();
            ObjectInputStream senderinput = new ObjectInputStream(sender.getInputStream());
            ObjectOutputStream senderoutput = new ObjectOutputStream(sender.getOutputStream());
            senderoutput.flush();
            
            //the receiver
            Socket receiver = new Socket("localhost", 2004);
            ObjectOutputStream recieveroutput = new ObjectOutputStream(receiver.getOutputStream());
            recieveroutput.flush();
            ObjectInputStream recieverinput = new ObjectInputStream(receiver.getInputStream());

            //message exchange
            while (true) {

                Integer sendermessage = (Integer) senderinput.readObject();
                Integer message = sendermessage * 3;

                recieveroutput.writeObject(message);
                recieveroutput.flush();

                Integer ack = (Integer) recieverinput.readObject();

                senderoutput.writeObject(ack);
                senderoutput.flush();

            }
        }
        catch (Exception e) {
           System.out.println("Exception");
        }
    }
}

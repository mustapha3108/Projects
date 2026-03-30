package crow;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class p4 {
    public static void main(String[] args) {
        try{
            //start server
            ServerSocket me = new ServerSocket(2004);

            //the sender
            Socket sender = me.accept();
            ObjectInputStream senderinput = new ObjectInputStream(sender.getInputStream());
            ObjectOutputStream senderoutput = new ObjectOutputStream(sender.getOutputStream());
            senderoutput.flush();
            
            //message exchange
            while (true) {

                Integer sendermessage = (Integer) senderinput.readObject();
                Integer ack = sendermessage * 4;
                System.out.println("recieved: " + sendermessage + " going to send: " + ack);

                senderoutput.writeObject(ack);
                senderoutput.flush();

            }
        }
        catch (Exception e) {
           System.out.println("Exception");
        }
    }
}

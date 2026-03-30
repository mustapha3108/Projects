import java.net.Socket;
import java.io.ObjectOutputStream;

public class P1 {// client
    public static void main(String[] args) {
        System.out.println("Hello Java");

        try{
            System.out.println("Demande de connexion");
            Socket c = new Socket("localhoste", 2007);
            System.out.println("Connected");
            ObjectOutputStream out = new ObjectOutputStream(c.getOutputStream());
            out.writeObject("RSD");
            c.close(); out.close();
        }
        catch (Exception e) {
            System.out.println("Exception" + e.toString());
        }

    }
}

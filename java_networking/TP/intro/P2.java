import java.net.ServerSocket;

public class P2 { //server
    public static void main(String[] args) {

        try{
            System.out.println("Exception");
            ServerSocket s = new ServerSocket(2007);
            System.out.println("Waiting ...");
            Socket cnx = s.accept();
            System.out.println("Accepted");
            ObjectInputStream in = new ObjectInputStream(cnx.getInputStream);
            String ch = (String) in.readObject();
            System.out.println(ch);
            in.close(); s.close(); cnx.close();    
        }
        catch (Exception e) {
           System.out.println("Exception");
        }
    }
}

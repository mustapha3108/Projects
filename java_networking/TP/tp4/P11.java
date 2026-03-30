import java.net.*;
import java.io.*;
import java.util.Scanner;

public class P11 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("P1: Entrez votre chaîne: ");
        String chaine = sc.nextLine();

        DatagramSocket udpSocket = new DatagramSocket();
        InetAddress p2Address = InetAddress.getByName("10.127.89.161");
        byte[] buffer = chaine.getBytes();
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, p2Address, 8000);
        udpSocket.send(packet);
        udpSocket.close();
        System.out.println("P1: Message envoyé à P2 via UDP.");

        ServerSocket server = new ServerSocket(6000);
        Socket socket = server.accept();
        ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
        String result = (String) ois.readObject();
        System.out.println("P1: Message final reçu de P4: " + result);

        ois.close();
        socket.close();
        server.close();
        sc.close();
    }
}
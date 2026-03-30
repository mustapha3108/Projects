import java.net.*;
import java.io.*;
import java.util.Scanner;

public class P1 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        // Saisie de P1
        System.out.print("P1: Entrez votre chaîne: ");
        String chaine = sc.nextLine();

        // Envoyer à P2 via UDP
        DatagramSocket udpSocket = new DatagramSocket();
        InetAddress p2Address = InetAddress.getByName("10.127.89.161"); // IP de P2
        byte[] buffer = chaine.getBytes();
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, p2Address, 5000);
        udpSocket.send(packet);
        udpSocket.close();
        System.out.println("P1: Message envoyé à P2 via UDP.");

        // Recevoir message final de P4 via TCP
        ServerSocket server = new ServerSocket(6000); // Port TCP pour recevoir P4
        Socket socket = server.accept();
        Object in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String result = in.readLine();
        System.out.println("P1: Message final reçu de P4: " + result);

        socket.close();
        server.close();
        sc.close();
    }
}

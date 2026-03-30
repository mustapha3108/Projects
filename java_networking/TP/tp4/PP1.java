package tp4;

import java.net.*;
import java.io.*;

public class PP1 {
    public static void main(String[] args) {
        try {
            String message = "RSD";
            InetAddress ip = InetAddress.getByName("10.172.99.23");

            // --- SEND via UDP ---
            DatagramSocket udpSocket = new DatagramSocket();
            byte[] sendData = message.getBytes();
            DatagramPacket udpPacket = new DatagramPacket(sendData, sendData.length, ip, 9876);
            udpSocket.send(udpPacket);
            System.out.println("Sent via UDP: " + message + " to " + ip);
            udpSocket.close();

            // --- RECEIVE via TCP ---
            ServerSocket serverSocket = new ServerSocket(9877); // TCP port to listen on
            System.out.println("Waiting for TCP connection on port 9877...");
            Socket tcpSocket = serverSocket.accept(); // blocks until connection received

            BufferedReader in = new BufferedReader(
                new InputStreamReader(tcpSocket.getInputStream())
            );

            String received = in.readLine();
            System.out.println("Received via TCP: " + received
                + " From: " + tcpSocket.getInetAddress()
                + " Port: " + tcpSocket.getPort());

            in.close();
            tcpSocket.close();
            serverSocket.close();

        } catch (Exception e) {
            System.out.println("Exception: " + e.toString());
        }
    }
}
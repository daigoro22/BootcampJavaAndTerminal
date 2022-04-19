import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Main {

  static Socket socket = null;
 public static void main(String[] args) {
  Server server = new Server();
  server.start();

  Sender sender = new Sender();
  sender.start();
 }
}

class Server extends Thread {
 public void run(){
  ServerSocket sSocket = null;
  BufferedReader reader = null;
  PrintWriter writer = null;

  try{
   sSocket = new ServerSocket("",8190);

   System.out.println("サーバー側開始です");

   Main.socket = sSocket.accept();
   reader = new BufferedReader(new InputStreamReader(Main.socket.getInputStream()));

   String line;

   while (true) {
    line = reader.readLine();

    if (line.equals("bye")) {
     break;
    }
    System.out.println(line);
   }
  }catch(Exception e){
   e.printStackTrace();
  }finally{
   try{
    if (reader!=null){
     reader.close();
    }
    if (Main.socket!=null){
     Main.socket.close();
    }
    if (sSocket!=null){
sSocket.close();
    }
    System.out.println("サーバー側終了です");
   } catch (IOException e) {
    e.printStackTrace();
   }
  }
 }
}

class Sender extends Thread {
 public void run(){
  PrintWriter writer = null;

  try{

   Scanner sc = new Scanner(System.in);

   String str = sc.nextLine();

   writer = new PrintWriter(Main.socket.getOutputStream(), true);

   while (true) {
    writer.println(str);
   }
  }catch(Exception e){
   e.printStackTrace();
  }finally{
   try{
    if (writer != null) {
     writer.close();
    }
    if (Main.socket != null) {
     Main.socket.close();
    }
   } catch (IOException e) {
    e.printStackTrace();
   }
  }
 }
}

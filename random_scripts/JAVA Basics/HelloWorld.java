//linked lists, simple threds thing

import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.Timer;
import java.util.TimerTask;
import java.util.HashMap;

import crow.*;

//TODO : RECORDS, INSTANCE OF


public class HelloWorld {
 int global = 50;
 public static void main(String[] args) {
     /*
     logic stuff: (and &&) (or ||) (not!) 
     int crow = 50;
     String yay = "winter is coming"; 
     final int o = 50 that is constant
      int cowvar = (string.empty()) ? 50 : 60 

     String[] foods = {"burger", "pizza", "chicken"}, String[] foods = new String[3]
     foods[1] = "marguerita";
      fruits.length, Arrays.sort(fruits) for  
      Arraylits are dynamic but don't work with primitives , so Integer instead of int
      ArrayList<String> names = new ArrayList<>(), ArrayList<String> names = new ArrayList<>(Arrays.asList("Crow", "Raven", "Magpie"))
         names.add("Crow"), names.add(0, "raven") names.get(0), names.size(), set(), contains(), remove(), 
         names.foreach( name ->{ stuff; stuff; }); traditional for : works too
         ArrayList<ArrayList<Integer>> 

     okay java shinanigans stime, so data types are either primitive like int float double or objects (wrapper class) like String
      basically all you have to do is spell it out so Integer w = 25;, Double Character 
      also the reverse process is simply int q = w
      it is useful because there are built in methods like Integer.toString(50) and Integer.parseInt("50"), isLetter, isUppercase....chatgpt work

     Scanner huss = new Scanner(System.in);
      System.out.print("just type anything: ");
      String whatevs = huss.nextLine(); also nextDouble(), nextInt(), nextBoolean()
      huss.nextLine(); this is because if you put a string input after number intupt java just freaks out 

     Random zigzag = new Random();
      double zig = zigzag.nextDouble(1, 100);
      System.out.printf("the random number is %.3f \n", zig); 

     Math.PI, Math.abs(), Math.pow(5,2) = 25, Math.sqrt(),
      Math.ceil(), Math.floor(), Math.max(), Math.min() 

     string.length(), string.empty(), string.charAt(3), string.indexOf("k"), string.lastIndexOf("l"), string.contains("s"),
      string.toUpperCase(), string.toLowerCase(), string.trim(), string.replace("l", "k"), name.equals("josh"), string.equals(name),
      string.equalsIgnoreCase(name),
      string.substring(0,6)--inclusive-exvlusive-- or string.substring(6) = 6 to the end, 
      also the string doesn't have to be a variable it can be just "word".whatever method
       
     switch statements 
      1.c style
      int x = 5;
      string rr;
      switch (x) {
         case 1:
             int y = 6;
             some loop
             some condition
             some whatever
             rr = whatever;
             break;
         case 3:
         case 2:
             int y = 6;
             some loop
             some condition
             some whatever
             rr = whatever;
             break;
         default:
             rr = "no"
             break;
         } 
      2.enhaced switches
      int x = 5;
      string rr = switch(x){
         case 1, 2, 3 -> {
             int y = 90;
             some loop
             some condition
             some whatever
             yield whatever
         } // if only 1 operation you can ommit the {}
         case 6, 8, 10 -> {
             int y = 80;
             some loop
             some condition
             some whatever
             yield whatever
         } 
         default -> {
             int y = 800;
             some loop
             some condition
             some whatever
             yield whatever
         } 
      }; the (;) is here because it is a variable declaration, you can have these switches without declaration of variables
     
     while and for are just like in c, php and javascript also foreach: for (int num : numbers) {} where numbers is an array
      break and continue on loops, stop and skip basically 
     double res = firstfun(15.6, 26.8, "yo");
      System.out.printf("the firstfun result is: %.2f \n", res); 

     try {
     }
     catch(Exception e){
     }

     there are extensive and i mean extensive ways to get the date and time, but that's chatgpt stuff i ain't learning that
     */ 
     people person = new people("jhon doe", "missing");
     System.out.println(person.work());
     System.out.println(person.job); 
     people carl = new people("carl", "zombie hunting");
     System.out.println(carl.name + " does " + carl.job + " for a living" + " also " + carl.health); 
     ArrayList<people> clar = new ArrayList<>(Arrays.asList(person, carl));
     for(people cl : clar){
        System.out.println(cl.name);
     } 
     ElitePeople jhonCena = new ElitePeople("jhon cena", "wrestler");
     System.out.println(jhonCena.name + " is a goat " + jhonCena.job);
     System.out.println(jhonCena.work());

    //you can also override a method for one object only rather than a whole class, can't use private stuff though
     people hitler = new people("adolf hiter", "genocidal hero"){
        @Override
        public String work(){
            return name + " is a " + job + " i like him a little too much";
        }
     };

     System.out.println(hitler.work());

     ArrayList<Integer> dtest = new ArrayList<>();
     int dtesti = 20;
     int dtesti2 = 50;
     dtest.add(dtesti);
     dtest.add(dtesti2);
     for(int t : dtest){
        System.out.println(t);
     }
    //files, they must be in try catch cuz java, the true is there to not overwite when opening
    //keep in mind other way exists for specific needs, this is just the most generic
     try{
        FileWriter ihatefiles = new FileWriter("javatest.txt", true);
        ihatefiles.write("yo java is actually sick man ");
        ihatefiles.close();
        System.out.println("Success");
     } catch(Exception e){
        System.out.println("i really hate files");
     }

    //reading files line by line
     try {
         BufferedReader read = new BufferedReader(new FileReader("javatest.txt"));
         String line;
         while ((line = read.readLine()) != null) {
             System.out.println(line);
         }
         read.close();
      } catch (Exception e) {
         System.out.println("i really hate reading files");
      }
    System.out.println("-----------------------------------------------------");

    //reading files one charachter at a time , note: also posiible to do with BufferedRaeder
    try{
     FileReader fr = new FileReader("javatest.txt");
     int ch;
     while ((ch = fr.read()) != -1) {
         System.out.print((char) ch);
     }
     System.out.println();
     fr.close();
    } catch(Exception e){
         System.out.println("i really hate reading files one character at a time");
    }
    
    //also this exists
     String longparagraph = """ 
      sigbiugnvfdsngdfsgndfogn,
      hdgihjn,bogib
      hgdocccccccccccccccccf 
      """;
    System.out.println("-------------------------------------------------------------------");
    
    //timers and scheulers i guess
    Timer timer = new Timer();
    TimerTask dostuff = new TimerTask(){
        int stop = 5;
        @Override
        public void run(){
            System.out.println("i gotta get a better IDE");
            stop--;
            if(stop == 0){
                timer.cancel();
            }
        }
    };
    timer.schedule(dostuff, 1000, 500);//1000 is starting point, 500 is periodic, if only two args then only once.
    //this is just generics, like typescript
    General<String, Integer> go = new General<>("crow", 1000);
    go.display();
    //random though expirement
    int cc = 50; double bb = 25.3; System.out.println(cc+bb);

    //hashmap!! keys are unique so no two black man, duplicates are basically overwriting the value
    HashMap<String, Double> mymap = new HashMap<>();
    mymap.put("black man", 0.99);
    mymap.put("sandales", 99.9);
    mymap.put("asian courtisan", 15.6);
    System.out.println(mymap);
    mymap.remove("sandales");
    System.out.println(mymap);
    System.out.println(mymap.get("black man") + " and also for checking " + mymap.containsKey("asian courtisan") + " and for values " + mymap.containsValue(5.0));
    System.out.println("my map is this long " + mymap.size());
    //also works with for loops!!!!! what a shocker everyone
    for(String key : mymap.keySet()){
        System.out.println(mymap.get(key));
    }

    //i am supposed to learn enums now, but they creep me out
    //okay now for threads, you need a runnable class and the runnable and thread objects
/*
    Threading runthesucka = new Threading();
    Thread thread  = new Thread(runthesucka);
    thread.setDaemon(true); //this is so the thread closes when the main thread does
    thread.start();//this is to start the thread, mind blown
    //thread.sleep(), thread.join();*/


    //chatgpt excercise

    ArrayList<Integer> list = new ArrayList<>(Arrays.asList(5,96,2,3,6,4,7,5,98,5,5,8,4,2,54,9,12,178,6,9,2,78,8,3));
    ArrayList<Integer> result = new ArrayList<>();
    int k = 3;
    int big;
    System.out.println(list.size());

    for(int i = 0; i < list.size(); i++){
        if(exists(list, i+k-1)){
            big = list.get(i);
            for(int j = i; j <= i+k-1; j++){
                if(list.get(j)>big){
                    big = list.get(j);
                }
            }
            result.add(big);
        }
    }
    System.out.println(result);
    }

    static boolean exists(ArrayList<Integer> list, int index){
        if(index < list.size()){
            return true;
        }else{
            return false;
        }
    }

//you can have two functions with the same name in java as long as the args are different
//however no same name different data types
    static double firstfun(double x, double y){
        double z;
        z=x*y/25;
        return z*8;
    }
    static double firstfun(double x, double y, double a){
        double z;
        z=x*y/25;
        return z*8 + a;
    }
    static double firstfun(double x, double y, String a){
        double z;
        z=x*y/25;
        return z*8;
    }
//infinite args
//can do sum(String yoyo, double... numbers) or sum(double[] numbers, String[] strv) but no 2 infnite args with dot format
    static double sum(double... numbers){
        double sum = 0;
        for(double number : numbers){
            sum+=number;
        }
        return sum;
    }
}
package crow;

public class people {

 //can't find a tutorial here but i tested it and these are the default values
 public String name;
 public String job = "building";
 public String health = "depressed";

 public people(String name, String job){
     this.name = name;
     this.job = job;
 }
    
 private String secret(){
     return " too much";
 }

 public String work(){
     return name + " likes " + job + secret();
 }
}

/*
 okay so, sweet old classes
 public: access everywhere
 protected: subclasses and package
 nothing: package
 private: only by the class, so you can only call it inside its own class

 package is basically folder, kinda like it

 static: the mighty communism, which means every object (instance of a class) share it, when you don't want a variable to be unique to each object
  also preferrably called by the name of the og class, in this case people.
 
 there is a whole tostring method thing that can be overwritten so all the variables output instead of the memory hash thing, can't be bothered to learn it

 abstract: an abstract class basically means the class it self can't be called or used to create objects but its children can
  there is also abstract functions wich are functions that need to be overwritten like the compiler will force you to
  concrete methods in this context are just normal methods
  public abstract class
 
  IMPORTANT: if you wanna have an array of children, the data type will be the parent class, and that is called polymorphism, easy conecpt with mean sounding name
   works with interfaces too so the parent interface
   obciously a variable of the type parent can have values of the type child like people naruto = new ElitePeople();
   this works best withy interfaces and abstract classes, as some data of the child class can be ignored or lost otherwise

 okay now this is pretty important, INTERFACES: very similar to abstract, they are not a class, they define methods that children need to define, also stackable
  gotta write an example:

  public interface building {
    void clean(double time);
    string open(int hour, string crew);
  }
  public interface land {
    int buy();
    double sell();
  }

  public class house implements building, land {
   //gotta have both all four methods
   @override
   voide clean(double time){
   }
   .
   .
   .
   .

  }

 IMPORTANT: keep in mind that vall kinda of shnanigans can be used because classes are literally data types,
  so you can have a variable of a class inside another class even if it's not defined inside it, it's called agregation
  composition on the other hand is when you call the constructor of another class inside the constructor of the class
  confusing as shit i know, just keep in mind that you can call whatever you want whenerever you want most of the time car.engine.type

  AND WITH THAT I THINK OOP IS OVER NEGGAS


*/
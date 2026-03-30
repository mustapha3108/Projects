package crow;

public class ElitePeople extends people{

 public ElitePeople(String na, String jo){
//note to self, java inserts empty super(), so if you have an empty args constructor in the parent class you can define the constructor normally here
//however if you don't just use it this way
     super(na, jo);
    }
 @Override //that is not necessary btw, when overriding a method, you can't override the data type
 //also for some complicated reason you an return class types as in make a class inside a a class and return it as a adata type, yeah you can do that
 //you can also return a subclass without the data type issue thing, weird huh?
 public String work(){
    return "overridden";
 }
}
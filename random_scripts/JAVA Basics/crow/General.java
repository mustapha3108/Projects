package crow;
public class General <T,U> {
    T fp;
    U sp;
    public General(T fp, U sp){
        this.fp = fp;
        this.sp = sp;
    }
    public void display(){
        System.out.println("so the class holds: " + fp + " and " + sp);
    }
}
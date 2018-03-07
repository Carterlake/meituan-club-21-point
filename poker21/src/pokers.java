import java.util.Scanner;

public class pokers {
    Scanner in = new Scanner(System.in);
     public String number;
     public String color;
     public boolean exist = true ;

     public void pokers(String n, String c){
        number = n;
        color = c;
     }
    public String getNumber(){
         return number;
    }
    public String getColor(){ return color; }


}

import java.util.Scanner;  
import java.lang.Math;  
public class Main {  
    public static void main(String[] args) {  
        Scanner sc =new Scanner(System.in);  
        double x1,x2,y1,y2;  
        x1=sc.nextDouble();  
        y1=sc.nextDouble();  
        x2=sc.nextDouble();  
        y2=sc.nextDouble();  
        System.out.println(Math.pow((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1),0.5));  
    }  
}
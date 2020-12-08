import java.util.Scanner;
import java.lang.Math;
//寫得最不舒服的一次-20-12-9
class Triangle extends GeometricObject{
    Scanner sc;
    protected int numberOfSide=3;
    protected double[] side=new double[3];
    protected String color;
    protected Boolean draw;
    Triangle(){
        sc=new Scanner(System.in);
    }
    void inputData(){
        for(int i=0;i<numberOfSide;i++){
            this.side[i]=sc.nextDouble();
        }
        this.color=sc.next();
        this.draw=sc.nextBoolean();
    }
    double makePerimeter(){
        double ans=0;
        for(int i=0;i<numberOfSide;i++){
            ans+=side[i];
        }
       return ans;
    }
    double makeArea() {
        double s=this.perimeter/2;
        double ans=s;
        for(int i=0;i<numberOfSide;i++){
            ans*=(s-this.side[i]);
        }
        ans=Math.sqrt(ans);
        return ans;
    }
    void showPerimeter(){
        System.out.println("The perimeter is "+this.perimeter);
    }
    void showArea(){
        System.out.println("The area is "+this.area);
    }
    void showSide(){
        System.out.print("Triangle:");
        for(int i=0;i<3;i++){
            System.out.print(" side"+(int)(i+1)+" = "+this.side[i]);
        }
            System.out.println("");
    }
    void showColor(){
        System.out.println(this.color);
    }
    void showDraw(){
        System.out.println(draw);
    }
}
abstract class GeometricObject{
    protected double perimeter;
    protected double area;
    void makeAnser(){
        this.perimeter=makePerimeter();
        this.area=makeArea();
    }
    void showall(){
        showSide();
        showArea();
        showPerimeter();
        showColor();
        showDraw();
    }
    abstract void inputData();
    abstract double makePerimeter();
    abstract double makeArea();
    abstract void showPerimeter();
    abstract void showArea();
    abstract void showSide();
    abstract void showColor();
    abstract void showDraw();
}

public class Main {
    public static void main(String[] args) {
        Triangle tri=new Triangle();
        tri.inputData();
        tri.makeAnser();
        tri.showall();
    }
}

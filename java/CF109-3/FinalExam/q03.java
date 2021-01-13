import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Pointclass implements Comparable<Pointclass>{
    Point2D obj;
    static Point2D point0=new Point2D.Double(0,0);
    Pointclass(double x,double y){
        obj=new Point2D.Double(x,y);
    }
    @Override
    public int compareTo(Pointclass other) {
        double ThisD=Math.abs(this.obj.getX())+Math.abs(this.obj.getY());
        double OtherD=Math.abs(other.obj.getX())+Math.abs(other.obj.getY());
        double pointD=ThisD-OtherD;

        if(pointD==0){
            if(this.obj.getX()>other.obj.getX()){
                return 1;
            }else if(this.obj.getX()<other.obj.getX()){
                return -1;
            }else if(this.obj.getY()>other.obj.getY()){
                return 1;
            }else if(this.obj.getY()<other.obj.getY()){
                return -1;
            }else if(this.obj.getX()==other.obj.getX()&&this.obj.getY()==other.obj.getY()){
                return 0;
            }else{
                return -1;
            }
        }else if(pointD>0){
            return 1;
        }else{
            return -1;
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int time,done=0;
        while (sc.hasNext()){
            if(done==0){
                done++;
            }else{
                System.out.println("");
            }
            time=sc.nextInt();
            List<Pointclass> pointclassList=new ArrayList<>();
            for(int timeCount=0;timeCount<time;timeCount++){
                pointclassList.add(new Pointclass(sc.nextDouble(),sc.nextDouble()));
            }
            Collections.sort(pointclassList);
            for(Pointclass pointclass:pointclassList){
                System.out.printf("(%.0f,%.0f)\n",pointclass.obj.getX(),pointclass.obj.getY());
            }
            Pointclass last=pointclassList.get(time-1);
            System.out.printf(
                    "max num: %.0f\npoint:(%.0f,%.0f)\n",
                    last.obj.getX()+last.obj.getY(),last.obj.getX(),last.obj.getY());
        }
    }
}

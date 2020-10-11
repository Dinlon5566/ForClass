import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int max=-1,time=0,prs;
        while(sc.hasNextInt()){
            prs=sc.nextInt();
            if(prs>max){
                max=prs;
                time=1;
            }else if(prs==max){
                time++;
            }
        }
        System.out.printf("%d %d\n",max,time);
    }
}
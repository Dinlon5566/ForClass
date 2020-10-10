import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num=sc.nextInt();
        for(int i=1;i<=num;i++){
            for(int j=num-i;j>0;j--){
                System.out.print(" ");
            }
            for(int j=i*2-1;j>0;j--){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
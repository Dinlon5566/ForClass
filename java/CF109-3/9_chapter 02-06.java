import java.util.Scanner;  
public class Main {  
    public static void main(String[] args) {  
        Scanner sc=new Scanner(System.in);  
        int num=sc.nextInt();  
        int ans=1;  
        while(num!=0){  
            ans*=num%10;  
            num/=10;  
        }  
        System.out.println(ans);  
    }  
}
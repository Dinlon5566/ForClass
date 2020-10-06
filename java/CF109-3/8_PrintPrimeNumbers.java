import java.util.Scanner;  
public class Main {  
    public static void main(String[] args) {  
        Scanner sc=new Scanner(System.in);  
        int innum=sc.nextInt();  
        int flag,outtime=0;  
        for(int i=2;i<innum;i++){  
            flag=0;  
            for(int j=2;j<i;j++){  
                if(i%j==0){  
                    flag=1;  
                    continue;  
                }  
            }  
            if(flag==0){  
                System.out.print(i);  
                outtime++;  
                if(outtime%10==0){  
                    System.out.print("\n");  
                }else{  
                    if(i!=521){  
                    System.out.print(" ");  
                    }else{  
                        System.out.print("\n");  
                    }  
                }  
            }  
        }  
    }  
}  
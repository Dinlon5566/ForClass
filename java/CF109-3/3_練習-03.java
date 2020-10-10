import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        int num=sc.nextInt();
        int ans=2,re=0;
        while(ans<num){
            if(ans==2){
                System.out.print("2");
                re=1;
                ans++;
                continue;
            }
            for(int i=2;i<ans;i++){
                if(ans%i==0){
                    ans++;
                    break;
                }else if(i==ans-1){
                    if(re!=0){
                        System.out.print(" ");
                    }
                    re=1;
                    System.out.print(ans);
                    ans++;
                    break;
                }
            }
        }
        System.out.print("\n");
    }
}

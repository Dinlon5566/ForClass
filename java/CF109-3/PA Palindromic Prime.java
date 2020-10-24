import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);


        while(sc.hasNext()){
            int time=sc.nextInt();
            if(time==0){
                System.out.printf("\n");
            }
            int flag,outtime=0;
            while(time!=0){
                for(int i=2;time!=0;i++){
                    flag=0;
                    for(int j=2;j<i;j++){
                        if(i%j==0){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        int num=i;
                        int num1;
                        //retext find Start
                        if(num<10){
                            System.out.printf("%d",num);
                            outtime++;
                            time--;
                            if(time!=0){
                                System.out.printf(" ");
                            }else{
                                outtime=0;
                                System.out.println("");
                            }
                        }else{
                            int len=0;
                            num1=num;
                            while(num1!=0){
                                len++;
                                num1/=10;
                            }
                            num1=num;
                            String str=""+num;
                            //System.out.printf("\nD%d\n",outtime);
                            for(int s=0;s<len/2;s++){
                                if(str.charAt(s)!=str.charAt(len-s-1)){
                                    flag=1;
                                }
                            }
                            if(flag==0){
                                System.out.printf("%d",num);
                                outtime++;
                                time--;

                                if(time!=0){
                                    if(outtime%10!=0){
                                        System.out.printf(" ");
                                    }else{
                                        System.out.printf("\n");
                                    }
                                }else{
                                    outtime=0;
                                    System.out.println("");
                                }
                            }
                        }
                        //retext find END

                    }
                }
            }
        }
    }
}

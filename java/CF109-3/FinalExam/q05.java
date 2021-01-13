import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str;
        double ans;
        int done=0;
        double[] num=new double[3];
        String[] strarr=new String[3];
        String[] strbrr;
        String strbbb;
        while (sc.hasNext()){
            if(done==0){
                done++;
            }else{
                System.out.println("");
            }
            strbbb="";
            str=sc.nextLine();
            ans=0;
            strarr=str.split(" \\+ | - | \\* | / ");
            strbrr=str.split("0|1|2|3|4|5|6|7|8|9| ");
            for(int i=0;i<3;i++){
                num[i]=Double.parseDouble(strarr[i]);
            }
            for(String s:strbrr){
                if(s.length()!=0){
                    strbbb+=s;
                }
            }
            System.out.printf("%.0f",num[0]);
            for(int i=1;i<3;i++){
                System.out.printf(" %.0f",num[i]);
            }
            for(int i=0;i<2;i++){
                System.out.printf(" %c",strbbb.charAt(i));
            }
            if(strbbb.charAt(0)=='*'||strbbb.charAt(0)=='/'){
                if(strbbb.charAt(0)=='*'){
                    ans=num[0]*num[1];
                }else{
                    ans=num[0]/num[1];
                }

                if(strbbb.charAt(1)=='+'){
                    ans+=num[2];
                }else if(strbbb.charAt(1)=='-'){
                    ans-=num[2];
                }else if(strbbb.charAt(1)=='*'){
                    ans*=num[2];
                }else if(strbbb.charAt(1)=='/'){
                    ans/=num[2];
                }
            }else if(strbbb.charAt(1)=='*'||strbbb.charAt(1)=='/'){
                if(strbbb.charAt(1)=='*'){
                    ans=num[2]*num[1];
                }else{
                    ans=num[1]/num[2];
                }

                if(strbbb.charAt(0)=='+'){
                    ans+=num[0];
                }else if(strbbb.charAt(0)=='-'){
                    ans=num[0]-ans;
                }else if(strbbb.charAt(0)=='*'){
                    ans*=num[0];
                }else if(strbbb.charAt(0)=='/'){
                    ans=num[0]/ans;
                }

            }else{

                if(strbbb.charAt(0)=='+'){
                    ans=num[0]+num[1];
                }else if(strbbb.charAt(0)=='-'){
                    ans=num[0]-num[1];
                }else if(strbbb.charAt(0)=='*'){
                    ans=num[0]*num[1];
                }else if(strbbb.charAt(0)=='/'){
                    ans=num[0]/num[1];
                }

                if(strbbb.charAt(1)=='+'){
                    ans+=num[2];
                }else if(strbbb.charAt(1)=='-'){
                    ans=ans-num[2];
                }else if(strbbb.charAt(1)=='*'){
                    ans*=num[2];
                }else if(strbbb.charAt(1)=='/'){
                    ans=ans/num[2];
                }
            }
            System.out.printf("\n%c%.2f\n",ans>=0?'+':'-',Math.abs(ans));
        }
    }
}

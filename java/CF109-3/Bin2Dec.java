/**
 * Coding by Dinlon5566 - https://github.com/Dinlon5566
 * Complete at 01/03/2021.
**/
import java.util.Scanner;

class MyNumberFormatException extends Exception{

    private String ExceptionMsg;    //to save the Expection message


    MyNumberFormatException(String ExceptionMsg){
        this.ExceptionMsg=ExceptionMsg;
    }

    public String Getmsg(){         //Here should use "public"
        return ExceptionMsg;
    }

}

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);

        //Data here
        String str; //For get newline
        int strlen; //The str length
        int level;  //count level of calculation time
        int ans;    //to get sum of every time calculation

        while (sc.hasNext()){

            level=1;
            ans=0;
            str=sc.nextLine();
            strlen=str.length();
            try{

                for(int now=strlen-1;now>=0;now--){
                    if(str.charAt(now)=='1'){
                        ans+=level;
                    }else if(str.charAt(now)!='0'){
                        throw new MyNumberFormatException("Incorrect Binary Format");
                    }
                    level*=2;
                }
                System.out.println(ans);

            }catch (MyNumberFormatException es){
                System.out.println(es.Getmsg());
            }

        }
    }
}
//Below blank
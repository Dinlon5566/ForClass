import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        String maininput = sc.nextLine();
        String[] spnum = maininput.split("0|1|2|3|4|5|6|7|8|9|\\.");
        String[] nunum = maininput.split("\\*|-|\\+|/|%|\\(|\\)");
        String splist ="";
        String[] nulist=new String[255];
        int numtime=0;
        double ans=0;

        for(String a:spnum){
            if(a.length()>0){
                splist+=a;
            }
        }

        for(String a:nunum){
            if(a.length()>0){
                nulist[numtime]=a;
                ans+=Double.parseDouble(a);
                numtime++;
            }
        }

        for(int i=0;i<numtime;i++) {
            if(i!=numtime-1){
                System.out.printf("%s ",nulist[i]);
            }else{
                System.out.printf("%s\n", nulist[i]);
            }
        }

        for(int i=0;i<splist.length();i++) {
            if(i!=splist.length()-1){
                System.out.printf("%c ", splist.charAt(i));
            }else{
                System.out.printf("%c\n", splist.charAt(i));
            }
        }

        System.out.printf("%.3f\n",ans);
    }
}

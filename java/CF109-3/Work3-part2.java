import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        Scanner sc=new Scanner(System.in);
        String maininput = sc.nextLine();
        String[] spnum = maininput.split("0|1|2|3|4|5|6|7|8|9|\\.");
        String[] nunum = maininput.split("\\*|-|\\+|/|%|\\(|\\)");
        String splist ="";              //用來記錄符號
        String[] nulist=new String[255];//數字儲存串
        int numtime=0;                  //數字次數

        String combine="";
        int combine_record=0;
        for(int i=0;i<maininput.length();i++){
            String temp="";
            temp+=maininput.charAt(i);
            if("*+/-()%".contains(temp)){
                combine_record=0;
                combine+="1";
            }else{
                if(combine_record==0){
                    combine+="0";
                    combine_record=1;
                }
            }
        }

        for(String a:spnum){
            if(a.length()>0){
                splist+=a;
            }
        }

        for(String a:nunum){
            if(a.length()>0){
                nulist[numtime]=a;
                numtime++;
            }
        }
        /**
         //此處為輸出數字與符號處
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
         **/
        //製作後續式
        //combine : 0為數字 1為符號
        Stack<Character> spstk=new Stack<Character>();
        Stack<Integer> weight=new Stack<Integer>();
        String anser="";
        int nownum,nowsp;
        nownum=nowsp=0;
        for(int now=0;now<combine.length();now++){
            if(combine.charAt(now)=='1'){
                if(splist.charAt(nowsp)=='('){
                    spstk.push(splist.charAt(nowsp));
                    weight.push(-1);
                }
                if(splist.charAt(nowsp)==')'){
                    while(spstk.peek()!='('){
                        anser+=spstk.pop();
                        weight.pop();
                        anser+=" ";
                    }
                    spstk.pop();
                    weight.pop();
                }

                if(splist.charAt(nowsp)=='+'||splist.charAt(nowsp)=='-'){
                    while (weight.empty()==false&&weight.peek()>=5){
                        anser+=spstk.pop();
                        weight.pop();
                        anser+=" ";
                    }
                    weight.push(5);
                    spstk.push(splist.charAt(nowsp));
                }
                if(splist.charAt(nowsp)=='*'||splist.charAt(nowsp)=='/'||splist.charAt(nowsp)=='%'){
                    while (weight.empty()==false&&weight.peek()>=9){
                        anser+=spstk.pop();
                        weight.pop();
                        anser+=" ";
                    }
                    weight.push(9);
                    spstk.push(splist.charAt(nowsp));
                }

                nowsp++;

            }else {
                anser+=nulist[nownum];
                anser+=" ";
                nownum++;
            }

        }
        while (spstk.empty()==false){
            anser+=spstk.pop();
            anser+=" ";
        }
        System.out.println(anser);
    }
}

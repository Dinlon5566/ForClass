import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str;
        int numa,numb,ans;
        while(sc.hasNext()){
            numa=numb=ans=0;
            str = "";
            str=sc.nextLine();
            if(str.charAt(0)=='0' && str.length()==1){
                break;
            }
            for(int i=0;i<str.length();i++){
                if(i%2==0){
                    numa+=(int)(str.charAt(i)-'0');
                }else{
                    numb+=(int)(str.charAt(i)-'0');
                }
            }
            System.out.printf("%d %d\n",numa,numb);
            numa-=numb;
            numa=Math.abs(numa);
            if(numa%11==0){
                System.out.printf("%s : Yes\n",str);
            }else{
                System.out.printf("%s : No\n",str);
            }
        }
    }
}

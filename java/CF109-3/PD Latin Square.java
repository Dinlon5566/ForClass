import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int puttime=0;
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext()){
            String lenstr=sc.nextLine();
            while (lenstr.length()==0){
                lenstr=sc.nextLine();
            }
            int len=Integer.valueOf(lenstr);
            if(len==-1){
                break;
            }
            if(puttime==0){
                puttime=1;
            }else{
                System.out.println("");
            }
            char[][] map= new char[len][len];
            for(int i=0;i<len;i++){
                String str=sc.nextLine();
                int k=0;
                for(int j=0;j<str.length();j+=2){
                    map[i][k]=str.charAt(j);
                    k++;
                }
            }
//map get!
            int flag=0;
            char head;
            String data="";
            for(int i=0;i<len;i++){
                for(int j=0;j<len-1;j++){
                    head=map[i][j];
                    for(int k=j+1;k<len;k++){
                        //find retext
                        int cat=0;
                        for(int s=0;s<data.length();s++){
                            if(data.charAt(s)==head){
                                cat=1;
                            }
                        }
                        if(cat==0){
                            data+=head;
                            if (data.length()>len){
                                flag=1;
                            }
                        }

                        if(map[i][k]==head){
                            flag=1;
                        }
                    }
                }
            }
            if(flag==0){
                for(int i=0;i<len;i++){
                    for(int j=0;j<len-1;j++){
                        head=map[j][i];
                        for(int k=j+1;k<len;k++){
                            if(map[k][i]==head){
                                flag=1;
                            }
                        }
                    }
                }
            }
            if(flag==0){
                System.out.printf("The input array is a Latin square\n");
            }else{
                System.out.printf("The input array is not a Latin square\n");
            }
        }
    }
}

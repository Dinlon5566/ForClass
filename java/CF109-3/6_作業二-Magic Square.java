import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num,re=0;
        while(sc.hasNextInt()){
            if(re!=0){
                System.out.println();
            }
            re++;
            num=sc.nextInt();
            int[][] ormap = new int[num][num];
            if(num%2==0){
                System.out.println("It is not an odd number.");
                continue;
            }
            int i=0,j=num/2,min=num,renum=0,rekey=0;
            for(int key=num*num;key>0;){
                if(ormap[i][j]<min){
                    renum=ormap[i][j]=key;
                    rekey=0;
                    key--;
                }else if(renum==ormap[i][j]){
                    rekey++;
                }if(rekey==2){
                    if(i==num-1){
                        i=0;
                    }else{
                        i++;
                    }
                }else{
                    if(i==0){
                        i=num-1;
                    }else{
                        i--;
                    }
                    if(j==0){
                        j=num-1;
                    }else{
                        j--;
                    }
                }
            }
            min=0;
            for(int ii=0;ii<num;ii++){
                min+=ormap[ii][0];
            }
            System.out.println(min);
            for(int ii=0;ii<num;ii++){
                for(int jj=0;jj<num;jj++){
                    System.out.printf("%5d",ormap[ii][jj]);
                }
                System.out.println();
            }
        }
    }
}

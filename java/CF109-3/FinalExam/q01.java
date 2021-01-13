import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int innum,nownum,ans;
        Scanner sc= new Scanner(System.in);
        while (sc.hasNext()){
            innum=sc.nextInt();
            if(innum%2==0){
                System.out.println("It is not an odd number.");
            }else{
                nownum=innum*innum;
                ans=0;
                int[][] map=new int[innum][innum];
                int lon=0,lom=innum/2;
                while (nownum!=0){
                    if(map[lon][lom]==0){
                        map[lon][lom]=nownum;
                        nownum--;
                        lon=lon-1>=0?lon-1:innum-1;
                        lom=lom-1>=0?lom-1:innum-1;
                    }else if(map[lon][lom]==nownum+1){
                        lon=lon+1<innum?lon+1:0;
                    }else{
                        lon=lon-1>=0?lon-1:innum-1;
                        lom=lom-1>=0?lom-1:innum-1;
                    }
                }
                for (int i=0;i<innum;i++){
                    ans+=map[0][i];
                }
                System.out.println(ans);
                for(int i=0;i<innum;i++){
                    for(int j=0;j<innum;j++){
                        System.out.printf("%5d",map[i][j]);
                    }
                    System.out.println("");
                }
            }
            System.out.println("");
        }
    }
}



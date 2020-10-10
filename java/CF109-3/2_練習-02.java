public class Main {
    public static void main(String[] args) {
        for(int x=1,y=1;x<=9;y++){
            System.out.printf("%d * %d = %2d",x,y,x*y);
            if(y<9){
                System.out.printf(" ");
            }else{
                x++;
                y=0;
                System.out.println();
            }
        }
    }
}

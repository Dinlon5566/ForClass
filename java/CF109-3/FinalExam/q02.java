import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int hasNum,done=0;
        while (sc.hasNext()){
            hasNum=sc.nextInt();
            if(done==0){
                done++;
            }else{
                System.out.println("");
            }
            List<Double> arrylist=new ArrayList<>();
            ListIterator listIterator;
            Iterator iterator;
            for(int i=0;i<hasNum;i++){
                arrylist.add(sc.nextDouble());
            }
            Collections.sort(arrylist);
            iterator=arrylist.iterator();
            System.out.printf("%.2f",iterator.next());
            while(iterator.hasNext()){
                System.out.printf(" %.2f",iterator.next());

            }
            Collections.reverse(arrylist);
            listIterator=arrylist.listIterator();
            System.out.println("");
            System.out.printf("%.2f",listIterator.next());
            while (listIterator.hasNext()){
                System.out.printf(" %.2f",listIterator.next());
            }
            System.out.println("");
        }
    }
}

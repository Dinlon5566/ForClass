/**
 * Coding by Dinlon5566 - https://github.com/Dinlon5566
 * Complete at 01/04/2021.
 **/

import java.util.ArrayDeque;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int num;
        Vector<Integer> vector=new Vector<>();
        ArrayDeque<Integer> array=new ArrayDeque<>();
        while (sc.hasNext()){
            num=sc.nextInt();
            if(num!=0){
                vector.add(num);
            }else{
                Collections.sort(vector); //This is sort function
                for(int i:vector){        //Integer "i" form vector[begin]~vector[end]
                    if(i%2==0){
                        array.addLast(i); //it work like its name
                    }else{
                        array.addFirst(i);
                    }
                }
                while (array.size()!=1){
                        System.out.printf("%d ",array.removeFirst());
                }
                System.out.println(array.removeFirst());
                vector.clear();
            }
        }
    }
}
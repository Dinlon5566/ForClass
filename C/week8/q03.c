#include <stdio.h>
#include <stdlib.h>
void honai(int n,int a,int b,int c){
    if(n==1){
        printf("Move disk %d from %d to %d\n",n,a,c);
    }else{
        honai(n-1,a,c,b);
        printf("Move disk %d from %d to %d\n",n,a,c);
        honai(n-1,b,a,c);
    }
}
int main()
{
    int num;
    while(~scanf("%d",&num)){
        honai(num,1,2,3);
        printf("\n");
    }
    return 0;
}

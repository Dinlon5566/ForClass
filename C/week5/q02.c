#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int solution(int a,int b)
{
    int numhas[10]={0};
    int tmp;
    for(int i=0;i<5;i++){
        tmp=a%10;
        a/=10;
        numhas[tmp]++;
    }
    for(int i=5;i<10;i++){
        tmp=b%10;
        b/=10;
        numhas[tmp]++;
    }
    for(int i=0;i<10;i++){
        if(numhas[i]>1){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int num,a,b,flag;

        for(num=1;num<101;num++){


        flag=0;

        for(b=1234; b*num<=98765; b++)
        {
            if(solution(b*num,b))
            {
                printf("%05d = %d * %05d\n",b*num,num,b);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No pair for c = %d.\n",num);
        }
        if(num!=100)puts("");
    }

    return 0;
}

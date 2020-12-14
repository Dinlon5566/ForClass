#include <stdio.h>
#include <stdlib.h>
void fun(int a,int b,int rt[],int c,int pt)
{
    if(b==1)
    {
        for(int i=c; i<a; i++)
        {
            rt[i]=1;
            pt=output(a,rt,pt);
            rt[i]=0;
        }
    }
    else
    {
        for(int i=c; i<a; i++)
        {
            rt[i]=1;
            fun(a,b-1,rt,i+1,pt);
            pt=1;
            rt[i]=0;
        }
    }
}
int output(int a,int rt[],int pt)
{
    if(pt==1){
            printf("\n");
        }
    for(int i=a-1; i>=0; i--)
    {
        if(rt[i]==0)
        {
            printf("0");
        }
        else
        {
            printf("1");
        }
    }
    return 1;
}
int main()
{
    int a,b,time;
    scanf("%d",&time);
    while(time--)
    {
        scanf("%d %d",&a,&b);
        int rt[a];
        for(int i=0; i<a; i++)
        {
            rt[i]=0;
        }
        fun(a,b,rt,0,0);

        if(time!=0){
            printf("\n\n");
        }
    }
    return 0;
}

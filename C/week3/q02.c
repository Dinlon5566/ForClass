#include <stdio.h>

void function(int num,int cunt)
{
    if(num==1)
    {
        printf("Iteration %d: 1\nThe number of iterations is %d.\n\n",cunt,cunt);
        return 0;
    }
    else if(num%2==0)
    {
        printf("Iteration %d: %d\n",cunt,num);
        num/=2;
    }
    else
    {
        printf("Iteration %d: %d\n",cunt,num);
        num=3*num+1;
    }
    function(num,cunt+1);
}

int main()
{
    int time=1,num;
    while(scanf("%d",&num)!=EOF)
    {
        printf("Case %d:\n",time);
        time++;
        function(num,1);
    }
    return 0;
}

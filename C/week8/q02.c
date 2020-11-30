#include <stdio.h>
#include <stdlib.h>
int GCD(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }
}
int LCM(int a,int b){
return a*b/GCD(a,b);
}
int main()
{
    int a,b;
    while(~scanf("%d %d",&a,&b))
    {
        printf("%d %d\n",GCD(a,b),LCM(a,b));
    }
    return 0;
}

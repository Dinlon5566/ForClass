#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,ans,cont;
    while(~scanf("%d",&num))
    {
        cont=4;
        if(num==1)
        {
            ans=1;
        }
        else
        {
            ans=3;
        }
        for(int i=2;i<num;i++){
            ans+=cont;
            i++;
            if(i>=num){
                break;
            }
            ans+=cont;
            cont+=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time,t=0;
    int up,numa,numb;
    scanf("%d",&time);
    while(t++,time--)
    {
        scanf("%d %d %d",&up,&numa,&numb);
        printf("Case %d: %d + %d (base %d)\n",t,numa,numb,up);
        int update=0;
        while(numa!=0||numb!=0||update!=0)
        {
            printf("%d + %d + %d = %d",numa%10,numb%10,update,numa%10+numb%10+update>=up?(numa%10+numb%10+update)-up:numa%10+numb%10+update);
            if(numa%10+numb%10+update>=up)
            {
                update=1;
                puts(" with one carry");
            }
            else
            {
                update=0;
                puts("");
            }
            numa/=10;
            numb/=10;
        }
        puts("");
    }
    return 0;
}

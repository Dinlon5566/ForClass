#include <stdio.h>
int main()
{
    double avg;
    int num[10],time,ans;
    scanf("%d",&time);
    while(time--)
    {
        avg=ans=0;
        for(int i=0; i<10; i++)
        {
            scanf("%d",&num[i]);
            avg+=num[i];
        }
        avg/=10;

        for(int i=0; i<10; i++)
        {
            if(num[i]<avg)
            {
                ans++;
            }
        }
        printf("%d0.00%%\n",ans);
    }
    return 0;
}

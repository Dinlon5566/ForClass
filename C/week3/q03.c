#include <stdio.h>
int main()
{
    int mon,have,chan,ans;
    while(scanf("%d %d %d",&mon,&have,&chan)!=EOF)
    {
        ans=0;
        have=mon/have;
        ans+=have;
        mon=ans;
        do
        {
            ans+=mon=have/chan;
            have%=chan;
            have+=mon;
        }
        while(have>=chan);
        printf("%d\n",ans);
    }
    return 0;
}

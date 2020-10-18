#include <stdio.h>
#include <stdlib.h>

int main()
{
    int start,jump,time;
    char type;
    while(scanf("%d %d %d %c",&start,&jump,&time,&type)!=EOF)
    {
        while(time--)
        {
            printf("%d",start);
            if(type=='a')
            {
                start+=jump;
            }
            else
            {
                start*=jump;
            }
            if(time!=0)
            {
                printf(", ",start);
            }
            else
            {
                puts("");
            }
        }
    }
    return 0;
}

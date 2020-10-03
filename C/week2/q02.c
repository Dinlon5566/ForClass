#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int num[3];
    while(scanf("%d %d %d",&num[0],&num[1],&num[2])!=EOF)
    {
        for(int j=0; j<3; j++)
        {
            for(int i=0; i<2; i++)
            {
                if(num[i]<num[i+1])
                {
                    swap(&num[i],&num[i+1]);
                }
            }
        }
        if(num[0]*num[0]==num[1]*num[1]+num[2]*num[2])
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}

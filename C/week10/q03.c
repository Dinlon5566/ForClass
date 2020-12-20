#include <stdio.h>
#include <stdlib.h>
int main()
{
    char tmp_n[255];
    int n,m,rn,rm,s,topn,topm,done=0;
    while(~scanf("%s",&tmp_n))
    {
        if(tmp_n[0]=='*')
        {
            break;
        }
        if(done==0)
        {
            done++;
        }
        else
        {
            printf("\n\n");
        }

        n=atoi(tmp_n);
        scanf("%d %d %d %d",&m,&rn,&rm,&s);
        topn=topm=0;
        int arr[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        int tararr[n][m];
        int max;
        for(int i=0; i+rn-1<n; i+=s)
        {
            topm=0;
            for(int j=0; j+rm-1<m; j+=s)
            {
                max=-1;
                for(int ii=i; ii<i+rn; ii++)
                {
                    for(int jj=j; jj<j+rm; jj++)
                    {
                        if(arr[ii][jj]>max)
                        {
                            max=arr[ii][jj];
                        }
                    }
                }
                tararr[topn][topm]=max;
                topm++;
            }
            topn++;
        }
        for(int i=0; i<topn; i++)
        {
            for(int j=0; j<topm; j++)
            {
                printf("%d",tararr[i][j]);
                if(j<topm-1)
                {
                    printf(" ");
                }
            }
            if(i<topn-1)
            {
                printf("\n");
            }
        }
    }
    return 0;
}

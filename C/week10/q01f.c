#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k,done=0;
    char tmp_n[255],tmp_r[255],typ,line;
    while(~scanf("%s",&tmp_n))
    {
        if(tmp_n[0]=='*')
        {
            break;
        }
        if(done==0){
            done++;
        }else{
        printf("\n");
        }
        n=atoi(tmp_n);
        scanf("%d %s",&m,&tmp_r);
        if(tmp_r[0]=='D')
        {
            k=0;
            typ='D';
            scanf(" %c",&line);
        }
        else
        {
            k=atoi(tmp_r);
            scanf(" %c %c",&typ,&line);
        }
        //printf("%d %d %d %c %c\n",n,m,k,typ,line);
        int arr[n*m];
        for(int i=0; i<n*m; i++)
        {
            scanf("%d",&arr[i]);
        }
        if(typ=='D')
        {
            if(line=='R')
            {
                for(int i=0; i<n*m; i++)
                {
                    printf("%d",arr[i]);
                    if(i<n*m-1)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            else
            {
                for(int i=0; i<m; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        printf("%d",arr[i+j*m]);
                        if(j<n-1)
                        {
                            printf(" ");
                        }
                    }
                }
                printf("\n");
            }
        }
        else
        {
            //typ=U
            if(line=='R')
            {

                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        printf("%d",arr[i*m+j]);
                        if(j<m-1)
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            }else{
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        printf("%d",arr[j*n+i]);
                        if(j<m-1)
                        {
                            printf(" ");
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

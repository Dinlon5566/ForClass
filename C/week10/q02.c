#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tmp_n[255];
    int n,m,an,am,bn,bm,done=0;
    while(~scanf("%s",&tmp_n)){
        if(tmp_n[0]=='*'){
            break;
        }
        if(done){
            printf("\n\n");
        }else{
        done++;
        }
        n=atoi(tmp_n);
        scanf("%d %d %d %d %d",&m,&an,&am,&bn,&bm);
        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=an;i<=bn;i++){
            for(int j=am;j<=bm;j++){
                printf("%d",arr[i][j]);
                if(j<bm){
                    printf(" ");
                }
            }
            if(i<=bn-1){
                printf("\n");
            }
        }
    }
    return 0;
}

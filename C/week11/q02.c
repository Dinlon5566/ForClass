#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,done=0,ans;
    while(~scanf("%d",&n)){
        if(n<=0){
            break;
        }
        if(done){
            printf("\n");
        }else{
            done++;
        }
        int map[n][n],onelo[n];
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==1){
                    onelo[i]=j;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                if(map[k][onelo[i]]==1){
                    ans++;
                }
            }
            int a=i+1,b=onelo[i]+1;
            for(;a<n&&b<n;){
                if(map[a][b]==1){
                    ans++;
                }
                a++;
                b++;
            }
            a=i+1;
            b=onelo[i]-1;
            for(;a<n&&b>=0;){
                if(map[a][b]==1){
                    ans++;
                }
                a++;
                b--;
            }

        }
        if(ans==1){
            printf("There is 1 attack.");
        }
        else if(ans!=0){
            printf("There are %d attacks.",ans);
        }else{
            printf("There is no attack.");
        }

    }
    return 0;
}

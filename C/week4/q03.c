#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,ab,zb,ans;
    char aa[255];
    while(scanf("%s",&aa)!=EOF){
        if(aa[0]!='*'){
            ab=atoi(aa);
        }else{
            return 0;
        }
        scanf("%d %d %d",&zb,&a,&b);
        ans=0;
        for(;ab<=zb;ab++){
            if(a*ab<=b){
                ans+=ab;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

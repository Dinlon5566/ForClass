#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    unsigned int num,mask;
    int i,m,count=1;
    bool maskl[32];
    memset(maskl,0,sizeof(maskl));

    while(scanf("%d",&m)&&m!=-1){
        maskl[m]=1;
    }
    for(i=31;i>=0;i--){
        mask<<=1;
        mask+=maskl[i];
    }
    for(i=0;i<32;i++){
        if(maskl[i]){
            printf("%d ",i);
        }
    }
    printf("\n");
    while(~scanf("%u",&num)){
        printf("Case %d: %u\n",count,num);
        printf("%s(all bits 1)\n",mask==(num&mask)?"true":"false");
        printf("%s(exist bits 1)\n",num&mask?"true":"false");
        count++;
    }

    return 0;
}

#include <stdio.h>
int main()
{
    int num,i,time,num_save;
    while(~scanf("%d %d",&num,&i)){
        int ans[255]={};
        num_save=num;
        time=0;
        while(num/i!=0){
            ans[time]=num%i;
            time++;
            num/=i;
        }
        if(num!=0){
            ans[time]=num;
        }
        printf("Change %d to base %d number system: ",num_save,i);
        for(int i=time;i>=0;i--){
            printf("%d",ans[i]);
        }
         puts("");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int max_f(int a,int b){
    return (a>b)?a:b;
}
int main()
{
    int time,num;
    int max,min,rng[100002];
    int startpt,endpt,high;
    scanf("%d",&time);
    for(int time_count=1;time_count<=time;time_count++){
        scanf("%d",&num);

        //return 0
        for(int i=0;i<10002;i++){
            rng[i]=0;
        }
        max=0;
        min=100000;
        while(num--){
            scanf("%d %d %d",&startpt,&high,&endpt);
            max=max_f(max,endpt-1);
            min=min<startpt?min:startpt;
            for(;startpt<endpt;startpt++){
                rng[startpt]=max_f(rng[startpt],high);
            }
        }
        printf("Case %d:",time_count);
        while(min<=max+2){
            printf(" %d %d",min,rng[min]);

            while(rng[min]==rng[min+1]){
                min++;
            }
                min++;
        }
        if(time_count<time){
            printf("\n");
        }
    }
    return 0;
}

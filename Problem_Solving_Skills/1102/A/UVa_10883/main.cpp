#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cas;
    scanf("%d",&cas);
    for(int t=1;t<=cas;t++){
       int n;
       double res,num,c;
       res=num=c=0;

       scanf("%d",&n);
       for(int i=0;i<n;i++){
            scanf("%lf",&num);
            double sum=log2(fabs(num));
            if(i){
                c+=log2(double(n-i)/i);
                sum+=c;
            }
            if(num<0){
                res-=pow(2,sum-(n-1));
            }else{
                res+=pow(2,sum-(n-1));
            }

       }
        printf("Case #%d: %.3lf\n",t,res);
    }
    return 0;
}

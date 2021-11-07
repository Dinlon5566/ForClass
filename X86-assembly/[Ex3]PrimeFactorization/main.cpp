#include <iostream>

using namespace std;
void subfun(int num){
    int div=2;
    int pow;
    bool star=0;
    while(num>1){
        pow=0;
        while(num>1&&num%div==0){
            num/=div;
            pow++;
            //printf("$ %d ",num);
        }
        if(star!=0&&pow!=0){
            printf(" * ");
        }else if(pow!=0){
            star=1;
        }
        if(pow==1){
            printf("%d",div);
        }else if(pow>1){
            printf("%d^%d",div,pow);
        }
        div++;
    }
}
int main()
{
    int num;
    while(scanf("%d",&num)){
        if(num<0){
            break;
        }
        subfun(num);
        printf("\n");
    }

    return 0;
}

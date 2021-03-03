#include <iostream>

using namespace std;

int main()
{
    int time,num;
    scanf("%d",&time);
    while(time--){
        cin>>num;
        if(num&1){
            num=(num-1)*(num-1)/4;
        }else{
            num=num/2*(num/2-1);
        }
        cout<<num<<endl;
    }
    return 0;
}

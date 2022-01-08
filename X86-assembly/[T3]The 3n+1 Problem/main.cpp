#include <iostream>

using namespace std;
int threeN(int n){
    int s=1;
    while(n!=1){
        if(n%2){
            n=n*3+1;
        }else{
            n/=2;
        }
        s++;
    }
    return s;
}
int main()
{
    int i,j;
    while(cin>>i&&i){
        cin>>j;
        int max3n=0;
        cout<<i<<" "<<j<<" ";
        if(i>j){
            swap(i,j);
        }
        for(int a=i;a<=j;a++){
            max3n=max(max3n,threeN(a));
        }
        cout<<max3n<<endl;
    }

    return 0;
}

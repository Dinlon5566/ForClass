#include <iostream>

using namespace std;

int main()
{
    int num,ans,def,t;
    while(cin>>t){
        while(t--){
            cin>>num;
            ans=1;
            def=2;
            for(int i=1;i<num;i++){
                ans+=def;
                if(i%2){
                    def+=2;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

        int stc;

        cin>>stc;
        int stu[stc];

        for(int i=0;i<stc;i++){
            cin>>stu[i];
        }

        int ans=-1;
        int mina=stu[stc-1];

        for(int i=stc-2;i>=0;i--){
            mina=min(mina,stu[i]);
            ans=max(ans,stu[i]-mina);
        }
        if(ans==0){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}

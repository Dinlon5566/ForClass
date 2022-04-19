#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,tmp;
    int cas=1;
    while(cin>>n&&n){

        vector<int> nums;
        for(int i=0;i<n;i++){
            cin>>tmp;
            nums.push_back(tmp);
        }
        sort(nums.rbegin(),nums.rend());
        bool flag=1;

        while(nums[0]!=0){
            int d=nums[0];
            for(int df=1;df<1+d;df++){
                if(nums[df]>0){
                    nums[df]--;
                }else{
                    flag=0;
                    break;
                }
            }
            nums[0]=0;
            sort(nums.rbegin(),nums.rend());
        }
        if(flag){
            cout<<"Possible"<<endl;
        }else{
            cout<<"Not possible"<<endl;
        }

        nums.clear();
    }
    return 0;
}

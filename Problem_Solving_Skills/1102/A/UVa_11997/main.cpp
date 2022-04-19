#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp;
    while(cin>>n&&n){
        vector<vector<int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back(vector<int>());
            for(int j=0;j<n;j++){
                cin>>tmp;
                nums[i].push_back(tmp);
            }
            sort(nums[i].begin(),nums[i].end());
        }
         vector<int> pool(nums[0].begin(),nums[0].end());
         vector<int> newpool;
        for(int i=1;i<nums.size();i++){

            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    newpool.push_back(pool[j]+nums[i][k]);
                }
            }
            sort(newpool.begin(),newpool.end());

            pool.clear();
            pool=vector<int>(newpool.begin(),newpool.begin()+n);
            newpool.clear();
        }

        for(int num:pool){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,tmp;
    while(cin>>n&&n){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            cin>>tmp;
            pq.push(tmp);
        }
        long long int cost=0;

        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            a+=pq.top();
            pq.pop();
            cost+=a;
            pq.push(a);
        }
        cout<<cost<<endl;
    }
    return 0;
}

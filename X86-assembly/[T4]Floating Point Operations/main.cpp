#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double nums[n];

    for(int i=0;i<n;i++)
        cin>>nums[i];

    double maxNum,minNum;

    maxNum=minNum=nums[0];
    double sum=0;
    for(double num:nums){
        maxNum=max(maxNum,num);
        minNum=min(minNum,num);
        sum+=num;
    }

    printf("%+E %+E\n",minNum,maxNum);
    printf("%+E\n",sum);
    printf("%+E\n",minNum*maxNum);
    printf("%+E\n",sum/n);
    printf("%+E\n",sqrt(abs(sum)));

    return 0;
}

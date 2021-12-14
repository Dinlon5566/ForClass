#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void insertSort(T nums[],int arraySize)
{
    for(int i=0; i<arraySize; i++)
        for(int j=i; j>0&&nums[j]<nums[j-1]; j--)
            swap(nums[j],nums[j-1]);
}

int main()
{
    int n;
    cin>>n;
    int nums[n];

    //input result
    for(int i=0; i<n; i++)
        cin>>nums[i];

    insertSort(nums,n);

    //output result
    for(int num:nums)
        cout<<num<<" ";

    cout<<endl;
    return 0;
}

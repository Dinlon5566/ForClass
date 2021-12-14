#include <iostream>
using namespace std;

template <typename T>
void outputArray(T nums[],int arraySize)
{
    for(int i=0; i<arraySize; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

template <typename T>
void insertSort(T nums[],int arraySize)
{
    for(int i=1; i<arraySize; i++)
    {
        for(int j=i; j>0&&nums[j]<nums[j-1]; j--)
            swap(nums[j],nums[j-1]);
        outputArray(nums,arraySize);
    }
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        int nums[n];

        //input result
        for(int i=0; i<n; i++)
            cin>>nums[i];

        insertSort(nums,n);
        //output result
        cout<<endl;
        outputArray(nums,n);
    }

    return 0;
}

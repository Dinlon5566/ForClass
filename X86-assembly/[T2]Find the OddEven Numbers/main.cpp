#include <iostream>
using namespace std;

void pairNums(int nums[],int arrSize)
{
    int odd[255],even[255];

    int oddSum=0;
    int evenSum=0;

    int oddSize=0;
    int evenSize=0;

    for(int i=0;i<arrSize;i++){
        if(nums[i]&1){
            odd[oddSize]=nums[i];
            oddSize++;
        }else{
            even[evenSize]=nums[i];
            evenSize++;
        }
    }

    int oddMax=odd[0];
    int evenMin=even[0];

    cout<<oddSize;
    for(int i=0;i<oddSize;i++){
        cout<<" "<<odd[i];
        oddSum+=odd[i];
        if(odd[i]>oddMax)
            oddMax=odd[i];
    }
    cout<<endl;
    cout<<evenSize;
    for(int i=0;i<evenSize;i++){
        evenSum+=even[i];
        cout<<" "<<even[i];
        if(even[i]<evenMin)
            evenMin=even[i];
    }
    cout<<endl;


    cout<<oddMax<<" "<<evenMin<<endl;
    cout<<oddSum<<" "<<evenSum<<endl;
}
int main()
{
    int nums[255];
    int i=0;
    int n;
    while(cin>>n&&n)
    {
       nums[i]=n;
        i++;
    }
    pairNums(nums,i);
    return 0;
}

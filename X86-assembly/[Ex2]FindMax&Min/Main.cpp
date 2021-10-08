//It is not clear whether the requirement of the topic is ASM calling C/C++ or all written on ASM : (
#include <iostream>

int findMaximum(int *nums,int n){
    int maxNum=INT_MIN;
    for(int i=0;i<n;i++)
        maxNum=nums[i]>maxNum?nums[i]:maxNum;
    return maxNum;
}
int findMinimum(int *nums,int n){
    int minNum=INT_MAX;
    for(int i=0;i<n;i++)
        minNum=nums[i]<minNum?nums[i]:minNum;
    return minNum;
}

int main()
{
    int n;
    scanf("%d",&n); // faster than cin
    int nums[n];
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    printf("Min : %d\nMax : %d\n",findMinimum(nums,n),findMaximum(nums,n));
    return 0;
}

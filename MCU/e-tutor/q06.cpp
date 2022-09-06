#include <iostream>

using namespace std;
void printBinary(unsigned int num)
{
    int *p=new int[32];
    printf("%u = ",num);
    for(int i=0; i<32; i++)
    {
        p[i]=num&1;
        num>>=1;
    }
    for(int i=31; i>=0; i--)
    {
        printf("%d",p[i]);
        if((i)%8==0&&i){
            printf(" ");
        }
    }
    printf(" \n");
    delete(p);
}
int main()
{
    unsigned int num,rnum;
    scanf("%u",&num);
    printf("Before bits are reversed:\n");
    printBinary(num);
    for(int i=0;i<32;i++){
        rnum<<=1;
        rnum+=num&1;
        num>>=1;
    }
    printf("\nAfter bits are reversed:\n");
    printBinary(rnum);
    return 0;
}

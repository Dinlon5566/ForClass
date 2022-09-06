#include <iostream>
using namespace std;

void printBinary(unsigned int num)
{
    int *p=new int[32];
    for(int i=0; i<32; i++)
    {
        p[i]=num&1;
        num>>=1;
    }
    for(int i=31; i>=0; i--)
    {
        printf("%d",p[i]);
    }
    printf("\n");
    delete(p);
}
void printOctal(unsigned int num)
{
    int *p=new int[12];
    for(int i=0; i<12; i++)
    {
        p[i]=num&7;
        num>>=3;
    }
    for(int i=11; i>=0; i--)
    {
        printf("%d",p[i]);
    }
    printf("\n");
    delete(p);
}

void printHexidecimal(unsigned int num)
{
    int *p=new int[8];
    for(int i=0; i<8; i++)
    {
        p[i]=num&15;
        num>>=4;
    }
    printf("0x");
    for(int i=7; i>=0; i--)
    {
        if(p[i]>=10)
        {
            printf("%c",p[i]+'A'-10);
        }
        else
        {
            printf("%d",p[i]);
        }
    }
    printf("\n");
    delete(p);
}

int main()
{
    unsigned int num;
    int count=1;
    while(cin>>num)
    {
        printf("Case %d: %u\n",count,num);
        printBinary(num);
        printOctal(num);
        printHexidecimal(num);
        count++;
    }
    return 0;
}

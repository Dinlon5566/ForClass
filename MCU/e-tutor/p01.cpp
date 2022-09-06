#include <iostream>

using namespace std;

int main()
{
    unsigned int num;
    unsigned int *ns=new unsigned int[8];
    int count=1;
    while(cin>>num)
    {
        printf("Case %d: %u\n",count,num);
        count++;
        for(int i=0; i<9; i++)
        {
            ns[i]=num&15;
            num>>=4;
        }
        for(int i=7; i>=0; i--)
        {
            printf("%X ",ns[i]);
        }
        printf("\n");
    }
    delete(ns);
    return 0;
}

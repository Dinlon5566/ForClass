#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int num)
{
    int p[32];
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
    printf("\n");

}

int main()
{
    unsigned int res=0;
    char pc[4];
    for(int i=0;i<4;i++){
        scanf(" %c",&pc[i]);
    }

    for(int i=0;i<4;i++){
        printf("%c:\n%d = ",pc[i],pc[i]);
        printBinary(pc[i]);
        res<<=8;
        res+=pc[i]&255;
    }
    printf("'%c' and '%c' and '%c' and '%c' packed in an unsigned int:\n%u = ",pc[0],pc[1],pc[2],pc[3],res);
    printBinary(res);

    return 0;
}

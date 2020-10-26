#include <stdio.h>
#include <math.h>
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF){
        printf("%d\n",(int)log2((double)num)+1);
    }
    return 0;
}

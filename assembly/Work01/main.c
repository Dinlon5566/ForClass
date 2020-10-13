#include <stdio.h>
extern void mainasm();
int AllPrimeFactors(int innum)
{
    int flag,cunt=0;
    for (int i = 2; i < innum; i++)
    {
        flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                continue;
            }
        }
        if (!flag)
        {
            printf("%d ", i);
            cunt++;
        }
    }
    printf("\n");
    return cunt;
}
int main()
{
    mainasm();
    return 0;
}
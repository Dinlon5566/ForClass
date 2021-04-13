#include <stdbool.h>
#include <stdio.h>
#define SIZE 300

void get_bin(unsigned int *num, unsigned int *bin)
{
    unsigned int tmpnum=1<<31;
    unsigned int index=0;
    for(int i=0; i<4; i++)
    {
        unsigned int mv=(*(num+i))<<24;
        for(int j=0;j<8;j++){
            if(mv&tmpnum){
                bin[index]=1;
            }else{
                bin[index]=0;
            }
            mv<<=1;
            index++;
        }
    }
}

int main()
{
    int done=0,num;
    while(scanf("%d",&num))
    {
        if(num==0)
        {
            break;
        }
        if(done)
        {
            puts("");
        }
        else
        {
            done++;
        }

        unsigned int domain[4]= {0};
        unsigned int domain_bit[32]= {0};
        unsigned int sub[4]= {0};
        unsigned int sub_bit[32]= {0};
        unsigned int cmp;
        unsigned int cmp_flag;
        scanf("%u.%u.%u.%u/%u",&domain[0],&domain[1],&domain[2],&domain[3],&cmp);
        get_bin(domain,domain_bit);
        puts("--------------------------------------------------------------------------------");
        printf("The following addresses are within the subnetwork %u.%u.%u.%u/%u:\n", domain[0], domain[1], domain[2], domain[3],cmp);

        for(int i=0;i<num;i++){
            scanf("%u.%u.%u.%u",&sub[0],&sub[1],&sub[2],&sub[3]);
            get_bin(sub,sub_bit);
            cmp_flag=1;
            for(int j=0;j<cmp;j++){
                if(sub_bit[j]!=domain_bit[j]){
                    cmp_flag=0;
                    break;
                }
            }
            if(cmp_flag){
                printf("%u.%u.%u.%u\n",sub[0],sub[1],sub[2],sub[3]);
            }
        }
        puts("--------------------------------------------------------------------------------");
    }
    return 0;
}

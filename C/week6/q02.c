#include <stdio.h>
#include <string.h>
int main()
{
    char b[30];
    int time,a,ans[30],bnum[30],len,flag;
    while(~scanf("%d %s",&a,&b))
    {
        for(int i=0; i<30; i++)
        {
            ans[i]=0;
        }
        len=strlen(b);
        for(int i=len-1,j=0; i>=0; i--)
        {
            bnum[i]=(int)(b[j]-'0');
            j++;
        }
        time=2;
        flag=1;
        while(flag)
        {
            for(int i=0; i<30; i++)
            {
                ans[i]=0;
            }
            ans[0]=1;
            for(int t=0; t<a; t++)
            {
                int carry=0;
                for(int i=0; i<29; i++)
                {
                    ans[i]*=time;
                    ans[i]+=carry;
                    carry=0;
                    if(ans[i]>=10)
                    {
                        carry=ans[i]/10;
                        ans[i]%=10;
                    }
                }
            }
            int tflag=0;
            for(int i=0; i<len; i++)
            {
                if(ans[i]!=bnum[i])
                {
                    tflag=1;
                }
            }
            if(tflag==0){
                    flag=0;
                }
            time++;
        }
        printf("%d\n",time-1);
    }
    return 0;
}

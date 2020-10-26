#include <stdio.h>
#include <string.h>

int main()
{
    int a,b;
    char str[13],mini[4];
    double ans;

    while(scanf("%d %d",&a,&b)!=EOF){
            printf("%d^-%d = ",a,b);
        ans=1;
        while(b){
            ans/=a;
            b--;
        }
        sprintf(str,"%E",ans);

        mini[0]=str[10];
        mini[1]=str[11];
        mini[2]=str[12];
        str[10]='\0';
        mini[3]='\0';
        b=atoi(mini);
        sprintf(mini,"%d",b);
        strcat(str,mini);
        puts(str);
    }
    return 0;
}

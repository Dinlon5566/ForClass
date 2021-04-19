#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strrpc(char *str,char *oldstr,char *newstr){
    char bstr[strlen(str)];
    memset(bstr,0,sizeof(bstr));
    int i;
    for(i = 0;i < strlen(str);i++){
        if(!strncmp(str+i,oldstr,strlen(oldstr))){
            strcat(bstr,newstr);
            i += strlen(oldstr) - 1;
        }else{
                strncat(bstr,str + i,1);
            }
    }
    strcpy(str,bstr);
    return str;
}
int main()
{
    char str[255];
    char find[255];
    char rep[255];
    int k=0;
    while(scanf("%s",&find)){
            printf("%d\n",++k);
        if(strcmp(find,"*")==0){
            break;
        }
        scanf("%s",&rep);
        scanf("%s",&str);

        char *a=strrpc(str,find,rep);
        printf("%s\n",a);
    }
    return 0;
}

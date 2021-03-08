#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d\n",&T);
    char cmd[100];
    char str[100];

    while(T--){
        gets(cmd);

        gets(str);


        if(strcmp(cmd,"ECHO")==0){
            printf("%s",str);
        }else if (strcmp(cmd,"UPPERCASE")==0){
            for(int i=0;i<strlen(str);i++){
                printf("%c",toupper(str[i]));
            }
        }else if(strcmp(cmd,"LOWERCASE")==0){
            for(int i=0;i<strlen(str);i++){
                printf("%c",tolower(str[i]));
            }
        }else if(strcmp(cmd,"CAPITALIZATION")==0) {
            str[0]=toupper(str[0]);
            for(int i=0;i<strlen(str)-1;i++){
                if(str[i]==' '){
                    str[i+1]=toupper(str[i+1]);
                }
            }
            printf("%s",str);
        }else if()

        puts("");
    }
    return 0;
}

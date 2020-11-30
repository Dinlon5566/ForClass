#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void E_type(char str[255]){

for(int i=0;i<strlen(str);i++){
    printf("%c",str[i]);
}
printf("\n");
}
void R_type(char str[255]){
for(int i=strlen(str)-1;i>=0;i--){
        printf("%c",str[i]);
}
printf("\n");
}
int main()
{
    char str[255];
    while(~scanf("%s",&str)){

        if(str[0]=='O'){
            break;
        }
        if(str[0]=='E'){
            scanf("%s",&str);
            E_type(str);
        }else{
            scanf("%s",&str);
            R_type(str);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_replace (char *source, char *find,  char *rep){
   int find_L=strlen(find);
   int rep_L=strlen(rep);
   int length=strlen(source)+1;
   int gap=0;
   char *result = (char*)malloc(sizeof(char) * length);
   strcpy(result, source);
   char *former=source;
   char *location= strstr(former, find);

   while(location!=NULL){
       gap+=(location - former);
       result[gap]='\0';
       length+=(rep_L-find_L);
       result = (char*)realloc(result, length * sizeof(char));
       strcat(result, rep);
       gap+=rep_L;

       former=location+find_L;
       strcat(result, former);
       location= strstr(former, find);
   }

   return result;

}
int main()
{
    char orginText[255],search[255],replace[255];
    while(gets(search)){
        if(strcmp(search,"*")==0){
            break;
        }
        gets(replace);
        gets(orginText);
        puts(str_replace(orginText,search,replace));

    }
    return 0;
}


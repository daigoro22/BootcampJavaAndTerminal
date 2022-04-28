#include<string.h>
#include <stdlib.h>

char *concatArgv(int argc,char *argv[],char **concatStr){
  void my_strcat(size_t *size, char **concatStr, const char *s){
    *size += strlen(s);
    *concatStr = (char*)realloc(*concatStr, *size);
    strcat(*concatStr,s);
  }
  size_t size = 1;
  for(int i=0;i<argc;i++){
    if(*concatStr != NULL){
      my_strcat(&size, concatStr, " ");
    }
    my_strcat(&size, concatStr, argv[i]);
  }
}

char *concatArgvOffset(int argc,char *argv[],char *concatStr,int offset){
  for(int i=offset;i<argc;i++){
    strcat(concatStr,argv[i]);
    strcat(concatStr," ");
  }
}



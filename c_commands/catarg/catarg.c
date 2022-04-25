#include<string.h>

char *concatArgv(int argc,char *argv[],char *concatStr){
  for(int i=1;i<argc;i++){
    strcat(concatStr,argv[i]);
    strcat(concatStr," ");
  }
}

char *concatArgvOffset(int argc,char *argv[],char *concatStr,int offset){
  for(int i=offset;i<argc;i++){
    strcat(concatStr,argv[i]);
    strcat(concatStr," ");
  }
}



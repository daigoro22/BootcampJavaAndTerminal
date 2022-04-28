#include<stdio.h>
#include<stdlib.h>
#include"../catarg/catarg.h"

int main(int argc, char *argv[]){
  char *printStr = NULL;
  if(argc<2){
    printStr = "y";
  }else{
    concatArgv(argc-1,argv+1,&printStr);
  }

  while(1)
    puts(printStr);
}

#include<stdio.h>
#include<stdlib.h>
#include"../catarg/catarg.h"

int main(int argc, char *argv[]){
  char *printStr = malloc(1);
  if(argc<2){
    printStr = "y";
  }
  concatArgv(argc,argv,printStr);

  while(1)
    puts(printStr);
}

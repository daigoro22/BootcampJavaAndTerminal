#include<stdio.h>
#include"../catarg/catarg.h"
#include<unistd.h>
#include<stdbool.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
  int opt;
  bool nFlag=false;
  bool eFlag=false;
  
  while(( opt = getopt(argc,argv,"neE"))!=-1){
    switch(opt){
      case 'n':
      nFlag=true;
      break;
      case 'e':
      eFlag=true;
      break;
      case 'E':
      eFlag=false;
      break;
    }
  }

  char *concatStr=(char*)malloc(1);
  
  concatArgvOffset(argc,argv,concatStr,optind);
  fputs(concatStr,stdout);
} 

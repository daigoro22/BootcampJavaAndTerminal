#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>

int main(int argc,char *argv[]){
  int opt;
  bool bFlag=false;
  bool EFlag=false;
  bool nFlag=false;
  bool sFlag=false;
  bool TFlag=false;
  bool vFlag=false; 

  while(( opt = getopt(argc,argv,"bEnsTvAet"))!=-1){
    switch(opt){
      case 'b':
      bFlag=true;
      break;
      case 'E':
      EFlag=true;
      break;
      case 'n':
      nFlag=true;
      break;
      case 's':
      sFlag=true;
      break;
      case 'T':
      TFlag=true;
      break;
      case 'v':
      vFlag=true;
      break;
    }
  }
  
  int c,n=1;
  FILE *fp;
  fpos_t pos;
  while(optind<argc){
    if((fp = fopen(argv[optind++],"r"))!=NULL){
      if(bFlag||nFlag){
          printf("%d  ",n++);
      }
      while((c=fgetc(fp))!=EOF){
        putchar(c);
        if(bFlag&&c=='\n'){
          fgetpos(fp,&pos);
          int b = fgetc(fp);
          if(b!='\n'){
            printf("%d  ",n++);
          }
          fsetpos(fp,&pos);
        }else if(nFlag&&c=='\n'){
          printf("%d  ",n++);
        }
      }
      fclose(fp);
    }
    else if(*argv[optind-1]=='-'){
      while((c=getchar())!=EOF) putchar(c);
    }
    else{
      puts("Permission denied or Filepath not exists.");
      continue;
    }
  }
}

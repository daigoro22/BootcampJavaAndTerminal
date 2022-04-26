#include<stdio.h>
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

  char const *s = argv[optind];
  char c;

  while((c=*s++)){
    if(c=='\\'&&*s&&eFlag){
      switch(c=*s++){
        case 'a': c='\a'; break;
        case 'b': c='\b'; break;
				case 'c': exit (EXIT_SUCCESS);
				case 'e': c = '\x1B'; break;
				case 'f': c = '\f'; break;
				case 'n': c = '\n'; break;
				case 'r': c = '\r'; break;
				case 't': c = '\t'; break;
				case 'v': c = '\v'; break;
			}
		}
		putchar(c);
	}

	if(!nFlag){
		putchar('\n');
	} 
} 

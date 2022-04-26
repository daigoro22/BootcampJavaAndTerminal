#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc,char *[] argv)
{ 
	int opt;

  while(( opt = getopt(argc,argv,"aAbBcC"))!=-1){
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
 
	DIR *dir;
	struct dirent *dp;
	char dirpath[] = "/tmp";

	dir = opendir(dirpath);
	if (dir == NULL) { return 1; }

	dp = readdir(dir);
	while (dp != NULL) {
			printf("%s\n", dp->d_name);
			dp = readdir(dir);
	}

	if (dir != NULL) { closedir(dir); }

	return 0;
} 

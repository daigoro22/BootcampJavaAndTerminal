#include<stdio.h>
#include<wchar.h>
#include<locale.h>

int main(){
  FILE *fpn = fopen("narrow.txt","r");
  FILE *fpw = fopen("wide.txt","r");

  setlocale(LC_ALL,"");

  printf("fgetc to narrow: %c\n",fgetc(fpn));

	wint_t cw = fgetwc(fpw);
	printf("fgetwc to wide: %lc\n",cw);

  fwide(fpw,-1);
  printf("fgetc to wide: %c\n",fgetc(fpw));

  fclose(fpw);
  fclose(fpn);
}


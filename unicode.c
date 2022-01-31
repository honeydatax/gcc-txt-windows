#include <unistd.h>
#include "txtwin.h"
char echar[10];
char *getechar(char c){
	char c1=195;
	char c2=148;
	char c3=0;
	char c4=0;
	char c5=c & 0xff;
	c3=c5 & 0xf;
	c4=(c5 & 0xf0)>>4;
	c1=c1 + c3;
	c2=c2 + c4;
	echar[0]=c1;
	echar[1]=c2;
	echar[2]=0;
	return echar;
}

int main(){
	char c[9000];
	int n;
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	c[0]=0;
	for(n=0;n<255;n++){
		strcat(c,getechar(n));
	}
	replaceCharString(c,'\n',' ');
	replaceCharString(c,'\r',' ');
	replaceCharString(c,127,' ');
	replaceCharString(c,8,' ');
	replaceCharString(c,7,' ');
	createWin(newwins,5,4,16,16,4,6);
	printwin(newwins,0,0,c);
	drawin(newwins);
	refresh();
	sleep(5);
	free(newwins->s);
	endterminal();
	return 0;
}

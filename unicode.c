#include <unistd.h>
#include "txtwin.h"

int main(){
	char c[9000];
	int n;
	char *cc;
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	c[0]=0;
	for(n=0;n<255;n++){
		cc=getechar(n);
		if(cc[0]!='.')strcat(c,cc);
	}
	replaceCharString(c,'\n',' ');
	replaceCharString(c,'\r',' ');
	replaceCharString(c,127,' ');
	replaceCharString(c,8,' ');
	replaceCharString(c,7,' ');
	createWin(newwins,5,4,32,16,4,6);
	printwin(newwins,0,0,c);
	drawin(newwins);
	refresh();
	sleep(5);
	free(newwins->s);
	endterminal();
	return 0;
}

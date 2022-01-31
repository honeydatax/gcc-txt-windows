#include <unistd.h>
#include "txtwin.h"

void mainloop(struct win *newwins){
	char cc[2080];
	char ccc[10];
	char *c;
	cc[0]=0;
	createWin(newwins,5,4,16,16,4,6);
	printwin(newwins,0,0,"");
	drawin(newwins);
	refresh();
	while(1){
		cc[0]=0;
		ccc[0]=getc(stdin);
		if(ccc[0]!=255 && ccc[0]!=0)break;
		tempdate(cc);
		replaceCharString(cc,'\n',' ');
		replaceCharString(cc,'\r',' ');
		replaceCharString(cc,127,' ');
		replaceCharString(cc,8,' ');
		replaceCharString(cc,7,' ');
		printwin(newwins,0,0,cc);
		drawin(newwins);
		refresh();
		sleep(1);
	}
}
int main(){
	char *c;
	int n;
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	mainloop(newwins);
	frees(newwins->s);
	endterminal();
	return 0;
}

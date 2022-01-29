#include <unistd.h>
#include "txtwin.h"

char *mainloop(struct win *newwins){
	char cc[1000];
	char ccc[1000];
	char *c;
	c=newString("");
	createWin(newwins,5,4,16,16,4,6);
	printwin(newwins,0,0,c);
	drawin(newwins);
	refresh();
	cc[0]=0;
	while(cc[0]!='\n'){
		while(1){
			cc[0]=getc(stdin);
			if(cc[0]!=255 && cc[0]!=0)break;
		}
		cc[1]=0;
		locate(1,1);
		printf(" chr : %d    ",cc[0]);
		c=catString(c,cc);
		replaceCharString(c,'\n',' ');
		replaceCharString(c,'\r',' ');
		replaceCharString(c,127,' ');
		replaceCharString(c,8,' ');
		replaceCharString(c,7,' ');
		printwin(newwins,0,0,c);
		drawin(newwins);
		refresh();
	}
	return c;
}
int main(){
	char *c;
	int n;
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	c=mainloop(newwins);
	frees(c);
	frees(newwins->s);
	endterminal();
	return 0;
}

#include <unistd.h>
#include "txtwin.h"
int main(){
	char c[256];
	int n;
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	for(n=0;n<254;n++){
		if(n+32!=127){
			c[n]=n+32;
		}else{
			c[n]=32;
		}
	}
	c[128-32]=0;
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

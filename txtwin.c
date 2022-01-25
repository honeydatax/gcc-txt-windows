#include <unistd.h>
#include "txtwin.h"
int main(){
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	startTerminal();
	cls();
	createWin(newwins,10,5,10,10,4,6);
	printwin(newwins,4,4,"hello world......");
	drawin(newwins);
	refresh();
	sleep(5);
	free(newwins->s);
	endterminal();
	return 0;
}

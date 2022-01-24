#include "txtwin.h"
int main(){
	struct win newwin;
	struct win *newwins;
	newwins=&newwin;
	cls();
	locate(3,10);
	colors(4,6);
	createWin(newwins,10,5,10,10,4,6);
	printwin(newwins,4,4,"hello world......");
	drawin(newwins);
	free(newwins->s);
	return 0;
}

#include <unistd.h>
#include "txtwin.h"

char *cccc="----->";
void mainloop(struct win *newwins,struct win *newwinss){
	char cc[2080];
	char cc2[2080];
	char ccc[10];
	char *c;
	char *c1;
	int tabs=0;
	int n=0;
	cc[0]=0;
	createWin(newwins,8,4,8,5,4,6);
	createWin(newwinss,5,4,8,5,6,4);
	printwin(newwins,0,0,"");
	printwin(newwinss,0,0,"");
	drawin(newwins);
	drawin(newwinss);
	refresh();
	while(1){
		cc[0]=0;
		cc2[0]=0;
		ccc[0]=getc(stdin);
		if(ccc[0]==27)break;
		if(ccc[0]==10)tabs++;
		if(tabs>1)tabs=0;
		tempdate(cc);
		c1=cccc+n;
		strcpy(cc2,"press enter to change windows ");
		strcat(cc2,c1);
		strcat(cc2,"     ");
		n++;
		if (n>4)n=0;
		printwin(newwins,0,0,cc);
		printwin(newwinss,0,0,cc2);
		if(tabs==0){
			drawin(newwins);
			drawin(newwinss);
		}else{
			drawin(newwinss);
			drawin(newwins);
		}
		refresh();
		sleep(1);
	}
}
int main(){
	char *c;
	int n;
	struct win newwin;
	struct win newwinn;
	struct win *newwins;
	struct win *newwinss;
	newwins=&newwin;
	newwinss=&newwinn;
	startTerminal();
	cls();
	mainloop(newwins,newwinss);
	frees(newwins->s);
	frees(newwinss->s);
	endterminal();
	return 0;
}

#include <termios.h>
#include "fileList.h"

#define mmsize 4080
#define back 40
#define fore 30
struct termios oldt,newt;
struct win{
	int x;
	int y;
	int w;
	int h;
	int bcolors;
	int fcolors;
	char *s;
};

void cls(){
	printf("\ec");
}
void locate(int x,int y){
	printf("\e[%d;%df",y,x);
}
void colors(int bcolor,int fcolor){
	printf("\e[%d;%dm",bcolor+back,fcolor+fore);
}
void printn(char *s, int n){
	char c[mmsize];
	int nn;
	nn=n;
	if (nn>mmsize-10)nn=4070-10;
	strncpy(c,s,(size_t) nn);
	c[nn]=0;
	printf("%s",c);
}

void createWin(struct win *newwin,int x,int y,int w, int h,int bcolor,int fcolor){
	newwin->x=x;
	newwin->y=y;
	newwin->w=w;
	newwin->h=h;
	newwin->fcolors=fcolor;
	newwin->bcolors=bcolor;
	newwin->s=malloc(w*h+10);
	memset(newwin->s,' ',(size_t)w*h);
}
void printwin(struct win *newwin,int x,int y,char *ss){
	int maxsizes;
	int starts;
	int pos;
	char *c;
	if(ss!=NULL){
		maxsizes=strlen(ss);
		pos=y*newwin->w+x;
		if (pos<newwin->w*newwin->h){
			c=newwin->s+pos;
			if(pos+maxsizes>newwin->w*newwin->h)maxsizes=newwin->w*newwin->h-pos-1;
			strncpy(c,ss,(size_t)maxsizes);
		}
		
	}
}
void drawin(struct win *newwin){
	int n;
	char *c;
	int nn=0;
	for(n=newwin->y;n<newwin->y+newwin->h;n++){
		locate(newwin->x,n);
		colors(newwin->bcolors,newwin->fcolors);
		c=newwin->s+nn;
		printn(c,newwin->w);
		nn=nn+newwin->w;
	}
}
void refresh(){
	locate(1,1);
	printf("\n");
}
void startTerminal(){
	tcgetattr(fileno(stdin),&oldt);
	memcpy(&newt,&oldt,sizeof(struct termios));
	newt.c_lflag &= ~(ECHO|ICANON);
	newt.c_cc[VTIME]=0;
	newt.c_cc[VMIN]=0;
	tcsetattr(fileno(stdin),TCSANOW,&newt);
}
void endterminal(){
	oldt.c_lflag|=ECHO|ICANON;
	tcsetattr(fileno(stdin),TCSANOW,&oldt);
}

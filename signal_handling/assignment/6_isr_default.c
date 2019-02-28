#include"header.h"
void my_isr(int n)

{	
	static int  sigi,sigq;
	if(n==SIGINT)
		sigi++;
	else if(n==SIGQUIT)
		sigq++;
	if(sigi==3)
		signal(SIGINT,SIG_DFL);
	if( sigq==5)
		signal(SIGQUIT,SIG_DFL);

	puts("my_isr");


}
void main()
{
	puts("main");
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	while(1);


}

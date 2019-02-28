#include "header.h"
void my_isr()
{
	static int i=0;
	printf("MY_ISR %d\n",i);
	i++;
	alarm(5-i);
	if(i==5)
	raise(9);


}
void main()
{

printf("Main");
signal(SIGALRM,my_isr);
alarm(10);
//while(puts("."));
while(1);




}

#include "header.h"
void main()
{
	puts("main");
	int i;
	for(i=0;i<3;i++)
	{
		if(fork()==0)
		{
			break;
		}
		else
		{
			puts("CHILd");
		}
	
	}
	while(1);

}

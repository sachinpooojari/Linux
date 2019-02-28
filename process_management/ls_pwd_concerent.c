#include "header.h"
main()
{	int i;
	for(i=0;i<3;i++)
	{
		if(fork()==0)
			puts("hia");
		else
			;
		//	puts("bye");
		
	}
	while(1);

}

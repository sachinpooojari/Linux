#include"header.h"
void main()
{
	printf("Main\n");
	int i=10;
//	if(fork()==0)
	if(vfork()==0)
	{
		printf("Child \n");
		sleep(5);
		i=11;
//		exit(1);
	}
	else
	{
		printf("Parent\n");
		printf("%d\n",i);
		sleep(10);
		
	}

	while(1);




		
	



}

#include"header.h"
main()
{

	if(fork()==0)
	{
		printf("child %d\n",getpid());
		sleep(2);
		exit(0);
	
	}
	else
	{
		printf("Paremt  %d\n",getpid());
		signal(SIGCHLD ,SIG_IGN);

	
	
	}
	while(1);

}



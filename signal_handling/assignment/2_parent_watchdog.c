#include"header.h"

int k;


void my_isr(int n)
{
	printf("killlinng child %d \n",k);
	if(kill(k,9)==0)
		printf("parent killed \n");

	else 
		printf("parent N O T present\n");

}


void main()
{
	time_t t1,t2;

	if((k=fork())==0)
	{
		srand(getpid());
		int n=rand()%10+1;
		printf("chile PID=%d delay=%d\n",getpid(),n);	
		sleep(3);
		printf("still exicutes\n");
	//	exit(0);
	
	}
	else
	{	
		printf("Parent %d\n",getpid());
		signal(SIGALRM,my_isr);
		alarm(5);


	}
while(1)
;
}

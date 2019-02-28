#include"header.h"

int a[3];
void my_isr(int n)
{
	static int c=0;
	puts("isr  ");
	if(c==0)
	{		kill(a[0],9);
		printf("chld1 %d killd\n",a[0]);
	}
	
	else if(c==1)
	{	kill(a[2],9);
		printf("chld1 %d killd\n",a[1]);
	}
	else if(c==2)
	{	kill(a[1],9);
		printf("chld1 %d killd\n",a[2]);
	}	
	else
	{
		raise(19);
	
	}
	c++;
			      	alarm(2);
	
}
		int n;	
void main()
{
	printf("%d Parent \n",getpid());
	if((a[0]=fork())!=0)
	{//exclusive parent 
		if((a[1]=fork())!=0)
		{
			if((a[3]=fork())!=0)
			{
				signal(SIGALRM,my_isr);
			     	alarm(4);     
// //		sleep(5);				
//			      	alarm(2);
//		sleep(5);				
//				alarm(2);

				while(1);
			}else
			{//c3 8
				int n;
				srand(getpid());
				n=rand()%10+1;
				printf("child 3 pid %d n %d \n",getpid(),n);


			}

		}
		else
		{//c2 6
				srand(getpid());
				n=rand()%10+1;
				printf("child 2 pid %d n %d \n",getpid(),n);

		}

	}
	else
	{//c1 4
				srand(getpid());
				n=rand()%10+1;
				printf("child 1 pid %d n %d\n",getpid(),n);

	
	}

while(1);

}

#include "header.h"
void main()
{
	int a[3];
	int i;
	for(i=0;i<3;i++)
	{
	if((a[i]=fork())==0)
	{
		printf("Pid =%d,a[%d]= %d\n",getpid(),i,a[i]);

	//	sleep(10);
	
		
		exit(1);
		break;
	}
	else
	{
		int r,s;
		while((r=wait(&s))!=-1)
		{	int j;
			for(j=0;j<3;j++)
				if(r==a[i])
				{	printf("process %d is terminated a[%d]\n",r,i);
					break;
					}
		}
		
	
	
	}

	}

	while(1);

}




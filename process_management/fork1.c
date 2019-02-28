#include "header.h"
void main()
{
FILE *fp;
fp=fopen("data","r");
if(fp==0)
{
	perror("error");
	fork();
	fp=fopen("data","r");
	perror("child ");
	puts("t");

}
else
	puts("DONE");
			
while(1);
}

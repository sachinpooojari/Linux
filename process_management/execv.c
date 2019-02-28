#include "header.h"
void main(int a,char** argc,char **env)
{

	char *p[]={"ls","-l",NULL};
	//execvp(p[0],p);
	printf("%s  ",argc[1]);
	execvp(argc[1],argc+1);



}


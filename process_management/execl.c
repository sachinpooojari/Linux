#include "header.h"
void main(int argc,char ** agrv,char **env)
{
	int i;
	for(i=0;env[i];i++)
		printf("%s\n",env[i]);
	//execl("/bin/ls","ls","-l",NULL);
	execlp(env[1],env[2],NULL);


}

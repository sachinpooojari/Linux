#define _BSD_SOURCE
#include <signal.h>
extern const char *const sys_siglist[];
#include<stdio.h>
main()
{
      
printf("%s\n",sys_siglist[19]);

while(1);
}

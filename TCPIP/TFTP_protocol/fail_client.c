#include"header.h"
#define DATA_MAX 512

char* RRQ(char *fname,char *mode)
{
	char *rrq;
	rrq=calloc(2+strlen(fname)+1+strlen(mode)+1,1); // 2byte opcode + fname + 1 byte zero + mode + 1 byte zero
	
	strcat(rrq,"01");
	strcat(rrq,fname);
	strcat(rrq+strlen(fname)+2+1,mode);
/*	int i=sizeof(rrq);
	printf("size: %d\n",i);	
	for(i=0 ;i< 20 ;i++)
	{
		printf("%c ",rrq[i]);
	}
	printf("\n");
*/
	return rrq;
}


char* WRQ(char *fname,char *mode)
{
	char *wrq;
	wrq=calloc(2+strlen(fname)+1+strlen(mode)+1,1); // 2byte opcode + fname + 1 byte zero + mode + 1 byte zero
	
	strcat(wrq,"02");
	strcat(wrq,fname);
	strcat(wrq+strlen(fname)+2+1,mode);
	int i=sizeof(wrq);
	return wrq;

}

void read_frame(char *s)
{
	printf("opcode:%c%c\n",s[0],s[1]);
	char *fname,*mode;
	fname=s+2;
	printf("File name :%s\n",fname);
	mode=s+2+strlen(fname)+1;
	printf("Mode :%s\n",mode);
}

void DATA(char* s)
{
	char *wrq;
	wrq=calloc(2+2+DATA_MAX); // 2byte opcode  + fname + 2 byte block_no + 512 byte data 
	
	strcat(wrq,"03");
	strcat(wrq,);
	strcat(wrq+strlen(fname)+2+1,mode);
	int i=sizeof(wrq);
	return wrq;

}




void main(int argc,char**argv)
{
	///if(argc<3)
	//	{	puts("./client  port_no fname ");	return;	}
	int sfd;
/*	sfd=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");
	if(sfd<0)
			return;
////////
	struct sockaddr_in v;
	int len;
ui	v.sin_family=AF_INET;
	v.sin_port=htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(v);
////////
//	char s[20];	
	printf("Enter data\n");
///	scanf("%s",s);
//	sendto(sfd,s,sizeof(s),0,(struct sockaddr*)&v,len);
//	printf("data :  %s\n",s);
///////////////
	
	char *s;
*/
char *s;	
s=RRQ("data","netascii");
read_frame(s);	
s=WRQ("hai hello","binaryfilecii");
read_frame(s);	


	int fd;
	fd=open("data1",0,0664);
	if(fd<0)
	{		perror("read");
			return;
	}
	printf("fd=%d\n\n",fd);
	char str[DATA_MAX];
	bzero(str,sizeof(str));
	int i;
	for(i=0;i<DATA_MAX;i++)
	{
		char ch;
		if(read(fd,&ch,sizeof(ch))==0)   //come out if EOF
		{
			perror("read");
			break;
		}
		s[i]=ch;
	}
	printf("%s\n%d",s,strlen(s));
DATA(s);
	
}

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include<errno.h>

int main()
{
	int fd,i=0;
	char Ubuff[100];
	char *Kbuff="writing from user space to kernel";
	while(Kbuff[i] !='\0')
	{
		i++;
	}
	fd=open("/dev/CharDev",O_RDWR,0777);
	
	if(fd<0)
	{
		perror("user space: error\n");
		exit(1);
	}
 
	write(fd,Kbuff,i);
	read(fd,Ubuff,100);
	printf("the data read from kernel is %s\n",Ubuff);
	close(fd);
	return 0;
}

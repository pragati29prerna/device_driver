#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd,i=0;
	int Ubuff;
	int Kbuff[2]={20,10};
	
	fd=open("/dev/adddev",O_RDWR,0777);
	
	if(fd<0)
	{
		perror("user space: error\n");
		exit(1);
	}
 
	write(fd,Kbuff,sizeof(Kbuff));
	read(fd,&Ubuff,sizeof(Ubuff));
	printf("the data read from kernel is %d\n",Ubuff);
	close(fd);
	return 0;
}

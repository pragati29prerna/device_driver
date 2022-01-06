//application program for open and close calls

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
	int fd;
	fd=open("/dev/MyCharacterDevice",O_RDWR,0777); //open function to connect to device driver module
	if(fd<0)
	{
		printf("user space: error\n");
		exit(1);
	}
	printf("open done successfully\n");
	close(fd);
}

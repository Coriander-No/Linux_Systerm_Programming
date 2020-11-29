#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
//#include"tlpi_hdr.h"

#define MAX_READ   20
#define MAX_WRITE  20
int main()
{
	int fd;
	ssize_t numRead;
	ssize_t numWrite;
	char buffer[MAX_READ + 1];
	char buffer1[MAX_WRITE + 1];
	fd = open("../doc/test.txt", O_RDWR);
	if (fd == -1)
		printf("error\n");
//	fd = open("../doc/test2.txt", O_CREAT);
//	if (fd == -1)
//		printf("error\n");
	numRead = read(fd, buffer, MAX_READ);
	if (numRead == -1)
		printf("read\n");
	buffer[numRead] = '\0';
	printf("The input data was: %s\n", buffer);
	numWrite = write(fd, buffer1, MAX_WRITE);


	return 0;
}

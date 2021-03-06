#include<sys/stat.h>
#include<fcntl.h>
#include <sys/types.h>
#include"tlpi_hdr.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int inputFd;
	int outputFd;
	int openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	if (argc != 3 || strcmp(argv[1], "--help") == 0)
		usageErr("%s old-file new-file\n", argv[0]);
	inputFd = open(argv[1], O_RDONLY);
	if (inputFd == -1)
		errExit("opening file %s", argv[2]);
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP |
		    S_IROTH | S_IWOTH;
	if (outputFd == -1)
		errExit("opening file %s", argv[2]);

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
		if(write(outputFd, buf, BUF_SIZE) != numRead)
			fatal("couldn't write whole buffer");
	if (numRead == -1)
		errExit("read");
	if (close(inputFd) == -1)
		errExit("close input");
	if (close(outputFd) == -1)
		errExit("close outout");

	exit(EXIT_SUCCESS);
}

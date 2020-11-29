#ifndef TLPI_HDR_H
#define TLPI_HDR_H

#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<error.h>
#include<string.h>

//#include"get_num.h"
//#include"error_functions.h"

typedef enum{
	false,
	true
}Bool;

#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)

#endif


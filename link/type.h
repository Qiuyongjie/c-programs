#ifndef   __TYPE_H__
#define   __TYPE_H__
#include   <stdio.h>

typedef int data_t;

typedef struct Link LINK;
struct Link{
	data_t data;
	LINK* next;
};

#endif 

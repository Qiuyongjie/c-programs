
#include <stdio.h>
#include "../include/idgen.h"
#include <math.h>
#define MAXIDS pow(2,sizeof(int) * 8)
#define MINSZ (sizeof(int) + 1)


#if 0
int main(int argc, const char *argv[])
{
	printf("%d\n", getId());
	return 0;
}
#endif


int getId(void)
{
	static int id = 0;

	if (id == MAXIDS)
		id = 1;
	else
		id++;

	return id;
}

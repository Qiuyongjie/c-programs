#include <stdio.h>
#include <stdlib.h>
#include "type.h"


int main(int argc, const char *argv[])
{
	dlink *start = Init();
	int i = 0;

	printf("After init: \n");
	Display(start);

	for (i; i < 10; i++)
	{
		start = Insert(start, i);
	}
	printf("After Insert: \n");
	Display(start);
	
	if (ChangeByOff(start, 2, 101) == -1)
		printf("ChangeByOff error!\n");

	if (ChangeByVal(start, 3, 102) == -1)
		printf("ChangeByVal error!\n");

	Display(start);

	if (DeleteByVal(start, 101) == -1)
		printf("Delete error!\n");

	Display(start);

	if ((DeleteByOff(start, 2)) == -1)
		printf("DeleteByOff error!\n");
	
	Display(start);
	
	Free(start);


	return 0;
}

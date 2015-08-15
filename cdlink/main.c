


#include <stdio.h>
#include <stdlib.h>
#include "cdlink.h"


int main(int argc, const char *argv[])
{
	int num = 10;
	int i = 1;
	cdlink *beg = Init(12138);

	if (NULL == beg) {
		fprintf(stderr, "init error!");
		return -1;
	}


	while (i < num) {
		if (-1 == InsertAtOff(beg, 1, i)) {
			printf("InsertAtOff error!\n");
		}

		i++;
	}

	//printf("1111111111111111\n");

	Display(beg);

	if (-1 == InsertByKey(beg, 9, 1001))
		printf("InsertByKey error!\n");

	Display(beg);

	if (-1 == ChangeAtOff(beg, 8, 1008))
		printf("ChangeAtOff error!\n");

	if (-1 == ChangeByKey(beg, 1001, 2000))
		printf("ChangeByKey error!\n");

	Display(beg);

	if (-1 == DeleteByOff(beg, 8))
		printf("DeleteByOff error!\n");

	if (-1 == DeleteByKey(beg, 2000))
		printf("DeleteByKey error!\n");

	Display(beg);

	FreeALL(beg);


	//printf("---------------\n");

	return 0;
}



#include <stdio.h>
#include "../include/extproc.h"
#include "../include/idgen.h"
#include "../include/memtype.h"


int main(int argc, const char *argv[])
{
	mlink *head = ext_Init();
	int i = 0;
	int sz = 32;

	if (NULL == head) {
		fprintf(stderr, "ext_Init error! 1");
		return -1;
	}

	while (i < 10) {
		if (ext_InsertDefault(head, sz) == -1)
			return -1;
		i++;
	}

	PrintAll(head);

	puts("Okay!\n");
	ext_FreeAll(head);

	return 0;
}

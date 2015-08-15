


#include <stdio.h>
#include <math.h>
#include "BSTree.h"
#define RAND(i) ((i) % 2 ? -1 : 1)* rand() % 1024

int main(int argc, const char *argv[])
{
	BST *root = Init();
	BST *p = NULL;
	int i = 0;

	while (i < 10) {
		root = Insert(root, RAND(i++));
		printf("%p\n", root);
	}
	Print(root);

#if 0
	while (1) {

		scanf("%d", &i);

		if (NULL == (p = FindData(root, i))) {
			printf("not found\n");
			return -1;
		}

		printf("%p\n", p = Find_parent(root, p));
	}
	//Print(root);
#endif

	//delete 
	while (1) {
		printf("Input an node's key to delete:\n");
		scanf("%d", &i);

		if (NULL == (p = FindData(root, i))) {
			printf("not found\n");
		} else {
			if (Delete(root, p) == 0) {
				printf("delete ok\n");

				if (root != NULL)
					Print(root);
				else {
					printf("binary tree is NULL\n");
					break;
				}
			}
		}
	}
	return 0;
}



#ifndef __BSTREE_H__
#define __BSTREE_H__
#include <stdlib.h>
#include <stdio.h>

#define  data_t int

typedef struct BSTree BST;

struct BSTree {
	data_t data;
	BST *lchild;
	BST *rchild;
};

BST *Init(void);
BST *Print(BST * t);
BST *Insert(BST * t, data_t val);
BST *FindData(BST * t, data_t val);

BST *Find_parent(BST * rt, BST * ch);
BST *getParentofMax_left(BST * root);	/*feature: no rchild only left child or not have */
BST *getParentofMin_right(BST * root);	/*feature: no lchild only right child or not have */

#endif

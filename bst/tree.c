

#include "BSTree.h"


BST *Init(void)
{
	return NULL;
}

BST *Insert(BST * s, data_t val)
{
	if (NULL == s) {
		s = (BST *) malloc(sizeof(BST));

		if (NULL == s) {
			perror("malloc");
			return NULL;
		}

		s->data = val;
		s->lchild = NULL;
		s->rchild = NULL;
	} else if (s->data > val) {
		s->lchild = Insert(s->lchild, val);
	} else if (s->data < val)
		s->rchild = Insert(s->rchild, val);

	return s;
}

BST *FindData(BST * root, data_t val)
{
	BST *s = root;

	if (NULL == s) {
		return NULL;
	} else if (s->data == val) {
		return s;
	} else if (s->data > val) {
		s = FindData(s->lchild, val);
	} else if (s->data < val) {
		s = FindData(s->rchild, val);
	}

	return s;
}

BST *Print(BST * t)
{
	if (NULL == t)
		return NULL;

	printf("pre-order: %d\n", t->data);
#if 0
	printf("self: %p\n", t);
	printf("lchild : %p\n", t->lchild);
	printf("right : %p\n", t->rchild);
	putchar(10);
#endif
	Print(t->lchild);
	Print(t->rchild);

	return NULL;
}

int Delete(BST * root, BST * who)
{
	BST *parent = root;

	if (root == who) {	/*cannot delete root before BSTree have more than 1 node */
		if (root->lchild == NULL && root->rchild == NULL) {
			free(root);
			root = NULL;

			return 0;
		} else {
			puts("cannot Delete() root! BSTree has more than 1 node.\n");
			return -1;
		}
	}
	parent = Find_parent(root, who);
	if (NULL == parent)
		return -1;

	/*case 1: Dingke */
	if (who->lchild == NULL && who->rchild == NULL) {
		if (parent->lchild == who)
			parent->lchild = NULL;
		else
			parent->rchild = NULL;

		return 0;
	} else if (who->lchild == NULL) {	/* only right child */
		if (parent->lchild == who)
			parent->lchild = who->rchild;
		else
			parent->rchild = who->rchild;

		return 0;

	} else if (who->rchild == NULL) {	/* only left child */
		if (parent->lchild == who)
			parent->lchild = who->lchild;
		else
			parent->rchild = who->lchild;

		return 0;

	} else {		/* have two children */

		if (who->lchild->rchild != NULL)
			/*MAX*/ {
			BST *maxParent = getParentofMax_left(who->lchild);
			BST *max = maxParent->rchild;

			who->data = maxParent->rchild->data;

			//pingjie max de zuohaozi
			maxParent->lchild = max->lchild;

			free(max);
			}
#if 0
		else {

		}
#endif
	}

	return 0;
}

BST *getParentofMax_left(BST * root)
{				/*feature: no rchild only left child or not have */
	/* */
	BST *parent = root;
	BST *maxchild = parent->rchild;

	while (maxchild->rchild != NULL) {
		parent = maxchild;
		maxchild = maxchild->rchild;
	}
	return parent;
}

BST *getParentofMin_right(BST * root)
{				/*feature: no lchild only right child or not have */
	BST *parent = root;
	BST *minchild = parent->lchild;

	while (minchild->lchild != NULL) {
		parent = minchild;
		minchild = parent->lchild;
	}

	return parent;
}



BST *Find_parent(BST * parent, BST * child)
{
	BST *p = NULL;

	if (NULL == parent)
		return NULL;

	if (parent->lchild == child || parent->rchild == child)
		return parent;

	if (NULL != (p = Find_parent(parent->lchild, child)))
		return p;
	if (NULL != (p = Find_parent(parent->rchild, child)))
		return p;

	return NULL;
}

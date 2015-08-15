/*
 *
 * @author : youyou
 * @mail: iotpanda # gmail.com
 * @function: lib functions for manipulating cyclic-double-link  list.
 *
 */

#include "cdlink.h"


/*
 *
 *  Initailize a link list
 */
cdlink *Init(data_t val)
{
	cdlink *flags = (cdlink *) malloc(sizeof(cdlink));

	if (NULL == flags) {
		perror("Init: malloc");
		return NULL;
	}

	flags->data = val;
	flags->pre = flags;
	flags->post = flags;

	return flags;
}

/*
 *
 *  count out the number of nodes.
 */
int Count(cdlink * pos)
{
	int sum = 1;
	cdlink *p = pos->post;


	while (p != pos) {
		sum++;
		p = p->post;

		if (NULL == p)
			return -1;
	}

//      printf("Count : %d\n", sum);

	return sum;
}


cdlink *FindByOff(cdlink * beg, offset_t off)
{
	cdlink *p = beg;
	int realoff = Count(beg);

	if (realoff == -1) {
		printf("FindByOff error!\n");
		return NULL;
	}

	if (NULL == beg) {
		printf("Error: illeagel cdlink pionter\n");
		return NULL;
	}

	if (off <= 0)
		return beg;



	while (realoff > 0) {
		p = p->post;
		realoff--;
	}
	//printf("FindByOff\n");
	return p;
}

cdlink *FindByKey(cdlink * beg, data_t key)
{
	cdlink *p = beg->post;

	if (NULL == beg) {
		printf("Error: illeagel cdlink pionter\n");
		return NULL;
	}

	if (beg->data == key)
		return beg;

	while (p != beg) {
		if (p->data == key)
			return p;

		p = p->post;
	}

	return NULL;
}



int Insert(cdlink * pos, data_t val)
{
	cdlink *tar = NULL;

	if (NULL == pos) {
		fprintf(stderr, "Error: illeagel address\n");
		return -1;
	}

	/*initailize target node */
	tar = (cdlink *) malloc(sizeof(cdlink));
	if (NULL == tar)
		return -1;
	tar->data = val;

	/*Insert node operation */
	tar->post = pos->post;
	pos->post = tar;
	tar->pre = pos;

	return 0;
}

int InsertAtOff(cdlink * beg, offset_t off, data_t val)
{
	cdlink *pos = FindByOff(beg, off);


	if (pos == NULL)
		return -1;

	if (-1 == Insert(pos, val))
		return -1;

	return 0;
}

int InsertByKey(cdlink * beg, data_t key, data_t val)
{
	cdlink *pos = FindByKey(beg, key);

	if (NULL == pos)
		return -1;

	if (-1 == Insert(pos, val))
		return -1;

	return 0;
}

int Change(cdlink * pos, data_t val)
{
	if (NULL == pos)
		return -1;

	pos->data = val;

	return 0;
}

/*
 * Alter a node's data by offset.
 */
int ChangeAtOff(cdlink * beg, offset_t off, data_t val)
{
	cdlink *pos = FindByOff(beg, off);

	if (NULL == pos)
		return -1;

	if (-1 == Change(pos, val))
		return -1;

	return 0;
}

/*
 *
 * Alter a node's data by Key.
 *
 */
int ChangeByKey(cdlink * beg, data_t key, data_t val)
{
	cdlink *pos = FindByKey(beg, key);

	if (NULL == pos)
		return -1;

	if (-1 == Change(pos, val))
		return -1;

	return 0;
}

/*
 * Print all the nodes in a link,which started at pos; 
 */
void Display(cdlink * pos)
{
	cdlink *p = pos->post;

	putchar(10);

	if (NULL == pos)
		printf("Display error!\n");

	if (NULL == p) {
		printf("p->data : %d\n", p->data);
		return;
	}

	while (p != pos) {
		printf("p->data : %d\n", p->data);
		p = p->post;
	}
}

/*
 *
 * Delete a node by it's offset.
 */
int DeleteByOff(cdlink * beg, offset_t off)
{
	cdlink *pos = FindByOff(beg, off);

	if (NULL == pos)
		return -1;

	Free(pos);

	return 0;
}


/*
 *
 *Delete a node by key(ptr->data).
 */
int DeleteByKey(cdlink * beg, data_t key)
{
	cdlink *pos = FindByKey(beg, key);

	if (NULL == pos)
		return -1;

	Free(pos);

	return 0;
}

/*
 * Warning:
 *    when you free() a node, break the link which poionted at it first!
 */
void FreeALL(cdlink * pos)
{
	cdlink *tmp = pos;

	pos = pos->post;

	while (tmp != pos) {
		Free(tmp);
		tmp = pos;
		pos = pos->post;
	}
	printf("done\n");
}

/*
 * Warning: 
 * 		Before you free() a node, please break the link poionted to it firstly.
 * 
 */
void Free(cdlink * tmp)
{
	tmp->pre->post = tmp->post;
	tmp->post->pre = tmp->pre;

	free(tmp);
}

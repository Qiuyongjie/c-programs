#include "../include/memtype.h"

mlink *Init()
{
	mlink *head = (mlink *) malloc(sizeof(mlink));

	if (NULL == head) {
		perror("Init :malloc");
		return NULL;
	}

	head->size = 0;
	head->addr = NULL;
	head->pre = NULL;
	head->next = NULL;
	head->id = -1;



	return head;
}

mlink *FindById(mlink * h, id_tm id)
{
	mlink *p = h;

	if (NULL == h) {
		fprintf(stderr, "FindById error! (invalid node)\n");
		return NULL;
	}

	while (p->next != NULL) {
		if (p->id == id)
			return p;

		p = p->next;
	}

	return NULL;
}

mlink *FindBySize(mlink * h, mem_t sz)
{
	mlink *p = h;

	if (NULL == h) {
		fprintf(stderr, "FindById error! (invalid node)\n");
		return NULL;
	}

	while (p->next != NULL) {
		if (p->size == sz)
			return p;

		p = p->next;
	}

	return NULL;
}

mlink *FindByoff(mlink * h, offset_t off)
{
	mlink *p = h;

	if (NULL == h)
		return NULL;

	while (p->next != NULL) {
		if (off--)
			return p;
		p = p->next;
	}

	return NULL;
}


int Insert(mlink * pos, id_tm id)
{
	mlink *p = (mlink *) malloc(sizeof(mlink));

	if (NULL == p) {
		perror("Insert: malloc");
		return -1;
	}

	p->addr = NULL;
	p->size = 0;
	p->id = id;
	p->pre = pos;
	p->next = pos->next;

	if (pos->next != NULL)
		pos->next->pre = p;

	pos->next = p;

	return 0;
}

int InsertById(mlink * h, id_tm key, id_tm nid)
{
	mlink *where = h;

	if (NULL == h)
		return -1;

	if (NULL == (where = FindById(where, key)))
		return -1;

	if (-1 == Insert(where, nid))
		return -1;

	return 0;
}

int InsertByoff(mlink * h, offset_t off, id_tm id)
{
	mlink *whr = h;

	if (NULL == h)
		return -1;

	if (off > Count(whr))
		return -1;

	if (NULL == (whr = FindByoff(whr, off)))
		return -1;

	if (-1 == (Insert(whr, id)))
		return -1;

	return 0;
}

int Change(mlink * whr, mem_t sz, maddr_t * addr)
{
	if (NULL == whr || sz < 0)
		return -1;

	whr->size = sz;
	whr->addr = addr;

	return 0;
}

int ChangeByoff(mlink * h, offset_t off, mem_t sz, maddr_t * addr)
{
	mlink *p = h;

	if (NULL == h || off > Count(h) || off < 0 || sz < 0)
		return -1;

	if (NULL == (p = FindByoff(p, off)))
		return -1;

	if (-1 == Change(p, sz, addr))
		return -1;

	return 0;
}

int ChangeById(mlink * h, id_tm who, mem_t sz, maddr_t * addr)
{
	mlink *p = h;

	if (NULL == h || sz < 0)
		return -1;

	if (NULL == (p = FindById(p, who)))
		return -1;

	if (-1 == Change(p, sz, addr))
		return -1;

	return 0;
}

int DeletNode(mlink * whr)
{
	mlink *p = whr;
	if (NULL != whr->addr) {
		printf("Memory in use!\n");
		return -1;
	}

	if (p == NULL)
		return 0;

	if (NULL == p->pre || NULL == p->next) {
		free(p);
		return 0;
	}
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(whr);

	return 0;

}

int DeletAll(mlink * h)
{
	mlink *p = h;

	while (h != NULL) {
		h = h->next;
		DeletNode(p);
		p = h;
	}

	return 0;
}



int Count(mlink * h)
{
	int num = 1;
	mlink *nxt = h;

	if (NULL == nxt)
		return 0;

	while (NULL != nxt->next) {
		num++;
		nxt = nxt->next;
	}

	return num;
}

void PrintMem(mlink * p)
{
	if (p == NULL)
		return;
	printf("mem id: %d\n  at : %p\n", p->id, p);
	printf("\taddr: %p\n", p->addr);
	printf("\tsize: %d\n", p->size);
	printf("\tpre:  %p\n", p->pre);
	printf("\tnext: %p\n", p->next);
}

void PrintAll(mlink * h)
{
	mlink *p = h;
	puts("====== Memory info =======(You)\n");
	while (NULL != p) {
		PrintMem(p);
		p = p->next;
	}
	puts("++++++++++++++++++++++++++++++\n");
}

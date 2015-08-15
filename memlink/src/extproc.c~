

#include "../include/extproc.h"

mlink *ext_Init(void)
{
	mlink *ret = Init();
	//int  = getId();
	if (NULL == ret)
		return NULL;

	if (NULL == (ret->addr = myalloc()))
		return NULL;

	ret->id = 0;
	ret->size = sizeof(ret->addr);

	return ret;
}

maddr_t *myalloc(void)
{
	int msz = rand() % MAXMEM;
	maddr_t *addr = (maddr_t *) malloc(msz);

	if (NULL == addr) {
		perror("myalloc: malloc");
		return NULL;
	}

	return addr;
}

maddr_t *mynalloc(mem_t sz)
{
	maddr_t *addr = NULL;
	if (sz <= 0)
		return NULL;

	addr = (maddr_t *) malloc(sz);
	if (NULL == addr)
		return NULL;

	//init 
	memset(addr, 0, sizeof(addr));

	return addr;
}


int ext_Insert(mlink * whr, mem_t sz)
{
	int id = getId();
	maddr_t *addr = NULL;

	if (NULL == whr || sz <= 0)
		return -1;

	addr = mynalloc(sz);
	if (NULL == addr)
		return -1;

	if (-1 == Insert(whr, id)) {
		free(addr);
		return -1;
	}

	whr->next->addr = addr;
	whr->next->size = sz;

	return 0;
}

int ext_InsertDefault(mlink * h, mem_t sz)
{
	maddr_t *addr = NULL;

	if (NULL == h || sz <= 0)
		return -1;
	if (-1 == ext_Insert(h, sz))
		return -1;

	return 0;
}

int ext_Free(mlink * whr)
{
	if (NULL == whr)
		return 0;

	free(whr->addr);
	whr->addr = NULL;

	return 0;
}

int ext_FreeAll(mlink * h)
{
	mlink *p = h;
	mlink *q = h;
	while (p != NULL) {
		p = p->next;
		ext_Free(q);
		q = p;
	}

	if (-1 == DeletAll(h))
		return -1;

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "type.h"


dlink *Init(void)
{
	return NULL;
}

void Display(dlink *s)
{
	dlink *p = s;

	putchar(10);
	
	while (NULL != p)
	{
		printf("p->data ： %d\n", p->data);
		p = p->post; 
	}
	
	putchar(10);
}

void Free(dlink *s)
{
	dlink *p = s;
	while (NULL != s)
	{
		s = s->post;
		free(p);
		p = s;
	}
	printf("done\n");
}

dlink *Insert(dlink *s, data_t val)
{
	dlink *p = (dlink *)malloc(sizeof(dlink));
	p->data = val;
	p->pre = NULL;
	if (NULL == p)
		return s;

	if (NULL == s)
	{
		p->pre = NULL;
		p->post = s;
	}
	else
	{
		s->pre = p;
		p->post = s;
	}

	return p;
}

dlink *FindOffset(dlink *s, offset_t off)
{
	 dlink *pos = s;
	
	 if (off < 0)
		 return NULL;

	 while ( pos != NULL )
	 {
		if (off == 0)
			return pos;
		
		off --;
		pos = pos->post;
	 }

	 return pos;
}

dlink *FindData(dlink *s, data_t val)
{
	 dlink *pos = s;

	 while ( pos != NULL )
	 {
		if (pos->data == val)
			return pos;

		pos = pos->post;
	 }

	 return pos;
}

int ChangeByOff(dlink *s, offset_t off, data_t val)
{
	dlink *offp = FindOffset(s, off);

	if (NULL == offp)
	{
		printf("offp is NULL\n");
		return -1;
	}
	if (Change(offp, val) == -1)
		return -1;

	return 0;
}

int ChangeByVal(dlink *s, data_t old, data_t ud)
{
	dlink *offp = FindData(s,old);

	if (NULL == offp)
		return -1;

	if (Change(offp, ud) == -1)
		return -1;

	return 0;
}

int Change(dlink *off, data_t val)
{
	if (NULL == off)
		return -1;

	off->data = val;

	return 0;
}

dlink *FindTail(dlink *s)
{
	dlink *p = s;

	if (NULL == p)
		return NULL;

	while (NULL != p->post)
	{
		p = p-> post;
	}

	return p;
}


dlink *Reverse(dlink *s)
{
	dlink *p = s;
	dlink *m = NULL;
	m->pre = NULL;

	p = FindTail(p);
	
	if (NULL == p)
		return s;

	s = p;
	m = p;
	while (NULL != m->pre)
	{
		p = p->pre;

	}
	return s;
}

int DeleteByOff(dlink *s, offset_t off)
{
	dlink *p = s;

	p = FindOffset(p, off);
	
	if (NULL == p)
		return -1;

	p->pre->post = p->post;
	p->post->pre = p->pre;

	free(p);

	return 0;
}

int DeleteByVal(dlink *s, data_t val)
{
	dlink *p = s;

	p = FindData(p, val);
	
	if (NULL == p)
		return -1;

	p->pre->post = p->post;
	p->post->pre = p->pre;

	free(p);

	return 0;
}


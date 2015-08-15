#ifndef __LINK_H__
#define __LINK_H__

#include<stdio.h>
#include<stdlib.h>
typedef int data_t;
typedef struct link LINK;

struct link
{
	data_t data;
	LINK *next;
};


int IsEmpty(LINK *head)
{
	return head->next == NULL;
}

LINK *Init_link(void)
{
	LINK *head = (LINK *)malloc(sizeof(LINK));

	if (NULL == head)
		return NULL;

	head->next = NULL;

	return head;
}

LINK *Seek_parent(LINK *head, int offset)
{
	LINK *tmp = head;
	if (IsEmpty(tmp) != 0)
		return NULL;

	if(offset < 1)
	{
		return NULL;
	}

	while (tmp != NULL)
	{
		if(offset == 1)
			return tmp;
	
		tmp = tmp->next;
		offset--;
	}
	
	return NULL;
}

int Insert_atoff(LINK *off,data_t val)
{
	LINK *q = (LINK *)malloc(sizeof(LINK));

	if (NULL == q || NULL == off)
		return -1;

	q->data = val;
	q->next = off->next;
	off->next = q;

	return 0;
}

int Insert_link(LINK *head, int offset, data_t val)
{
	LINK *tmp = Seek_parent(head, offset);
	
	if(NULL == tmp)
		return -1;

	if(Insert_atoff(tmp, val) == -1)
		return -1;

	return 0;
}



int Change_link(LINK *head, int offset, data_t val)
{
	LINK *tmp = Seek_parent(head, offset);
	
	if (NULL == tmp)
		return -1;
	
	tmp = tmp->next;
	if (NULL == tmp)
		return -1;
	if (!Change_link_off(tmp, val))
		return -1;

	return 0;
}

int Change_link_off(LINK *off, data_t val)
{
	if (NULL == off)
		return -1;
	off->data = val;

	return 0;
}


void Free_link(LINK *head)
{
	LINK *p = head;
	head = head->next;
	while(head != NULL)
	{
		free(p);
		p = head;
		head = head->next;
	}
}

void Display(LINK *head)
{
	LINK *tmp = head;

	while (tmp != NULL){
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}

	putchar(10);
}

int Insert_tail(LINK *head, data_t val)
{
	LINK *tail = head;
	LINK *q = (LINK *)malloc(sizeof(LINK));

	if (NULL == q)
		return -1;

	q->data = val;
	q->next = NULL;

	while (tail->next != NULL)
		tail = tail->next;

	tail->next = q;
	
	return 0;
}


#endif

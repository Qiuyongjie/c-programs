#include  <stdlib.h>
#include   "common.h"

LINK* Init_link(void)
{
	LINK *head = (LINK*)malloc(sizeof(LINK));

	if (NULL == head)
	{
		perror("malloc");
		return NULL;
	}
	
	//set the ptr 
	head->next = NULL;

	return head;
}

int Free_link(LINK *nxt)
{
	LINK *ptr;
	
	if (NULL == nxt)
		return 0;

	while( NULL !=(ptr = nxt))
	{
		nxt = nxt->next;
		free(ptr);
		if (NULL != ptr)
			return -1;
	}
	
	return 0;
}

int Free_head(LINK *head)
{
	if (NULL != head->next)
		if (!Free_link(head->next))	{/*true: Free ok*/
			printf("error occurred! while attempted to release the link");
			return -1;
		}
	if (head != NULL)
		free(head);
	head = NULL;
	
	return 0;
}

int Insert_back(LINK *head,data_t val)
{
	LINK *p = head;
	LINK *q ;
	while (p->next != NULL)
	{
		p = p->next;
	}

	if ((q = (LINK *)malloc( sizeof(LINK))) == NULL){
		printf("error while malloc\n");
		return -1;
	}

	q->data = val;
	q->next = NULL;
	p->next = q;

	return 0;
}
LINK *Seek_parent_byVal(LINK *head, data_t val)
{
	LINK *ptr = head;

	while (NULL != ptr)
	{
		if (ptr->data == val)
			return ptr;
		ptr = ptr->next;
	}

	return NULL;
}

LINK *Seek_parent(LINK *head,int offset)
{
	LINK *ptr = head;
	if(offset <= 0)
		return NULL;
	 
	while (NULL != ptr)
	{
		if(offset == 0)
			return ptr;
		ptr = ptr->next;
		offset --;
	}

	return NULL;
}

int Insert_atoff(LINK *off, data_t val)
{
	LINK *p = (LINK *)malloc(sizeof(LINK));
	LINK *q = off;
	if (NULL == p)
	{
		perror("malloc");
		return -1;
	}
	

	if( NULL == q){
		free(q);
		return -1;
	}
	p->data = val;
	p->next = NULL;

	p->next = q->next;
	q->next = p;

	return 0;
}
int Insert_atoff_val(LINK *head,int offset,data_t val)
{
	LINK *p = Seek_parent(head,offset - 1);
	if (Insert_atoff(p, val) == -1)
		return -1;

	return 0;
}

int Change_atoff_val(LINK *head, int offset, data_t val)
{
	LINK *p = Seek_parent(head,offset-1);
	if (Change_atoff(p, val) == -1)
		return -1;

	return 0;
}

int Change_atoff(LINK *off, data_t val)
{
	if (NULL == off)
		return -1;
	
	off->data = val;
	
	return 0;
}

int Delete_attoff_off(LINK *head, int offset)
{
	LINK *p = head;
	LINK *q = NULL;
	LINK *ptr = Seek_parent(p, offset-1);//the former
		
	if (NULL == ptr){
		printf("Out of range!\n");
		return -1;
	}
	q = ptr->next;
	if (NULL == q)
		return 0;
	
	if (Delete_attoff(ptr, q) != 0)
		return -1;
	
	return 0;
}

int Delete_attoff(LINK *p,LINK *q)
{
	if(NULL == p )
		return 0;
	if (q == NULL)
		return 0;
	p->next = q->next;
	free(q);

	return 0;
}
void Dispaly(LINK *head)
{
	LINK *ptr = head;
	
	while (NULL != ptr)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	
	putchar(10);
}






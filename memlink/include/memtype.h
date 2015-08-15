#ifndef __MEMTYPE_H__
#define __MEMTYPE_H__
#include <stdio.h>
#include <stdlib.h>
#define MAXIDS 1000000;
#define MAXMEM 1024;

typedef void maddr_t;		/*memory address */
typedef struct memory_record mlink;	/* the struct of memory records. */
typedef int mem_t;		/* the size of memory each block */
typedef int id_tm;		/*records id_tm */
typedef int offset_t;

struct memory_record {
	maddr_t *addr;
	mem_t size;
	id_tm id;
	mlink *pre;
	mlink *next;
};
mlink *Init(void);

mlink *FindById(mlink * h, id_tm id);
mlink *FindBySize(mlink * h, mem_t sz);
mlink *FindByoff(mlink * h, offset_t whr);

int Insert(mlink * whr, id_tm id);
int InsertById(mlink * h, id_tm key, id_tm nid);
int InsertByoff(mlink * h, offset_t off, id_tm);

int Change(mlink * whr, mem_t sz, maddr_t * addr);
int ChangeByoff(mlink *, offset_t, mem_t, maddr_t *);
int ChangeById(mlink *, id_tm, mem_t, maddr_t *);

int DeletNode(mlink * whr);	/*only free the node's space */
int DeletAll(mlink * head);

/* Print the specific memory info.
 */
void PrintMem(mlink * ptr);

/* Print all the memory info.
 */
void PrintAll(mlink * h);

/* Count nodes include head.
 */
int Count(mlink * h);


#endif

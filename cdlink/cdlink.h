#ifndef __CDLINK_H__
#define __CDLINK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct cdlink cdlink;
typedef int data_t;
typedef int offset_t;

struct cdlink {
	data_t data;
	cdlink *pre;
	cdlink *post;
};

cdlink *Init(data_t val);
void Free(cdlink * pos);
void FreeALL(cdlink * pos);
int Count(cdlink * pos);	// 0<= error
int Insert(cdlink * pos, data_t val);
int InsertAtOff(cdlink * beg, offset_t off, data_t val);
int InsertByKey(cdlink * beg, data_t key, data_t val);
int Change(cdlink * pos, data_t val);
int ChangeAtOff(cdlink * beg, offset_t off, data_t val);
int ChangeByKey(cdlink * beg, data_t key, data_t val);
int DeleteByOff(cdlink * beg, offset_t off);
int DeleteByKey(cdlink * beg, data_t key);
cdlink *FindByOff(cdlink * beg, offset_t off);
cdlink *FindByKey(cdlink * beg, data_t key);

#endif

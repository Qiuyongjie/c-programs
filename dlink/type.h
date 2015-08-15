
#ifndef __TYPE_H__
#define __TYPE_H__

typedef struct dlink dlink;
typedef int data_t;
typedef int offset_t;
struct dlink{
	data_t data;
	dlink *pre;
	dlink *post;
};

dlink *Init(void);
void Display(dlink *s);
void Free(dlink *s);
dlink *Insert(dlink *s, data_t val);
dlink *FindOffset(dlink *s, offset_t off);
dlink *FindData(dlink *s, data_t val);
int ChangeByOff(dlink *s, offset_t off, data_t val);
int ChangeByVal(dlink *s, data_t old, data_t ud);
int Change(dlink *off, data_t val);
int DeleteByOff(dlink *s, offset_t off);
int DeleteByVal(dlink *s, data_t val);
#endif

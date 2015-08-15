#ifndef   __COMMON_H__
#define   __COMMON_H__
#include   <stdio.h>
#include   "type.h"

LINK* Init_link(void);
int Free_link(LINK*);
int Free_head(LINK*);
int Insert_back(LINK *, data_t);
LINK *Seek_parent(LINK *, int);
LINK *Seek_parent_byVal(LINK *, data_t);
int Insert_atoff(LINK *, data_t);
int Insert_atoff_val(LINK *, int, data_t); //recommended
int Change_atoff_val(LINK *, int, data_t); //also recommended
int Change_atoff(LINK *, data_t);// ..
int Delete_attoff(LINK *,LINK *);
int Delete_attoff_off(LINK *, int);
void Dispaly(LINK *);
#endif  

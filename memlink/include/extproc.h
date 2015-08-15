#ifndef __EXTPROC_H__
#define __EXTPROC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "idgen.h"
#include "memtype.h"

#define RAND (rand()%MAXMEM)
maddr_t *myalloc(void);
maddr_t *mynalloc(mem_t);
int ext_Insert(mlink *, mem_t);
int ext_InsertDefault(mlink *, mem_t);
int ext_Free(mlink *);
int ext_FreeAll(mlink *);
mlink *ext_Init(void);


#endif

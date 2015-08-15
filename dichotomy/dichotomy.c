




#include <stdio.h>
#define MAXSZ 8

int *dictchotomy(int *addr, int val, int s, int e)
{
	if (addr == NULL)
		return NULL;
	//if (val < addr[s] || val > addr[e])
	//	return NULL;
	
	int  mid = (s + e) / 2;
	
	if (mid == s || e == mid) 
	{
		if (addr[s] == val)
			return &addr[s];
		else if (addr[e] == val)
			return &addr[e];
		else
			return NULL;
	}
	
	
	if (addr[mid] > val)
		return dictchotomy(addr,val,s,mid);
	if (addr[mid] < val)
		return dictchotomy(addr,val,mid,e);
	else
		return &addr[mid];
}
void init(int *array)
{
	int i = 0;
	while (i < MAXSZ) {
		array[i] = i;
		printf("array[%d] = %d, at %p\n", i, array[i], &array[i]);
		i++;
	}
}

int main(int argc, const char *argv[])
{
	int i = 0;
	int val = 0;
	int array[MAXSZ];
	int *addr = NULL;
	init(array);

	putchar(10);
	
	i = -1;
	val = i;

	while(i <= MAXSZ){
		addr = dictchotomy(array, val, 0, MAXSZ - 1);
		if (NULL == addr) {
			puts("not found\n");
		}
		else
			printf("found: %d, at %d (%p)\n", *addr, addr - array, addr);

		i++;
		val = i;
	}

	return 0;
}

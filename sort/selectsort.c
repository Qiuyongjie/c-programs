


#include <stdio.h>

void print(int *addr, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
		printf("array[%d] = %d, at %p\n", addr[i], i, &addr[i]);
	}
}

void swap(int *p, int *q)
{
	*p ^= *q;
	*q ^= *p;
	*p ^= *q;
	printf("swap ..\n");
}

int Bubble_sort(int *addr, int sz)
{
	int i = 0;
	int j = 0;

	for (; i < sz - 1; i++)
	{
			for (j = 0; j < sz - i -1 ; j++)
			{
				if (addr[i] < addr[j])
				{
					swap(&addr[i], &addr[j]);
				}
			}
	}
}

int Select_sort(int *addr, int sz)
{
	int i = 0;
	int j = 0;
	int *max = NULL;
	for (i; i < sz - 1; i++)
	{
		max = &addr[i];

		for (j = i + 1; j < sz - 1 ; j++)
		{
			if (addr[j] > *max)				
				max = &addr[j];
		}

		if (max != &addr[i])
			swap(max, &addr[i]);
	}
}

int main(int argc, const char *argv[])
{
	int array[] = {5,2,8,3,6,1,7,4,9,10};

#if 0
	Bubble_sort(array, 10);
#endif
#if 1
	Select_sort(array, 10);
#endif
	print(array, 10);
	return 0;
}




#include <stdio.h>

void print(int *addr, int sz)
{
	int i;
	for (i = 0; i < sz; i++)
	{
	//	printf("array[%d] = %d, at %p\n", addr[i], i, &addr[i]);
		printf("%d,",addr[i]);
	}
	putchar(10);
}

static inline void swap(int *p, int *q)
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
				max = & addr[j];
		}

		if (max != &addr[i])
			swap(max, &addr[i]);
	}
}


int Quick_sort(int *addr, int start, int end)
{
	if (start >= end)
		return 0;
	int low  = start;
	int high = end;
	int key  = addr[start];

	while (start < end)
	{
		while(start < end && addr[end] >= key)
		{
			end--;
		}
		addr[start] = addr[end];

		while(start < end && addr[start] <= key)
		{
			start++;
		}
		addr[end] = addr[start];
	}
	addr[start] = key;
	Quick_sort(addr, low, start - 1);
	Quick_sort(addr,start + 1, high);
	return 0;
}

int Insert_sort(int *a,int n)
{
	int i, j;

	for (i = 1 ; i < n; i++)
		for (j = i - 1; j >= 0 && a[j] > a[j+1]; j--)
			swap(&a[j],&a[j+1]);
	return 0;
}
int main(int argc, const char *argv[])
{
	int array[] = {5,2,8,3,6,1,7,4,9,10};

#if 0
	Bubble_sort(array, 10);
#endif
#if 0
	Select_sort(array, 10);
#endif
#if 0
	print(array, 10);
	Quick_sort(array, 0,9);
#endif
#if 1
	Insert_sort(array,10);
#endif
	print(array, 10);
	return 0;
}

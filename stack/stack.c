


#include <stdio.h>
#include <stdlib.h>
#define LEN 128
typedef int data_t;
typedef struct stack STACK;

struct stack{
	data_t data[LEN];
	int top;
};

STACK *init(void)
{
	STACK *s = (STACK *)malloc(sizeof(STACK));

	if (NULL == s)
	{
		perror("malloc");
		return NULL;
	}
	s->top = -1;

	return s;
}

int isEmpty(STACK *s)
{
	return s->top == -1;
}


int isFull(STACK *s)
{
	return s->top == LEN - 1;
}

/*return :
 * failed : NULL
 * */
data_t getStackTop(STACK *s)
{
	return (s->data[s->top]);
}

int push(STACK *s, data_t val)
{
	s->data[++(s->top)] = val;

	return 0;
}

int pop(STACK *s)
{
	s->top --;

	return 0;
}

void makeClean(STACK *s)
{
	if (s != NULL)
		s->top = -1;
}
int main(int argc, const char *argv[])
{
	int i = 0;
	STACK *s = init();
	
	if (NULL == s){
		printf("error\n");
		return -1;
	}
	while (isFull(s) == 0)
	{
		 if (push(s, i++) != 0)
			 printf(" 2nd error\n");
	}

	
	while (isEmpty(s) != 1)
	{
		printf("%d\n", getStackTop(s));
//		printf("EMPTY: %d\n",isEmpty(s));
		pop(s);
	}


	free(s);
	return 0;
}

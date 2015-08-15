



#include <stdio.h>
#include <stdlib.h>

#define LEN 128
typedef int data_t;
typedef struct queue Q;

struct queue {
	data_t data[LEN];
	int front;
	int rear;
};

Q *init(void)
{
	Q *q = (Q *) malloc(sizeof(Q));

	if (NULL == q) {
		perror("Init : malloc");
		return NULL;
	}

	q->front = q->rear = 0;
	q->data[0] = -1;

	return q;
}

int isEmpty(Q * q)
{
	return q->front == q->rear;
}

int isFull(Q * q)
{
	return (q->rear + 1) % LEN == q->front;
}

int In(Q * q, data_t val)
{
	if (NULL == q)
		return -1;

	q->rear = (q->rear + 1) % LEN;
	q->data[q->rear] = val;

	return 0;
}

int Out(Q * q)
{
	q->front = (q->front + 1) % LEN;
	return q->data[q->front];
}

data_t getFront(Q * q)
{
	return q->data[q->front];
}

int main(int argc, const char *argv[])
{
	Q *q = init();

	int i = 0;
	if (NULL == q)
		return -1;

	while (!isFull(q)) {
		In(q, i++);
	}

	printf("Out: %d\n", Out(q));

	do
	{
		printf("%d\n", Out(q));
	}while(!isEmpty(q));
	
	free(q);
	return 0;
}

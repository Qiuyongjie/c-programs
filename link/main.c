#include   <stdio.h>
#include   "common.h"
int main()
{
	LINK *head = Init_link();
	int i = 20;
	LINK *ptr = NULL;


	if (NULL == head)
	{
		printf("error init\n");
		return -1;
	}
	head->data = 0;

	while (i > 0)
	{
		if (Insert_back(head, i--) != 0)
		{
			printf("error while Insert_back\n");
			Free_head(head);
			return -1;
		}
	}
	Dispaly(head);
	putchar(10);

	
	
	if (Insert_atoff_val(head, 10, 100) == -1)
		printf("Insert_atoff_val error\n");
	Dispaly(head);

	putchar(10);

	if (Change_atoff_val(head, 10, 1000) == -1)
		printf("Change_atoff_val error\n");
	Dispaly(head);

	putchar(10);

	if (Delete_attoff_off(head,10) == -1)
		printf("Delete_attoff_off error\n");
	Dispaly(head);



	if (Free_head(head) != 0)
		return -1;

	return 0;
}

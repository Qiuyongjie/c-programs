#include <stdio.h>
#include "link.h"
int main(int argc, const char *argv[])
{
	LINK *head = Init_link();
	int i = 0;
	head->data = 0;
	

	for (i = 1; i < 10; i++)
	{
		if (Insert_tail(head, i) == -1)
			return -1;
	}
	Display(head);
		
	Insert_link(head, 5, 1001);
	Display(head);

	Change_link(head, 1, 1002);
	Display(head);
	return 0;


}

#include "../includes/push_swap.h"

void print(t_frame *frame, char stack_name)
{
	t_struct *tmp;

	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
		tmp = frame->stack_b;
	while (tmp->next != NULL)
	{
		printf("%li\n", tmp->num);
		tmp = tmp->next;
	}
	printf("%li\n", tmp->num);
}

#include "../includes/push_swap.h"

void	first_node(t_frame *frame, t_struct *tmpA, long int num)
{
	frame->stack_a = (t_struct *)malloc(sizeof (t_struct));
	tmpA = frame->stack_a;
	tmpA->num = num;
	tmpA->next = NULL;
	tmpA->previous = NULL;
}

void	add_to_stack(t_frame *frame, char stack_name, long int num)
{
	t_struct	*tmpA;
	t_struct	*last_elem;

	frame->stack_len++;
	if (frame->stack_a == NULL)
		first_node(frame, tmpA, num);
	else
	{
		tmpA = frame->stack_a;
		while (tmpA->next != NULL)
		{
			last_elem = tmpA;
			tmpA = tmpA->next;
			tmpA->previous = last_elem;
		}
		tmpA->next = (t_struct *) malloc(sizeof(t_struct));
		last_elem = tmpA;
		tmpA = tmpA->next;
		tmpA->previous = last_elem;
		tmpA->num = num;
		tmpA->next = NULL;
		frame->tail = tmpA;
	}
}

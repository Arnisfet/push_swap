#include "../../includes/push_swap.h"

void	do_rb(t_frame *frame)
{
	t_struct	*tmp;
	t_struct	*another;

	tmp = frame->stack_b;
	frame->tail_b->next = tmp;
	tmp->previous = frame->tail_b;
	another = tmp->next;
//	printf("%li, another\n", another->num);
	tmp->next = NULL;
	another->previous = NULL;
	frame->stack_b = another;
	frame->tail_b = tmp;
//	frame->stack_a = frame->stack_a->next;
	write(1, "rb\n", 3);
}
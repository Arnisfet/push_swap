#include "../../includes/push_swap.h"

void	do_rrb(t_frame *frame)
{
	t_struct *tmp;
	t_struct *another;

	tmp = frame->tail_b;
	tmp->next = frame->stack_b;
//	tmp->previous = NULL;
	frame->stack_b->previous= tmp;
	another = tmp;
	tmp = tmp->previous;
	frame->tail_b =tmp;
	tmp->next = NULL;
	frame->stack_b = another;

	write(1, "rrb\n", 4);
}
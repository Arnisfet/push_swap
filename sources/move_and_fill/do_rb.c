#include "../../includes/push_swap.h"

void	do_rb(t_frame *frame)
{
	t_struct	*tmp;
	t_struct	*another;

	tmp = frame->stack_b;
	frame->tail_b->next = tmp;
	tmp->previous = frame->tail_b;
	another = tmp->next;
	tmp->next = NULL;
	another->previous = NULL;
	frame->stack_b = another;
	frame->tail_b = tmp;
	write(1, "rb\n", 3);
}

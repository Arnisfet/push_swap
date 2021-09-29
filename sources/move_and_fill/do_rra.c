#include "../../includes/push_swap.h"
/* Алгоритм:
 * 1) поменять местами первые два числа в стеке
 * 2) поменять местами первое и последнее число в стеке */

void	do_rra(t_frame *frame)
{
	t_struct	*tmp;
	t_struct	*another;

	tmp = frame->tail;
	tmp->next = frame->stack_a;
	frame->stack_a->previous = tmp;
	another = tmp;
	tmp = tmp->previous;
	frame->tail = tmp;
	tmp->next = NULL;
	frame->stack_a = another;
	write(1, "rra\n", 4);
}

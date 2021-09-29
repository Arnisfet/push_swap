#include "../../includes/push_swap.h"

/* Алгоритм:
 * 1) поменять местами последнее и предпоследнее число в стеке
 * 2) поменять местами первое и последнее число в стеке*/

void	do_ra(t_frame *frame)
{
	t_struct	*tmp;
	t_struct	*another;

	tmp = frame->stack_a;
	frame->tail->next = tmp;
	tmp->previous = frame->tail;
	another = tmp->next;
	tmp->next = NULL;
	another->previous = NULL;
	frame->stack_a = another;
	frame->tail = tmp;
	write(1, "ra\n", 3);
}

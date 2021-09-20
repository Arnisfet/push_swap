#include "../../includes/push_swap.h"

/* Алгоритм:
 * 1) поменять местами последнее и предпоследнее число в стеке
 * 2) поменять местами первое и последнее число в стеке*/

void	do_ra(t_frame *frame)
{
	long int tmp;

	tmp = frame->tail->num;
	frame->tail->num = frame->tail->previous->num;
	frame->tail->previous->num = tmp;
	tmp = frame->stack_a->num;
	frame->stack_a->num = frame->tail->num;
	frame->tail->num = tmp;
	write(1, "ra\n", 3);
}

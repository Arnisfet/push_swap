#include "../../includes/push_swap.h"

void	do_rra(t_frame *frame)
{
	long int	first;
	long int	second;

	first = frame->stack_a->num;
	frame->stack_a->num = frame->stack_a->next->num;
	frame->stack_a->next->num = first;
	second = frame->stack_a->num;
	frame->stack_a->num = frame->stack_a->previous->num;
	frame->stack_a->previous->num = second;
	write(1, "rra\n", 4);
}


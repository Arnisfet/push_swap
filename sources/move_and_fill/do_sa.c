#include "../../includes/push_swap.h"

void	do_sa(t_frame *frame)
{
	long int tmp;

	tmp = frame->stack_a->num;
	frame->stack_a->num = frame->stack_a->next->num;
	frame->stack_a->next->num = tmp;
	write(1, "sa\n", 3);
}


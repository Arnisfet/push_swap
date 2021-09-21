#include "../../includes/push_swap.h"

void	do_sb(t_frame *frame)
{
	long int tmp;

	tmp = frame->stack_b->num;
	frame->stack_b->num = frame->stack_b->next->num;
	frame->stack_b->next->num = tmp;
	write(1, "sa\n", 3);
}

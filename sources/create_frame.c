#include "../includes/push_swap.h"

void	create_frame(t_frame *frame)
{
	frame->stack_a->next = NULL;
	frame->stack_b->next = NULL;
	frame->stack_len = 0;
}

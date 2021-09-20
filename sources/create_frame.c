#include "../includes/push_swap.h"

void	create_frame(t_frame *frame)
{
	frame->stack_a = NULL;
	frame->stack_b = NULL;
	frame->stack_len = 0;
	frame->big_move = 0;
	frame->small_move = 0;
	frame->biggest = 0;
	frame->smallest = 0;
}

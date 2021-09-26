#include "../includes/push_swap.h"

void	create_frame(t_frame *frame)
{
	frame->stack_a = NULL;
	frame->stack_b = NULL;
	frame->stack_len = 0;
	frame->big_move_end = 0;
	frame->small_move_end = 0;
	frame->small_move_start = 0;
	frame->big_move_start = 0;
	frame->after_rotate = 0;
	frame->big_flag = 0;
	frame->small_flag = 0;
	frame->biggest = 0;
	frame->smallest = 0;
	frame->median = 0;
	frame->three_quarter = 0;
	frame->quarter = 0;
}

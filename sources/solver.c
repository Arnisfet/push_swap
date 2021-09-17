#include "../includes/push_swap.h"

void	solver(t_frame *frame)
{
	if (frame->stack_len <= 5)
		solve_5_or_less(frame);
}
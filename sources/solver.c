#include "../includes/push_swap.h"

void	solver(t_frame *frame)
{
	if (frame->stack_len <= 5)
		solver_5_or_less(frame);
	else if (frame->stack_len <= 100)
		solve_big_num(frame);
	else
		solve_over_100(frame);
}

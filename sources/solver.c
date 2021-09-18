#include "../includes/push_swap.h"

void	solve_2(t_frame *frame)
{
	if (frame->stack_a->num > frame->stack_a->next->num)
		do_sa(frame);
}

void	solver_5_or_less(t_frame *frame)
{
	if (frame->stack_len == 2)
		solve_2(frame);
}

void	solver(t_frame *frame)
{
	if (frame->stack_len <= 5)
		solver_5_or_less(frame);
}
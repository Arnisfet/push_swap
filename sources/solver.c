#include "../includes/push_swap.h"

void	solve_2(t_frame *frame)
{
	if (frame->stack_a->num > frame->stack_a->next->num)
		do_sa(frame);
}

void	solve_3(t_frame *frame)
{
	t_struct *stack_a;
	t_struct *temp;
	find_biggest(frame, 'a');
	moves_to_end(frame, 'a', 2);
	if (frame->big_move >= 1)
		while (frame->big_move-- > 1)
			do_rra(frame);
		stack_a = frame->stack_a;
		temp = frame->stack_a->next;
		if (stack_a->num > temp->num)
			do_sa(frame);
}

void	solver_5_or_less(t_frame *frame)
{
	if (frame->stack_len == 2)
		solve_2(frame);
	if (frame->stack_len == 3)
		solve_3(frame);
}

void	solver(t_frame *frame)
{
	if (frame->stack_len <= 5)
		solver_5_or_less(frame);
}
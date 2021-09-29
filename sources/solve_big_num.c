#include "../includes/push_swap.h"

void	after_rotate(t_frame *frame)
{
	if (frame->small_flag)
		do_ra(frame);
	if (frame->big_flag || !frame->stack_b)
		frame->after_rotate++;
	reset_moves(frame);
}

void	push_to_stack_a(t_frame *frame)
{
	if (frame->small_move_start > 0)
	{
		while (frame->small_move_start--)
			do_rb(frame);
	}
	else if (frame->small_move_end > 0)
	{
		while (frame->small_move_end--)
			do_rrb(frame);
	}
	else if (frame->big_move_start > 0)
	{
		while (frame->big_move_start--)
			do_rb(frame);
	}
	else if (frame->big_move_end > 0)
	{
		while (frame->big_move_end--)
			do_rrb(frame);
	}
	do_pa(frame);
	after_rotate(frame);
}

void	solve_big_num(t_frame *frame)
{
	int	split;

	split = 1;
	median(frame, 'a');
	while (frame->stack_a)
	{
		push_median(frame, split);
		while (frame->stack_b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->small_move_end >= 0 || frame->big_move_end >= 0
				|| frame->big_move_start >= 0 || frame->small_move_start >= 0)
				push_big_small(frame, frame->stack_b, frame->tail_b);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 3)
			break ;
	}
	print(frame, 'a');
}

void	push_big_small(t_frame *frame, t_struct *stack, t_struct *stack_end)
{
	while (1)
	{
		while (stack != NULL && stack->num != frame->biggest && stack->num
			!= frame->smallest)
			stack = stack->next;
		if (stack->num == frame->biggest || stack->num == frame->smallest)
		{
			push_to_stack_a(frame);
			break ;
		}
		if (stack == stack_end)
			break ;
		else
			stack = frame->stack_b;
	}
}

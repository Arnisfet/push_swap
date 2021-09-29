#include "../includes/push_swap.h"

void	push_first_split(t_frame *frame)
{
	if (frame->stack_b)
	{
		if (frame->stack_b->num > (frame->quarter / 2))
			do_rb(frame);
	}
	do_pb(frame);
}

void	push_second_split(t_frame *frame)
{
	if (frame->stack_b)
	{
		if (frame->stack_b->num > (frame->quarter / 2) * 3)
			do_rb(frame);
	}
	do_pb(frame);
}

void	push_third_split(t_frame *frame)
{
	if (frame->stack_b)
	{
		if (frame->stack_b->num > (frame->quarter / 2) * 5)
			do_rb(frame);
	}
	do_pb(frame);
}

void	push_fourth_split(t_frame *frame)
{
	if (frame->stack_b)
	{
		if (frame->stack_b->num > (frame->quarter / 2) * 7)
			do_rb(frame);
	}
	do_pb(frame);
}

void	push_quartes(t_frame *frame, int split)
{
	t_struct	*begin;
	t_struct	*end;
	int			flag;

	begin = frame->stack_a;
	end = frame->tail;
	flag = 0;
	find_smallest(frame, 'a');
	while (1)
	{
		if (begin == end)
			flag = 1;
		if (split == 1 && begin->num <= frame->quarter)
			push_first_split(frame);
		else if (split == 2 && begin->num > frame->quarter && begin->num <=
															  frame->median)
			push_second_split(frame);
		else if (split == 3 && begin->num > frame->median && begin->num <=
															 frame->three_quarter)
			push_third_split(frame);
		else if (split == 4 && begin->num > frame->three_quarter)
			push_fourth_split(frame);
		else if (split == 4 && begin->num == frame->smallest)
			break ;
		else
			do_ra(frame);
		if (flag == 1)
			break ;
		begin = frame->stack_a;
	}
	reset_moves(frame);
}

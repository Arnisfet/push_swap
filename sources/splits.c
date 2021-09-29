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

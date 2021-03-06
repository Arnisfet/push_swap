#include "../includes/push_swap.h"

void	push_median(t_frame *frame, int split)
{
	t_struct	*begin;
	t_struct	*end;
	int			flag;

	flag = 0;
	begin = frame->stack_a;
	end = frame->tail;
	find_smallest(frame, 'a');
	while (1)
	{
		if (begin == end)
			flag = 1;
		if (split == 1 && begin->num <= frame->median)
			do_pb(frame);
		else if (split == 2 && begin->num > frame->median)
			do_pb(frame);
		else if (begin->num == frame->smallest)
			break ;
		else
			do_ra(frame);
		if (flag == 1)
			break ;
		begin = frame->stack_a;
	}
	reset_moves(frame);
}

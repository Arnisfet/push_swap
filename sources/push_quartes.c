#include "../includes/push_swap.h"

void	loop(t_frame *frame, t_struct *begin, int flag, int split)
{
	t_struct	*end;

	end = frame->tail;
	while (1)
	{
		if (begin == end)
			flag = 1;
		if (split == 1 && begin->num <= frame->quarter)
			push_first_split(frame);
		else if (split == 2 && begin->num > frame->quarter && begin->num
			<= frame->median)
			push_second_split(frame);
		else if (split == 3 && begin->num > frame->median && begin->num
			<= frame->three_quarter)
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
}

void	push_quartes(t_frame *frame, int split)
{
	t_struct	*begin;
	int			flag;

	begin = frame->stack_a;
	flag = 0;
	find_smallest(frame, 'a');
	loop(frame, begin, flag, split);
	reset_moves(frame);
}

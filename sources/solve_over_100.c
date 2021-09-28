#include "../includes/push_swap.h"

void	solve_over_100(t_frame *frame)
{
	int split;

	split = 1;
	median(frame, 'a');
	while (frame->stack_a)
	{
		push_quartes(frame, split);
		while (frame->stack_b)
		{
			find_biggest_smallest(frame, 'b');
			find_moves(frame, 'b');
			if (frame->stack_b && (frame->small_move_end >= 0 ||
				frame->big_move_end	>= 0 ||
				frame->big_move_start >= 0 || frame->small_move_start >= 0))
				push_big_small(frame, frame->stack_b, frame->tail_b);
		}
		while (--frame->after_rotate)
			do_ra(frame);
		split++;
		if (split == 5)
			break ;
	}
}

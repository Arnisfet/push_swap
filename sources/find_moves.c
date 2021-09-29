#include "../includes/push_swap.h"

void	moves_smallest(t_frame *frame, char stack_name)
{
	t_struct	*temp;
	int			flag;

	flag = 1;
	if (stack_name == 'a')
		temp = frame->stack_a;
	else
		temp = frame->stack_b;
	if (temp)
	{
		moves_to_end(frame, stack_name, flag);
		moves_to_start(frame, stack_name, flag);
		if (frame->small_move_start <= frame->small_move_end)
			frame->small_move_end = -1;
		else
			frame->small_move_start = -1;
	}
}

void	moves_biggest(t_frame *frame, char stack_name)
{
	t_struct	*tmp;
	int			flag;

	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
		tmp = frame->stack_b;
	flag = 2;
	if (tmp)
	{
		moves_to_start(frame, stack_name, flag);
		moves_to_end(frame, stack_name, flag);
	}
	if (frame->big_move_start <= frame->big_move_end)
		frame->big_move_end = -1;
	else
		frame->big_move_start = -1;
}

void	find_moves(t_frame *frame, char stack_name)
{
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (frame->big_move_start != -1 && (frame->big_move_start
			>= frame->small_move_start && frame->big_move_start
			>= frame->small_move_end))
		frame->big_move_start = -1;
	else if (frame->big_move_end != -1 && (frame->big_move_end
			>= frame->small_move_start && frame->big_move_end
			>= frame->small_move_end))
		frame->big_move_end = -1;
	else if (frame->small_move_start != -1
		&& (frame->small_move_start >= frame->big_move_start
			 && frame->small_move_start >= frame->big_move_end))
		frame->small_move_start = -1;
	else if (frame->small_move_end != -1
		 && (frame->small_move_end >= frame->big_move_start
			 && frame->small_move_end >= frame->big_move_end))
		frame->small_move_end = -1;
	if (frame->small_move_start != -1 || frame->small_move_end != -1)
		frame->small_flag = 1;
	else if (frame->big_move_start != -1 || frame->big_move_end != -1)
		frame->big_flag = 1;
}

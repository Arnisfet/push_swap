#include "../includes/push_swap.h"

void	moves_to_end(t_frame *frame, char stack_name, int flag)
{
	t_struct	*temp;
	int			element;

	if (stack_name == 'a')
		temp = frame->tail;
	else
		temp = frame->tail_b;
	if (flag == 1)
		element = frame->smallest;
	else
		element = frame->biggest;
	while (temp->num != element)
	{
		if (flag == 1)
			frame->small_move_end++;
		else
			frame->big_move_end++;
		temp = temp->previous;
	}
	if (flag == 1)
		frame->small_move_end++;
	else
		frame->big_move_end++;
}


void	reset_moves(t_frame *frame)
{
	frame->smallest = 0;
	frame->biggest = 0;
	frame->big_move_end = 0;
	frame->small_move_end = 0;
	frame->big_move_start = 0;
	frame->small_move_start = 0;
	frame->small_flag = 0;
	frame->big_flag = 0;
}

void	moves_to_start(t_frame *frame, char stack_name, int flag)
{
	t_struct	*temp;
	int			element;

	if (stack_name == 'a')
		temp = frame->stack_a;
	else
		temp = frame->stack_b;
	if (flag == 1)
		element = frame->smallest;
	else
		element = frame->biggest;
	while (temp->num != element)
	{
		if (flag == 1)
			frame->small_move_start++;
		else
			frame->big_move_start++;
		temp = temp->next;
	}
	if (flag == 1 && temp->num != frame->smallest)
		frame->small_move_start++;
	if (flag == 2 && temp->num != frame->biggest)
		frame->big_move_start++;
}

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
	t_struct *stack;
	if (stack_name == 'a')
		stack = frame->stack_a;
	else
		stack = frame->stack_b;
	moves_smallest(frame, 'b');
	moves_biggest(frame, 'b');
	if (frame->big_move_start != -1 && (frame->big_move_start >=
										frame->small_move_start && frame->big_move_start >= frame->small_move_end))
		frame->big_move_start = -1;
	else if (frame->big_move_end != -1 && (frame->big_move_end >=
										   frame->small_move_start && frame->big_move_end >= frame->small_move_end))
		frame->big_move_end = -1;
	else if (frame->small_move_start != -1 && (frame->small_move_start >= frame->big_move_start &&
											   frame->small_move_start >= frame->big_move_end))
		frame->small_move_start = -1;
	else if (frame->small_move_end != -1 && (frame->small_move_end >= frame->big_move_start &&
											 frame->small_move_end >= frame->big_move_end))
		frame->small_move_end = -1;
	if (frame->small_move_start != -1 || frame->small_move_end != -1)
		frame->small_flag = 1;
	else if (frame->big_move_start != -1 || frame->big_move_end != -1)
		frame->big_flag = 1;
}
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

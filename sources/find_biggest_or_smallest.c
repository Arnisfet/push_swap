#include "../includes/push_swap.h"

void	find_biggest(t_frame *frame, char stack_name)
{
	t_struct *stack;
	t_struct *temp;

	if (stack_name == 'a')
		stack = frame->stack_a;
	else
		stack = frame->stack_b;
	temp = stack;
	frame->biggest = temp->num;
	while (temp->next != NULL)
	{
		if (temp->num > frame->biggest)
			frame->biggest = temp->num;
		temp = temp->next;
	}
	if (temp->num > frame->biggest)
		frame->biggest = temp->num;
}

void	find_smallest(t_frame *frame, char stack_name)
{
	t_struct *stack;
	t_struct *temp;

	if (stack_name == 'a')
		stack = frame->stack_a;
	else
		stack = frame->stack_b;
	temp = stack;
	frame->smallest = temp->num;
	while (temp->next != NULL)
	{
		if (temp->num < frame->smallest)
			frame->smallest = temp->num;
		temp = temp->next;
	}
}

void	find_biggest_smallest(t_frame *frame, char stack_name)
{
	find_biggest(frame, stack_name);
	find_smallest(frame, stack_name);
}
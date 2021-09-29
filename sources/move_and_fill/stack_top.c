#include "../../includes/push_swap.h"

void	stack_del_top(t_frame *frame, char stack_name)
{
	t_struct	*tmp;

	if (stack_name == 'a')
	{
		tmp = frame->stack_a;
		frame->stack_a = frame->stack_a->next;
		free(tmp);
	}
	else
	{
		tmp = frame->stack_b;
		frame->stack_b = frame->stack_b->next;
		free(tmp);
	}
}

void	first_elem(t_frame *frame, t_struct *new_node, long int num)
{
	new_node->num = num;
	new_node->next = NULL;
	new_node->previous = NULL;
	frame->tail_b = new_node;
	frame->stack_b = new_node;
}

void	stack_add_top(t_frame *frame, char stack_name, long int num)
{
	t_struct	*tmp;
	t_struct	*new_node;

	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
		tmp = frame->stack_b;
	if (tmp == NULL)
	{
		new_node = (t_struct *)malloc(sizeof (t_struct));
		first_elem(frame, new_node, num);
	}
	else
	{
		new_node = (t_struct *) malloc(sizeof(t_struct));
		new_node->next = tmp;
		new_node->previous = NULL;
		tmp->previous = new_node;
		new_node->num = num;
		if (stack_name == 'a')
			frame->stack_a = new_node;
		else
			frame->stack_b = new_node;
	}
}

#include "../../includes/push_swap.h"

void	stack_del_top(t_frame *frame, char stack_name)
{
	t_struct *tmp;

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

void	stack_add_top(t_frame *frame, char stack_name, long int num)
{
	t_struct *tmp;
	t_struct *new_node;

	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
		tmp = frame->stack_b;
	if (tmp == NULL)
	{
		tmp = (t_struct *)malloc(sizeof (t_struct));
		tmp->num = num;
		tmp->next = NULL;
		tmp->previous = NULL;
		frame->stack_b = tmp;
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

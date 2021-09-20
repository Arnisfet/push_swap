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

	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
	{
		if (frame->stack_b == NULL)
		{
			frame->stack_b = (t_struct *)malloc(sizeof (t_struct));
			tmp = frame->stack_b;
			tmp->num = num;
			tmp->next = NULL;
			tmp->previous = NULL;
		}
		else
		{
			tmp = (t_struct *) malloc(sizeof(t_struct));
			tmp->next = frame->stack_a;
			tmp->previous = NULL;
			frame->stack_a->previous = tmp;
			tmp->num = num;
			frame->stack_b = tmp;
		}
	}
}
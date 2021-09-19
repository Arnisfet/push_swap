#include "../includes/push_swap.h"

void	moves_to_end(t_frame *frame, char stack_name, int flag)
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
			frame->small_move++;
		else
			frame->big_move++;
		temp = temp->next;
	}
	if (flag == 1)
		frame->small_move = frame->stack_len - frame->small_move++;
	else
		frame->big_move = frame->stack_len - frame->big_move++;
}

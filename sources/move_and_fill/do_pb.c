#include "../../includes/push_swap.h"

void	do_pb(t_frame *frame)
{
	long int temp;

	temp = frame->stack_a->num;
	stack_del_top(frame, 'a');
	stack_add_top(frame, 'b', temp);
	write(1, "pb\n", 3);
}

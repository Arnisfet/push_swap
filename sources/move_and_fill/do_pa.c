#include "../../includes/push_swap.h"

void	do_pa(t_frame *frame)
{
	long int	tmp;

	tmp = frame->stack_b->num;
	stack_del_top(frame, 'b');
	stack_add_top(frame, 'a', tmp);
	write(1, "pa\n", 3);
}

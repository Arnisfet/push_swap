#include "../includes/push_swap.h"

int	sorted(t_frame *frame)
{
	t_srtuct *tmpA;

	tmpA = frame->stack_a;

	while(tmpA->next != NULL)
	{
		if (tmpA->num > tmpA->next->num)
			return (1);
		tmpA = tmpA->next;
	}
	return (0);
}


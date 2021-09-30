#include "../includes/push_swap.h"

void	freed(t_frame *frame)
{
	t_struct	*tmp;
	t_struct	*next_elem;

	tmp = frame->stack_a;
	next_elem = tmp->next;
	while (next_elem != NULL)
	{
		free(tmp);
		tmp = next_elem;
		next_elem = next_elem->next;
	}
	free(tmp);
	tmp = NULL;
	next_elem = NULL;
}

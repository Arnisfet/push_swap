#include "../includes/push_swap.h"

long	*sort_array(long *array, int len)
{
	long	tmp;
	int		i;
	long	*check;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
	check = array;
	return (check);
}

int	find_stack_len(t_frame *frame, char stack_name)
{
	t_struct	*tmp;
	int			len;

	len = 0;
	if (stack_name == 'a')
		tmp = frame->stack_a;
	else
		tmp = frame->stack_b;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	len++;
	return (len);
}

void	find_median(t_frame *frame, t_struct *stack, char stack_name)
{
	long	*array;
	long	*check;
	int		i;
	int		quarter_len;

	i = 0;
	frame->stack_len = find_stack_len(frame, stack_name);
	quarter_len = frame->stack_len / 4;
	array = (long *)malloc(sizeof(long) * (frame->stack_len + 1));
	while (i < frame->stack_len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	check = sort_array(array, frame->stack_len);
	frame->quarter = check[quarter_len];
	frame->median = check[quarter_len * 2];
	frame->three_quarter = check[quarter_len * 3];
	free(check);
}

void	median(t_frame *frame, char stack_name)
{
	t_struct	*stack;

	if (stack_name == 'a')
		stack = frame->stack_a;
	else
		stack = frame->stack_b;
	find_median(frame, stack, stack_name);
}

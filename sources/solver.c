#include "../includes/push_swap.h"

void	solve_2(t_frame *frame)
{
	if (frame->stack_a->num > frame->stack_a->next->num)
		do_sa(frame);
}

void	solve_3(t_frame *frame)
{
	t_struct *stack_a;
	t_struct *temp;
	find_biggest(frame, 'a');
	moves_to_end(frame, 'a', 2);
	if (frame->big_move_end >= 1)
		while (frame->big_move_end-- > 1)
			do_rra(frame);
	stack_a = frame->stack_a;
	temp = frame->stack_a->next;
	if (stack_a->num > temp->num)
		do_sa(frame);
}

void	solve_4(t_frame *frame)
{
	t_struct *tmp;

	tmp = frame->stack_a;
	find_biggest_smallest(frame, 'a');
	while (tmp->num != frame->smallest)
	{
		do_ra(frame);
		tmp = frame->stack_a;
	}
	do_pb(frame);
	solve_3(frame);
	do_pa(frame);
//	print(frame, 'a');
}

void	solver_5_or_less(t_frame *frame)
{
	if (frame->stack_len == 2)
		solve_2(frame);
	if (frame->stack_len == 3)
		solve_3(frame);
	if (frame->stack_len == 4)
		solve_4(frame);
	if (frame->stack_len == 5)
		solve_5(frame);
}

void	solve_5(t_frame *frame)
{
	t_struct	*stack_end;
	t_struct	*temp;
	int			flag;

	flag = 0;
	stack_end = frame->tail;
	median(frame, 'a');
	while (flag != 1)
	{
		if (frame->stack_a == stack_end)
			flag = 1;
		if (frame->stack_a->num < frame->median)
			do_pb(frame);
		else
			do_ra(frame);
	}
	solve_3(frame);
	temp = frame->stack_b->next;
	if (frame->stack_b->num < temp->num)
		do_sb(frame);
	do_pa(frame);
	do_pa(frame);
//	print(frame, 'a');
}

void	solver(t_frame *frame)
{
	if (frame->stack_len <= 5)
		solver_5_or_less(frame);
	else if (frame->stack_len <= 100)
		solve_big_num(frame);
}
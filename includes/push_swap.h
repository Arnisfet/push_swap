
#ifndef UNTITLED_PUSH_SWAP_H
# define UNTITLED_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_struct
{
	long int		num;
	struct s_struct	*next;
	struct s_struct	*previous;
}				t_struct;

typedef struct	s_frame
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	t_struct	*tail;
	t_struct	*tail_b;
	int			stack_len;
	int			*sign;
	long int			biggest;
	long int			smallest;
	long int			small_move_end;
	long int			small_move_start;
	long int			big_move_end;
	long int			big_move_start;
	long				quarter;
	long				median;
	long			three_quarter;
	int			big_flag;
	int			small_flag;
	int			after_rotate;

}				t_frame;

void	push_swap(t_frame *frame, int ac, char **av);
int		error_parse(t_frame *frame, char **av, int ac);
void	push_swap_error(t_frame *frame);
int		ft_strchr_ps(char **str);
void	create_frame(t_frame *frame);
void	add_to_stack(t_frame *frame, char stack_name, long int num);
int		sorted(t_frame *frame);
void	solver(t_frame *frame);
void	solver_5_or_less(t_frame *frame);
void	find_biggest(t_frame *frame, char stack_name);
void	find_smallest(t_frame *frame, char stack_name);
void	find_biggest_smallest(t_frame *frame, char stack_name);
void	moves_to_end(t_frame *frame, char stack_name, int flag);
void	solve_4(t_frame *frame);
void	median(t_frame *frame, char stack_name);
void	solve_5(t_frame *frame);
void	solve_big_num(t_frame *frame);
void	reset_moves(t_frame *frame);
void	push_median(t_frame *frame, int split);
void	find_moves(t_frame *frame, char stack_name);
void	push_big_small(t_frame *frame, t_struct *stack, t_struct *stack_end);
void	push_quartes(t_frame *frame, int split);

void	do_sa(t_frame *frame);
void	do_rra(t_frame *frame);
void	do_ra(t_frame *frame);
void	do_pb(t_frame *frame);
void	do_pa(t_frame *frame);
void	do_sb(t_frame *frame);
void	do_rb(t_frame *frame);
void	do_rrb(t_frame *frame);

void	stack_del_top(t_frame *frame, char stack_name);
void	stack_add_top(t_frame *frame, char stack_name, long int num);






void print(t_frame *frame, char stack_name);
#endif //UNTITLED_PUSH_SWAP_H

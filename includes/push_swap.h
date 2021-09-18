
#ifndef UNTITLED_PUSH_SWAP_H
# define UNTITLED_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"



typedef struct	s_struct
{
	long int		num;
	struct s_struct	*next;
}				t_struct;

typedef struct	s_frame
{
	t_struct	*stack_a;
	t_struct	*stack_b;
	int			stack_len;
	int			*sign;
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

void	do_sa(t_frame *frame);



#endif //UNTITLED_PUSH_SWAP_H

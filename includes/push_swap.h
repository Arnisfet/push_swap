
#ifndef UNTITLED_PUSH_SWAP_H
# define UNTITLED_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"



typedef struct	s_struct
{
	long int		num;
	struct s_struct	*prev;
	struct s_struct	*next;
}				t_srtuct;

typedef struct	s_frame
{
	t_srtuct	*a;
	t_srtuct	*b;
	t_srtuct	link;
}				t_frame;

void	push_swap(t_frame *frame, int ac, char **av);
int		error_parse(t_frame *frame, char **av, int ac);
void	push_swap_error(t_frame *frame);
int		ft_strchr_ps(char **str);
void	create_frame(t_frame *frame);
void	stack_add_end(t_frame *frame, char stack_name, long int num);


#endif //UNTITLED_PUSH_SWAP_H

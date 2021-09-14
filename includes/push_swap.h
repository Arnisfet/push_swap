//
// Created by Mickey Rudge on 9/10/21.
//

#ifndef UNTITLED_PUSH_SWAP_H
# define UNTITLED_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_struct
{
	struct s_struct	*next;
	struct s_struct	*prev;
}				t_srtuct;

typedef struct	s_frame
{
	int		*argc;
}				t_frame;

t_frame	ft_create_frame(t_frame, char **argv);
void	push_swap(t_frame *frame, int ac, char **av);
int		error_parse(t_frame *frame, char **av, int ac);
void	push_swap_error(t_frame *frame);
int		ft_strchr_ps(char **str);

#endif //UNTITLED_PUSH_SWAP_H

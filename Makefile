SRC		=	sources/push_swap.c	sources/ft_strchr_ps.c	sources/create_frame.c	sources/sorted.c	\
			sources/solver.c	sources/solve_5_or_less.c	sources/move_and_fill/do_sa.c	sources/find_biggest_or_smallest.c	\
			sources/moves.c	sources/move_and_fill/do_rra.c	sources/move_and_fill/do_pb.c	sources/move_and_fill/stack_top.c	\
			sources/move_and_fill/do_ra.c	sources/move_and_fill/do_pa.c sources/move_and_fill/do_sb.c	sources/median.c	\
			sources/solve_big_num.c	sources/push_median.c	sources/move_and_fill/do_rb.c	sources/move_and_fill/do_rrb.c	\
			sources/print.c

OBJ		=	$(SRC:.c=.o)

INC_LIB	=	-I libft/libft.h

INC		=	-I includes/push_swap.h

WWW		=	-Wall -Werror -Wextra

LIB		=	libft/libft.a

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft
	@gcc $(OBJ) $(LIB) $(WWW) -o $(NAME)
	
%.o:	./sources%.c
	@gcc -c $(INC) $(INC_LIB) $(WWW) $< -o $@
	@echo "\t\t\t\t\033[0;34Compile $@"
	// Для работы данной конструкции файлы в срц должны быть конкретно обозначены

%.o:	./sources/move_and_fill%.c
	@gcc -c $(INC) $(INC_LIB) $(WWW) $< -o $@
	@echo "\t\t\t\t\033[0;34Compile $@"
clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\t\t\t\t\033[0;41mDelete $(NAME)"

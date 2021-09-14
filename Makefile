SRC		=	sources/push_swap.c	sources/ft_strchr_ps.c	sources/create_frame.c

OBJ		=	$(SRC:.c=.o)

INC_LIB	=	-I libft/libft.h

INC		=	-I includes/push_swap.h

WWW		=	-Wall -Werror -Wextra

LIB		=	libft/libft.a

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft
	gcc $(OBJ) $(LIB) $(WWW) -o $(NAME)

%.o:	./sources%.c
	gcc -c $(INC) $(INC_LIB) $(WWW) $< -o $@
	// Для работы данной конструкции файлы в срц должны быть конкретно обозначены

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

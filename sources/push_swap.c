

#include "../includes/push_swap.h"

/* Этапы написания алгоритма:
 * 1) парсинг элементов из командной строки в стек и обработка ошибок
 * Процесс парсинга:
 * 		1)объявление указателя на массив интов и последующее выделение памяти
 * 		в функции пушсвап.
 * 		2) Парс ошибок
 *	Кейсы ошибок:
 *		1) Один из аргументов не целое число
 *		2) один из аргументов больше чем целое число
 *		3) В списке аргументов присутствуют дубликаты
 *	2)Создание новых элементов списка и запись каждого элемента в этот список.
 *
 *	*/



void	push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	free(frame);
	exit(0);
}
int	error_parse(t_frame *frame, char **av, int ac)
{
	int			i;
	int			j;
	char		str[255];
	long int	num;

	ft_bzero(str, 255);
	i = 1;
	j = 0;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (!ft_strchr_ps(av))
			push_swap_error(frame);
		else if (str[num])
			push_swap_error(frame);
		if (num > 2147483647 || num < -2147483648)
			push_swap_error(frame);
		else if (!str[num])
			str[num] = 1;
		else if(!ft_isdigit((int)num))
			push_swap_error(frame);
		stack_add_end(frame, 'a', num);
//		frame->argc = //запись в стек а.
		printf("%ld", num);
		i++;
	}
}

void	push_swap(t_frame *frame, int ac, char **av)
{
	create_frame(frame);
	error_parse(frame, av, ac);
}

void	stack_add_end(t_frame *frame, char stack_name, long int num)
{


}

int	main(int ac, char **av)
{
	t_frame *frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->link.num = 0;
	frame->link->next = frame;
	if (ac < 2)
		return (1);
	push_swap(frame, ac, av);
}

// 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 токен

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
 *	2)Создание новых элементов списка и запись значения в каждый элемент
 *	этого списка.
 *	3) Проверка на отсортированность полученного списка элементов.
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
	char		str[255];
	long int	num;
	int i;

	i = 0;
	ft_bzero(str, 255);
	while (av[i+1])
	{
		num = ft_atoi(av[i+1]);
		if (!ft_strchr_ps(av))
			push_swap_error(frame);
		else if (str[num] && num != 0)
			push_swap_error(frame);
		if (num > 2147483647 || num < -2147483648)
			push_swap_error(frame);
		else if (!str[num])
			str[num] = 1;
		else if(!ft_isdigit((int)num))
			push_swap_error(frame);
		add_to_stack(frame, 'a', num);
//		frame->argc = //запись в стек а.
//		printf("%ld", num);
		i++;
	}
	return 0;
}

void	push_swap(t_frame *frame, int ac, char **av)
{
	frame->stack_a = (t_srtuct *)malloc(sizeof (t_srtuct));
	frame->stack_b = (t_srtuct *)malloc(sizeof (t_srtuct));
	error_parse(frame, av, ac);
	if (!sorted(frame))
		return ; // Не забудь почистить элементы списка.
	solver(frame);
}

void	add_to_stack(t_frame *frame, char stack_name, long int num)
{
	t_srtuct *tmpA;
	t_srtuct *tmpB;

	tmpA = frame->stack_a;
	tmpB = frame->stack_b;

	while (tmpA->next != NULL)
	{
		tmpA = tmpA->next;
		tmpB = tmpB->next;
		printf("Stack A: %li\n", tmpA->num);
	}
	tmpA->next = (t_srtuct *) malloc(sizeof(t_srtuct));
	tmpB->next = (t_srtuct *) malloc(sizeof(t_srtuct));
	tmpA = tmpA->next;
	tmpB = tmpB->next;
	tmpA->num = num;
	tmpA->next = NULL;
	++frame->stack_len;
//	printf("Stack A: %li\n", tmpA->num);
}

int	main(int ac, char **av)
{
	t_frame *frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (ac < 2)
		return (1);
	create_frame(frame);
	push_swap(frame, ac, av);
}

// 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 токен

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

void	check_duplicates(t_frame *frame)
{
	t_struct *tmpA;
	t_struct *checker;

	tmpA = frame->stack_a;

	while (tmpA->next !=NULL)
	{
		checker = tmpA->next;
		while(checker->next != NULL)
		{
			printf("%li %li\n", tmpA->num, checker->num);
			if (checker->num == tmpA->num)
				push_swap_error(frame);
			checker = checker->next;
		}
		tmpA = tmpA->next;
	}
}

int	error_parse(t_frame *frame, char **av, int ac)
{
	long int	num;
	int			i;

	i = 0;
	while (av[i+1])
	{
		num = ft_atoi(av[i+1]);
		if (num > 2147483647 || num < -2147483648)
			push_swap_error(frame);
		if(num < 0)
		{
			if (!ft_isdigit(av[i+1][1]))
				push_swap_error(frame);
		}
		else if (!ft_isdigit(*av[i+1]))
			push_swap_error(frame);
		if (!ft_strchr_ps(av))
			push_swap_error(frame);
		add_to_stack(frame, 'a', num);
		i++;
	}
	return 0;
}

void	push_swap(t_frame *frame, int ac, char **av)
{
	frame->stack_a = (t_struct *)malloc(sizeof (t_struct));
	frame->stack_b = (t_struct *)malloc(sizeof (t_struct));
	create_frame(frame);
	error_parse(frame, av, ac);
	check_duplicates(frame);
	if (!sorted(frame))
		return ; // Не забудь почистить элементы списка.
	solver(frame);
}

void	add_to_stack(t_frame *frame, char stack_name, long int num)
{
	t_struct *tmpA;
	t_struct *tmpB;

	tmpA = frame->stack_a;
	tmpB = frame->stack_b;

	while (tmpA->next != NULL)
	{
//		printf("Stack A: %li\n", tmpA->num);
		tmpA = tmpA->next;
		tmpB = tmpB->next;
//		printf("Stack A: %li\n", tmpA->num);
	}
	if (tmpA->next == NULL)
		tmpA->num = num;
	tmpA->next = (t_struct *) malloc(sizeof(t_struct));
	tmpB->next = (t_struct *) malloc(sizeof(t_struct));
	tmpA = tmpA->next;
	tmpB = tmpB->next;
	tmpA->next = NULL;
	tmpB->next = NULL;
	tmpA->num = num;
	++frame->stack_len;
}

int	main(int ac, char **av)
{
	t_frame *frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (ac < 2)
		return (1);
	push_swap(frame, ac, av);
}

// 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 токен

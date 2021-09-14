

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
 *	*/

int		ft_strchr_ps(char **str)
{
	int		i;
	int		j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= 58 && str[i][j] <= 176)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	exit(0);
}
int	error_parse(t_frame *frame, char **av, int ac)
{
	int			i;
	int			j;
	char		str[255];
	long int	words;

	ft_bzero(str, 255);
	i = 1;
	j = 0;
	while (av[i])
	{
		words = ft_atoi(av[i]);
		if (!ft_strchr_ps(av))
			push_swap_error(frame);
		else if (str[av[i][j]])
			push_swap_error(frame);
		if (words > 2147483647 || words < -2147483648)
			push_swap_error(frame); // Error
		else if (!str[words])
			str[words] = 1;
		else if(!ft_isdigit((int)words))
			push_swap_error(frame); // Error
//		frame->argc = //запись в стек а.
		printf("%ld", words);
				i++;
	}

}
// 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

void	push_swap(t_frame *frame, int ac, char **av)
{
//	printf("%s", av[1]);
//	printf("%d", ac);
	frame->argc = (int *)malloc(sizeof(int) * (ac - 1));
	error_parse(frame, av, ac);
}

int main(int ac, char **av)
{
	t_frame *frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (ac < 2)
		return (1);
	push_swap(frame, ac, av);
}


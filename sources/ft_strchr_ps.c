#include "../includes/push_swap.h"

int	ft_strchr_ps(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= 58 && str[i][j] <= 127)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//
// Created by vitya on 02.05.2021.
//
// Функция возвращает указатель на блок памяти, в который был скопирован
// массив стр
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;

	len = ft_strlen(str) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (!p)
		return (NULL);
	p = ft_memcpy(p, str, len);
	return (p);
}

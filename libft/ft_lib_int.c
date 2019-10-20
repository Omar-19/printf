#include "header.h"

static void	ft_abs(long long *value, char **str, int *size, int *flag)
{
	*flag = 1;
	(*str)[0] = '-';
	(*str)[(*size)--] = '0' - *value % 10;
	*value /= 10;
	*value *= -1;
}

char		*ft_itoa_d(long long int value_i, unsigned long long value_u, int *l)
{
	unsigned long long	value;
	unsigned long long	val;
	char			*str;
	int				size;
	int				flag;

	printf("%s\n", "-------------------------");
	flag = 0;
	size = 0;
	if (value_i < 0)
	{
		++size;
		flag = 1;
		val = -value_i;
	}
	else if (value_i > 0)
		val = value_i;
	else
		val = value_u;
	value = val;
	while (value /= 10)
		++size;
	++size;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size--] = '\0';
	*l = size;
	if (flag == 1)
		str[0] = '-';
	while ((size > 0 && flag == 1) || (size >= 0 && flag == 0))
	{
		str[size--] = '0' + val % 10;
		val /= 10;
	}
	printf("%s\n", "-------------------------");
	return (str);
}

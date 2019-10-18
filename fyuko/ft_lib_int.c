#include "header.h"

int			ft_result_len(t_param *f_p_s, int flag)
{
	//if ((*f_p_s).result < (*f_p_s).precision)
	//{
	//(*f_p_s).result = (*f_p_s).precision + flag;
	if ((*f_p_s).precision > (*f_p_s).len)
		(*f_p_s).len = (*f_p_s).precision + flag;
	//}
	(*f_p_s).result = (*f_p_s).len;
	if ((*f_p_s).result < (*f_p_s).width)
		(*f_p_s).result = (*f_p_s).width;
	//---
	//if ((*f_p_s).precision > (*f_p_s).len)
	//	(*f_p_s).len = (*f_p_s).precision + flag;
	return ((*f_p_s).result);
}

void		ft_string_processing(t_param *f_p_s, char *str, int flag)
{
	int i;
	int f;

	i = 0;
	f = 0;
	if (ft_strchr((*f_p_s).flags, '0'))
		f = 1;
	//printf("len = %d\n", (*f_p_s).len);
	//printf("size = %d\n", (*f_p_s).result - i);
	while ((*f_p_s).result - i > (*f_p_s).len - flag)
	{
		//printf("--------%c\n", '-');
		//printf("i = %d\n", i);
		//printf("\n--------%c\n", '-');
		//printf("\n%d != %d\n", (*f_p_s).precision, (*f_p_s).result);
		if (i == 0 && ft_strchr((*f_p_s).flags, ' ') && (*f_p_s).width == (*f_p_s).result)//&& (*f_p_s).precision + flag != (*f_p_s).result)
		{
			//printf("\n--------%c\n", '-');
			str[i] = ' ';
		}
		else if ((i == 0 || (i == 1 && str[0] != '-')) && flag == 1)
			str[i] = '-';
		else if (f == 0)
			str[i] = ' ';
		else
			str[i] = '0';
		++i;
	}
	if((i == 0 && flag == 1) || (i == 1 && flag == 1 && str[0] != '-'))
		str[i] = '-';
}

char		*ft_itoa_d(long long int value_i, unsigned long long value_u, t_param *f_p_s)
{
	//unsigned long long	value;
	//unsigned long long	val;
	unsigned long long	val[2];
	char				*str;
	int					size;
	int					flag;

	flag = 0;
	size = 0;
	if (value_i < 0)
	{
		++size;
		flag = 1;
		val[0] = -value_i;
	}
	else if (value_i > 0)
		val[0] = value_i;
	else
		val[0] = value_u;
	val[1] = val[0];
	while (val[1] /= 10)
		++size;
	++size;
	(*f_p_s).len = size;
	size = ft_result_len(f_p_s, flag);
	//printf("len = %d\n", (*f_p_s).len);
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size--] = '\0';
	//if (flag == 1)
	//	str[0] = '-'
	ft_string_processing(f_p_s, str, flag);
	// исправить эту хуйню!!!
	//if ((*f_p_s).len == (*f_p_s).precision + flag)
	//	--(*f_p_s).len;
	while (((*f_p_s).len > 1 && flag == 1) || ((*f_p_s).len >= 1 && flag == 0))
	{
		//printf("\nsize = %d = %c\n", size, '0' + val[0] % 10);
		str[size--] = '0' + val[0] % 10;
		val[0] /= 10;
		--(*f_p_s).len;
	}
	return (str);
}

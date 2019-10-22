/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:35:06 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_strnew_null(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		ptr[i++] = '0';
	ptr[i] = '\0';
	return (ptr);
}

int			ft_only_space(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (0);
		++str;
	}
	return (1);
}

int			ft_result_len(t_param *f_p_s, int flag)
{
	int f;

	f = 0;
	if (flag)
		f = 1;
	if ((*f_p_s).precision > (*f_p_s).len)
		(*f_p_s).len = (*f_p_s).precision + f;
	(*f_p_s).result = (*f_p_s).len;
	if ((*f_p_s).result < (*f_p_s).width)
		(*f_p_s).result = (*f_p_s).width;
	if (ft_only_space((*f_p_s).flags) && (*f_p_s).width == 0 && (*f_p_s).precision == 0)
		++(*f_p_s).result;
	return ((*f_p_s).result);
}

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr != '\0' || (*ptr == '\0' && c == '\0'))
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

int		ft_strstr_num(const char *str, const char *to_find, size_t len)
{
	const char *a;
	const char *b;

	while (len > 0)
	{
		a = str;
		b = to_find;
		while (*(a++) == *(b++))
		{
			if (*b == '\0')
				return (1);
		}
		++str;
		--len;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++) != '\0')
		++i;
	return (i);
}


// char		*ft_itoa_d_flagmin(long long int value_i, unsigned long long value_u, t_param *f_p_s)
// {
// 	unsigned long long	val[2];
// 	char				*str;
// 	int					size;
// 	int					flag;

// 	flag = 0;
// 	size = 0;

// 	if (ft_strchr((*f_p_s).flags, '+'))
// 	{
// 		flag = 3;
// 		++size;
// 	}
// 	if (value_i < 0)
// 	{
// 		if (flag != 3)
// 			++size;
// 		flag = 1;
// 		val[0] = -value_i;
// 	}
// 	else if (value_i > 0)
// 		val[0] = value_i;
// 	else
// 		val[0] = value_u;
// 	val[1] = val[0];
// 	while (val[1] /= 10)
// 		++size;
// 	++size;
// 	(*f_p_s).len = size;
// 	size = ft_result_len(f_p_s, flag);
// 	str = ft_strnew_space(size);
// 	str[size--] = '\0';
// 	if (flag == 3)
// 		str[0] = '+';
// 	if (flag == 1)
// 		str[0] = '-';
// 	size = (*f_p_s).len--;
// 	//printf("\nx%sx\n", str);
// 	while (val[0] != 0)
// 	{
// 		//printf("\n%s\n", "------------------------------");
// 		str[(*f_p_s).len--] = '0' + val[0] % 10;
// 		val[0] /= 10;
// 	}
// 	//printf("\nsize == (*f_p_s).len + 1 : %d == %d\n", size, (*f_p_s).len + 1);
// 	if (size == (*f_p_s).len + 1)
// 		str[size - 1] = '0';
// 	//if ((*f_p_s).precision != 0)
// 	//while(str[size] != '\0')
// 	//	str[size++] = ' ';
// 	return (str);
// }
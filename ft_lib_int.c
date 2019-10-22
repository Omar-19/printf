/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:32 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:34:35 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_string_processing(t_param *f_p_s, char *str, int flag)
{
	int i;
	int f;
	int fl;

	fl = 0;
	i = 0;
	f = 0;
	if (flag)
		fl = 1;
	if (ft_strchr((*f_p_s).flags, '0'))
		f = 1;
	if (ft_strchr((*f_p_s).flags, ' ') && (*f_p_s).width == (*f_p_s).result)
		str[i++] = ' ';
	while ((*f_p_s).result - i > (*f_p_s).len - fl)
	{
		if ((i == 0 || (i == 1 && str[0] != '-')) && flag == 1 && f)
			str[i] = '-';
		else if ((i == 0 || (i == 1 && str[0] != '+')) && flag == 3 && f)
			str[i] = '+';
		else if (f == 0)
			str[i] = ' ';
		else
			str[i] = '0';
		++i;
	}
	if (!f && flag == 1)
		str[--i] = '-';
	else if (!f && flag == 3)
		str[--i] = '+';
	if((i == 0 && flag == 1) || (i == 1 && flag == 1 && str[0] != '-'))
		str[i] = '-';
	else if((i == 0 && flag == 3) || (i == 1 && flag == 3 && str[0] != '+'))
		str[i] = '+';
}

char		*ft_itoa_d(long long int value_i, unsigned long long value_u, t_param *f_p_s)
{
	unsigned long long	val[2];
	char				*str;
	int					size;
	int					flag;
	int					flag_pl;

	flag = 0;
	size = 0;
	flag_pl = 0;
	if (ft_strchr((*f_p_s).flags, '-'))
		return (ft_itoa_d_flagmin(value_i, value_u, f_p_s));
	//--------------------------------
	if (ft_strchr((*f_p_s).flags, '+'))
	{
		flag = 3;
		++size;
	}
	if (value_i < 0)
	{
		if (flag != 3)
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
	//------------------------------
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size--] = '\0';
	ft_string_processing(f_p_s, str, flag);
	while (((*f_p_s).len > 1 && flag == 1) || ((*f_p_s).len > 1 && flag == 3)
		|| ((*f_p_s).len >= 1 && flag == 0))
	{
		str[size--] = '0' + val[0] % 10;
		val[0] /= 10;
		--(*f_p_s).len;
	}
	return (str);
}
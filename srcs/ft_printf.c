/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:49 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:34:51 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void		ft_write_str(const char *str, size_t len)
{
	write(1, str, len);
}

inline int	ft_is_conversion(const char c)
{
	return (!(ft_strchr("diuoxXfFeEgGaAcsSpn%", c) == NULL));
}

int			print_elem(const char *format, va_list elem)
{
	const char	*ptr;
	const char	*str;
	size_t		len;
	int			res;
	int			i;

	str = format;
	res = 0;
	ptr = str;
	i = 0;
	len = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			len = str + i - ptr;
			if (len != 0)
			{
				ft_write_str(ptr, len);
				res += len;
				ptr = str + ++i;
			}
			else
				ptr = str + ++i;
			// if (str[i] == '%')
			// 	++i;
			// else
			// {
			while(!(ft_is_conversion(str[i])))
				++i;
			len = str + i - ptr + 1;
			res += ft_param_processing(ptr, len, elem);
			ptr = str + ++i;
			// }
			continue;
		}
		++i;
	}
	if ((len = str + i - ptr))
	{
		res += len;
		ft_write_str(ptr, len);
	}
	return (res);
}

int			ft_printf(const char *format, ...)
{
	va_list	elem;
	int		result;

	va_start(elem, format);
	result = print_elem(format, elem);
	va_end(elem);
	return (result);
}

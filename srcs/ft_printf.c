/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:49 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/26 18:41:14 by btheia           ###   ########.fr       */
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
	return (!(ft_strchr("diuoxXfFeEgGaAcsSpbn%", c) == NULL));
}

int			print_elem(const char *format, va_list elem)
{
	const char	*ptr;
	const char	*str;
	size_t		len;
	int			res;
	int			i;
	int			j;

	str = format;
	res = 0;
	ptr = str;
	i = 0;
	len = 0;
	while(str[i])
	{
		j = 0;
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
			if (!str[i])
			{
				// res += len;
				// ft_write_str(ptr, len);
				// // --i;
				// // break;
				return res;
			}
			while(!(ft_is_conversion(str[i])))
			{
				++j;
				if (!str[++i])
				{
					res += j;
					write(1, (str + i - 1), 1);
					// ft_write_str(ptr, len);
					//--i;
					// break;
					return res;
				}
			}
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

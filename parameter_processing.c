/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:35:41 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline int		ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+' ", c) == NULL));
}

int		ft_atoi_n(const char *str, int *j)
{
	long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		++(*j);
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + 1 * (*str - '0');
		str++;
	}
	return (number);
}

void	ft_format_specification_description(const char *str, size_t len, va_list elem, t_param *f_p_s)
{
	int i;
	int j;

	i = 0;
	while (ft_is_flag(*(str + i)) && i < len)
	{
		*((*f_p_s).flags + i) = *(str + i);
		++i;
	}
	j = i;
	while (i < 5)
		*((*f_p_s).flags + i++) = '\0';
	i = 0;
	if (*(str + j) == '*')
	{
		(*f_p_s).width = va_arg(elem, int);
		++j;
	}
	else if (*(str + j) >= '0' && *(str + j) <= '9')
		(*f_p_s).width = ft_atoi_n(str + j, &j);
	else
		(*f_p_s).width = 0;
	if (*(str + j) == '.')
	{
		if (*(str + ++j) == '*')
			(*f_p_s).precision = va_arg(elem, int);
		else
			(*f_p_s).precision = ft_atoi_n(str + j, &j);
	}
	else
		(*f_p_s).precision = 0;
}

int		read_variable_int(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char	*ptr;
	
	if (ft_strstr_num(str, "hhd\0", len) || ft_strstr_num(str, "hhi\0", len))
		ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, form_place_spc);
	else if (ft_strstr_num(str, "hd\0", len) || ft_strstr_num(str, "hi\0", len))
		ptr = ft_itoa_d((short int)va_arg(elem, int), 0, form_place_spc);
	else if (ft_strstr_num(str, "lld\0", len) || ft_strstr_num(str, "lli\0", len))
		ptr = ft_itoa_d(va_arg(elem, long long int), 0, form_place_spc);
	else if (ft_strstr_num(str, "ld\0", len) || ft_strstr_num(str, "li\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, form_place_spc);
	else if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
		ptr = ft_itoa_d(va_arg(elem, int), 0, form_place_spc);
	else if (ft_strstr_num(str, "llu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), form_place_spc);
	else if (ft_strstr_num(str, "lu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), form_place_spc);
	else if (ft_strstr_num(str, "hhu\0", len))
		ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), form_place_spc);
	else if (ft_strstr_num(str, "hu\0", len))
		ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), form_place_spc);
	else if (ft_strstr_num(str, "u\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned int), form_place_spc);
	else
	{
		return (0);
	}
	write(1, ptr, (*form_place_spc).result);
	free(ptr);
	return ((*form_place_spc).result);
}

int		read_variable_char(const char *str, size_t len, va_list elem)
{
	char	*ptr;
	char 	s;
	size_t	res;

	if (ft_strstr_num(str, "c\0", len))
	{
		s = (char)va_arg(elem, int);
		write(1, &s, 1);
		return (1);
	}
	else if (ft_strstr_num(str, "s\0", len))
	{
		ptr = va_arg(elem, char *);
		res = ft_strlen(ptr);
		write(1, ptr, res);
		return (res);
	}
	return (0);
}

int		read_variable_float(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char			*ptr;
	t_double		d;
	char			*l;
	int				sign;

	if ((*form_place_spc).precision == 0)
		(*form_place_spc).precision = 6;
	if (ft_strstr_num(str, "Lf\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = float_ld(d, (*form_place_spc).precision, &sign);
	}
	else if (ft_strstr_num(str, "lf\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = float_d(d, (*form_place_spc).precision, &sign);
	}
	else if (ft_strstr_num(str, "f\0", len))
	{
		d.numf = (float)va_arg(elem, double);
		ptr = float_f(d, (*form_place_spc).precision, &sign);
	}
	else
		return (0);
	(*form_place_spc).len = ft_strlen(ptr);
	ft_result_len(form_place_spc, 0);
	write(1, ptr, (*form_place_spc).len);
	return ((*form_place_spc).result);
}

int		ft_param_processing(const char *str, size_t len, va_list elem)
{
	int		l;
	char	*ptr;
	// Format placeholder specification
	t_param	form_place_spc;

	ft_format_specification_description(str, len, elem, &form_place_spc);

	if ((l = read_variable_int(str, len, elem, &form_place_spc)))
		return (l);
	else if ((l = read_variable_char(str, len, elem)))
		return (l);
	else if ((l = read_variable_float(str, len, elem, &form_place_spc)))
		return (l);
	return (0);
}

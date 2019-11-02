/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 20:59:11 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline int	ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+ ", c) == NULL));
}

int					ft_atoi_n(const char *str, int *j)
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
		++str;
	}
	return (number);
}

static inline void	ft_null_f_p_s(t_param *f_p_s, size_t *i, int *j)
{
	*i = 0;
	*j = 0;
	f_p_s->is_hash = 0;
	f_p_s->is_minus = 0;
	f_p_s->is_plus = 0;
	f_p_s->is_pres = 0;
	f_p_s->is_space = 0;
	f_p_s->is_zero = 0;
	f_p_s->is_width = 1;
}

void				ft_format_specification_description(const char *str,
	size_t len, va_list elem, t_param *f_p_s)
{
	size_t	i;
	int		j;
	int		k;

	ft_null_f_p_s(f_p_s, &i, &j);
	while (ft_is_flag(*(str + i)) && i < len)
	{
		if (i == 0 || !ft_strchr((*f_p_s).flags, *(str + i)))
		{
			(*(str + i) == ' ') ? (f_p_s->is_space = 1) : 0;
			(*(str + i) == '+') ? (f_p_s->is_plus = 1) : 0;
			(*(str + i) == '-') ? (f_p_s->is_minus = 1) : 0;
			(*(str + i) == '#') ? (f_p_s->is_hash = 1) : 0;
			(*(str + i) == '0') ? (f_p_s->is_zero = 1) : 0;
			*((*f_p_s).flags + j) = *(str + i);
			*((*f_p_s).flags + j + 1) = '\0';
			++j;
		}
		++i;
	}
	k = j;
	j = i;
	while (i < len)
	{
		if (*(str + i) == '+' || *(str + i) == '-')
		{
			f_p_s->is_plus = 1;
			*((*f_p_s).flags + k) = *(str + i);
			*((*f_p_s).flags + k + 1) = '\0';
			++k;
		}
		if (*(str + i) == '#')
		{
			f_p_s->is_hash = 1;
			*((*f_p_s).flags + k) = *(str + i);
			*((*f_p_s).flags + k + 1) = '\0';
			++k;
		}
		++i;
	}
	if (*(str + j) == '*')
	{
		(*f_p_s).width = va_arg(elem, int);
		++j;
	}
	else if (*(str + j) >= '0' && *(str + j) <= '9')
		(*f_p_s).width = ft_atoi_n(str + j, &j);
	else
	{
		f_p_s->is_width = 0;
		(*f_p_s).width = 0;
	}
	if (*(str + j) == '.')
	{
		if (*(str + ++j) == '*')
			(*f_p_s).precision = va_arg(elem, int);
		else
			(*f_p_s).precision = ft_atoi_n(str + j, &j);
		f_p_s->is_pres = 1;
	}
	else
		(*f_p_s).precision = 0;
}

int					read_variable_percent(const char *str,
	size_t len, t_param *form_place_spc)
{
	form_place_spc->len = 1;
	if (ft_strstr_num(str, "%\0", len))
		ft_write_tail_percent(form_place_spc);
	else
		return (0);
	return (form_place_spc->result);
}

int					read_variable_int(const char *str, size_t len,
	va_list elem, t_param *f_p_s)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
	{
		if (ft_strstr_num(str, "j\0", len) || ft_strstr_num(str, "z\0", len) ||
			ft_strstr_num(str, "ll\0", len))
			ptr = ft_itoa_d(va_arg(elem, long long int), 0, f_p_s, 0);
		else if (ft_strstr_num(str, "l\0", len))
			ptr = ft_itoa_d(va_arg(elem, long int), 0, f_p_s, 0);
		else if (ft_strstr_num(str, "hh\0", len))
			ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, f_p_s, 0);
		else if (ft_strstr_num(str, "h\0", len))
			ptr = ft_itoa_d((short int)va_arg(elem, int), 0, f_p_s, 0);
		else
			ptr = ft_itoa_d(va_arg(elem, int), 0, f_p_s, 0);
	}
	else if (ft_strstr_num(str, "u\0", len) || ft_strstr_num(str, "U\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "U\0", len))
			ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), f_p_s, 1);
		else if (ft_strstr_num(str, "l\0", len) || (ft_strstr_num(str, "j\0", len)))
			ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), f_p_s, 1);
		else if (ft_strstr_num(str, "hh\0", len))
			ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), f_p_s, 1);
		else if (ft_strstr_num(str, "h\0", len))
			ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), f_p_s, 1);
		else
			ptr = ft_itoa_d(0, va_arg(elem, unsigned int), f_p_s, 1);
	}
	else
		return (0);
	if (ptr)
		free(ptr);
	return ((*form_place_spc).result);
}

int					read_variable_int1(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char *ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "x\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "l\0", len) ||
			ft_strstr_num(str, "j\0", len))
			ptr = hex_oct_main(elem, form_place_spc, 'x', 1);
		else
			ptr = hex_oct_main(elem, form_place_spc, 'x', 0);
	}
	else if (ft_strstr_num(str, "X\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "l\0", len) ||
			ft_strstr_num(str, "j\0", len))
			ptr = hex_oct_main(elem, form_place_spc, 'X', 1);
		else
			ptr = hex_oct_main(elem, form_place_spc, 'X', 0);
	}
	else if (ft_strstr_num(str, "o\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "l\0", len) ||
			ft_strstr_num(str, "j\0", len))
			ptr = hex_oct_main(elem, form_place_spc, 'o', 1);
		else
			ptr = hex_oct_main(elem, form_place_spc, 'o', 1);
	}
	else if (ft_strstr_num(str, "b\0", len))
	{
		if (ft_strstr_num(str, "ll\0", len) || ft_strstr_num(str, "l\0", len) ||
			ft_strstr_num(str, "j\0", len))
			ptr = hex_oct_main(elem, form_place_spc, 'b', 1);
		else
			ptr = hex_oct_main(elem, form_place_spc, 'b', 1);
	}
	else
		return (0);
	if (ptr)
		free(ptr);
	return (form_place_spc->result);
}

int					read_variable_char(const char *str, size_t len, va_list elem, t_param *f_p_s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (ft_strstr_num(str, "c\0", len))
	{
		f_p_s->len = 1;
		ft_write_tail_char(f_p_s, (char)va_arg(elem, int));
		return (f_p_s->result);
	}
	else if (ft_strstr_num(str, "s\0", len))
	{
		ptr = va_arg(elem, char*);
		if (!ptr)
			(f_p_s->is_pres && !f_p_s->precision) ? (ptr = "") :
				(ptr = "(null)");
		f_p_s->len = ft_strlen(ptr);
		ft_write_tail_str(f_p_s, ptr);
		return (f_p_s->result);
	}
	else if (ft_strstr_num(str, "p\0", len))
	{
		f_p_s->is_pres = 0;
		f_p_s->precision = 0;
		ptr = va_arg(elem, void *);
		(!ptr) ? (ptr = strdup("0x0")) : (ptr = point_hex(&ptr));
		f_p_s->len = ft_strlen(ptr);
		ft_write_tail_str(f_p_s, ptr);
		if (ptr)
			free(ptr);
		return (f_p_s->result);
	}
	return (0);
}

int					read_variable_float(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char			*ptr;
	t_double		d;
	int				sign;

	ptr = NULL;
	if ((*form_place_spc).precision == 0 && !ft_strstr_num(str, ".0\0", len))
		(*form_place_spc).precision = 6;
	if (ft_strstr_num(str, "Lf\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = new_float_ld(d, (*form_place_spc).precision);
	}
	else if (ft_strstr_num(str, "f\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = new_float_d(d, (*form_place_spc).precision);
	}
	else if (ft_strstr_num(str, "Le\0", len))
	{
		d.numld = va_arg(elem, long double);
		ptr = float_lde(d, (*form_place_spc).precision, &sign);
	}
	else if (ft_strstr_num(str, "e\0", len))
	{
		d.numd = va_arg(elem, double);
		ptr = float_de(d, (*form_place_spc).precision, &sign);
	}
	else
		return (0);
	(*form_place_spc).len = ft_strlen(ptr);
	if (form_place_spc->is_hash && form_place_spc->is_pres &&
		!form_place_spc->precision)
	{
		*(ptr + form_place_spc->len) = '.';
		++(form_place_spc->len);
	}
	ft_result_len_float(form_place_spc, *ptr);
	ft_flag_correction_1(form_place_spc);
	ft_write_tail(form_place_spc, *ptr, ptr);
	if (ptr)
		free(ptr);
	return ((*form_place_spc).result);
}

int					ft_param_processing(const char *str, size_t len, va_list elem)
{
	int		l;
	t_param	form_place_spc;

	if (ft_strstr_num(str, "Z\0", len))
	{
		write(1, "Z", 1);
		return (1);
	}
	ft_format_specification_description(str, len, elem, &form_place_spc);
	if ((l = read_variable_percent(str, len, &form_place_spc)))
		return (l);
	else if ((l = read_variable_int1(str, len, elem, &form_place_spc)))
		return (l);
	else if ((l = read_variable_char(str, len, elem, &form_place_spc)))
		return (l);
	else if ((l = read_variable_int(str, len, elem, &form_place_spc)))
		return (l);
	else
	{
		ft_flag_correction3(&form_place_spc);
		if ((l = read_variable_float(str, len, elem, &form_place_spc)))
			return (l);
	}
	return (0);
}

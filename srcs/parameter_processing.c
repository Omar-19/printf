/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/28 21:13:47 by btheia           ###   ########.fr       */
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

void				ft_format_specification_description(const char *str, size_t len, va_list elem, t_param *f_p_s)
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
	// printf("FLAGs = |%s|\n", f_p_s->flags);
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
		//  *(str + i) == '#'
		if (*(str + i) == '#')
		{
			f_p_s->is_hash = 1;
			*((*f_p_s).flags + k) = *(str + i);
			*((*f_p_s).flags + k + 1) = '\0';
			++k;
		}
			// (*(str + i) == ' ') ? (f_p_s->is_space = 1) : 0;
			// (*(str + i) == '+') ? (f_p_s->is_plus = 1) : 0;
			// (*(str + i) == '-') ? (f_p_s->is_minus = 1) : 0;
			// (*(str + i) == '#') ? (f_p_s->is_hash = 1) : 0;
			// (*(str + i) == '0') ? (f_p_s->is_zero = 1) : 0;
			// *((*f_p_s).flags + k) = *(str + i);
			// *((*f_p_s).flags + k + 1) = '\0';
			// ++j;
		// }
		++i;
	}
	// i = 0;
	// if (ft_strchr((*f_p_s).flags, '+'))
	// 	while ((*f_p_s).flags[i] != '\0')
	// 	{
	// 		if ((*f_p_s).flags[i] == ' ')
	// 			(*f_p_s).flags[i] = '+';
	// 		++i;
	// 	}
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
	// printf("FLAGs = |%s|\n", f_p_s->flags);
	// printf("PRES = |%d|\n", f_p_s->precision);
	// printf("# = |%d|\n", f_p_s->is_hash);
	// printf("- = |%d|\n", f_p_s->is_minus);
	// printf("+ = |%d|\n", f_p_s->is_plus);
	// printf("pres = |%d|\n", f_p_s->is_pres);
	// printf("space = |%d|\n", f_p_s->is_space);
	// printf("0 = |%d|\n", f_p_s->is_zero);
}

int					read_variable_percent(const char *str, size_t len, t_param *form_place_spc)
{
	form_place_spc->len = 1;
	// printf("--------------------------%c", '\n');
	if (ft_strstr_num(str, "%\0", len))
	{
		// printf("--------------------------%c", '\n');
		ft_write_tail_percent(form_place_spc);//ft_write_tail_percent(form_place_spc);
	}
	else
		return (0);
	return (form_place_spc->result);
}

int					read_variable_int(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char	*ptr;
	//long long	a;

	// printf("FLAGs = |%s|\n", form_place_spc->flags);
	ptr = NULL;
	if (ft_strstr_num(str, "hhd\0", len) || ft_strstr_num(str, "hhi\0", len))
		ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, form_place_spc, 0);
	else if (ft_strstr_num(str, "hd\0", len) || ft_strstr_num(str, "hi\0", len))
		ptr = ft_itoa_d((short int)va_arg(elem, int), 0, form_place_spc, 0);
	else if (ft_strstr_num(str, "lld\0", len) || ft_strstr_num(str, "lli\0", len))
		ptr = ft_itoa_d(va_arg(elem, long long int), 0, form_place_spc, 0);
	else if (ft_strstr_num(str, "ld\0", len) || ft_strstr_num(str, "li\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, form_place_spc, 0);
	else if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
		ptr = ft_itoa_d(va_arg(elem, int), 0, form_place_spc, 0);
	else if (ft_strstr_num(str, "llu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), form_place_spc, 1);
	else if (ft_strstr_num(str, "lu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), form_place_spc, 1);
	else if (ft_strstr_num(str, "hhu\0", len))
		ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), form_place_spc, 1);
	else if (ft_strstr_num(str, "hu\0", len))
		ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), form_place_spc, 1);
	else if (ft_strstr_num(str, "u\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned int), form_place_spc, 1);
	// else if (ft_strstr_num(str, "llx\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'x', 1);
	// else if (ft_strstr_num(str, "llX\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'X', 1);
	// else if (ft_strstr_num(str, "x\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'x', 0);
	// else if (ft_strstr_num(str, "X\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'X', 0);
	// else if (ft_strstr_num(str, "llo\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'o', 1);
	// else if (ft_strstr_num(str, "o\0", len))
	// 	ptr = hex_oct_main(elem, form_place_spc, 'o', 0);
	else
		return (0);
	//write(1, ptr, form_place_spc->result);
	if (!ptr)
		free(ptr);
	return ((*form_place_spc).result);
}

int					read_variable_int1(const char *str, size_t len, va_list elem, t_param *form_place_spc)
{
	char *ptr;

	ptr = NULL;
	//printf("\nFLAGS = |%s|\n", form_place_spc->flags);
	if (ft_strstr_num(str, "llx\0", len) || ft_strstr_num(str, "lx\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'x', 1);
	else if (ft_strstr_num(str, "llX\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'X', 1);
	else if (ft_strstr_num(str, "x\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'x', 0);
	else if (ft_strstr_num(str, "X\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'X', 0);
	else if (ft_strstr_num(str, "llo\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'o', 1);
	else if (ft_strstr_num(str, "o\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'o', 1);
	else if (ft_strstr_num(str, "b\0", len))
		ptr = hex_oct_main(elem, form_place_spc, 'b', 1);
	else
		return (0);
	if (!ptr)
		free(ptr);
	return (form_place_spc->result);
}

int					read_variable_char(const char *str, size_t len, va_list elem, t_param *f_p_s)
{
	char	*ptr;


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
		(!ptr) ? (ptr = "0x0") : (ptr = point_hex(&ptr));
		f_p_s->len = ft_strlen(ptr);
		ft_write_tail_str(f_p_s, ptr);
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
		// printf("ddd %f\n",d.numd );
		ptr = new_float_d(d, (*form_place_spc).precision);
		// printf("F = %s\n", ptr);
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
	// printf("F = %s\n", ptr);
	ft_result_len(form_place_spc, 0);
	ft_flag_correction_1(&form_place_spc);
	ft_write_tail(form_place_spc, *ptr, ptr);
	if (!ptr)
		free(ptr);
	return ((*form_place_spc).result);
}

int					ft_param_processing(const char *str, size_t len, va_list elem)
{
	int		l;
	// Format placeholder specification
	t_param	form_place_spc;

	ft_format_specification_description(str, len, elem, &form_place_spc);
	// printf("fps->res = %d\n", form_place_spc.width);
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

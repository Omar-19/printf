/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_hex_octa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/26 20:48:12 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_result_len_xo(t_param *f_p_s)
{
	(!f_p_s->len) ? ((f_p_s->is_hash = 0) && (f_p_s->is_zero = 0) &&
			(f_p_s->len  = 0)) : 0;
	(f_p_s->is_minus || f_p_s->is_pres) ? (f_p_s->is_zero = 0) : 0;
	(*f_p_s).result = (*f_p_s).len;
	if (f_p_s->precision > f_p_s->result)
		f_p_s->result = f_p_s->precision;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
	((f_p_s->precision = f_p_s->precision - f_p_s->len) > 0) ?
		0 : (f_p_s->precision = 0);
	((f_p_s->width = f_p_s->result - f_p_s->len - f_p_s->precision) > 0) ?
		0 : (f_p_s->width = 0);
}

void	ft_xo_write_min(t_param *f_p_s, char *ptr, char ho, char *str[2])
{
	int a;

	a = 0;
	if (f_p_s->is_hash)
	{
		a = 2;
		(ho == 'x') ? (write(1, "0x", 2) && (f_p_s->width -= 2)) : 0;
		(ho == 'X') ? (write(1, "0X", 2) && (f_p_s->width -= 2)) : 0;
		(f_p_s->width < 0) ? ((f_p_s->result += f_p_s->width) &&
			(f_p_s->width = 0)) : 0;
	}
	a = a + f_p_s->precision + f_p_s->len + f_p_s->width;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	write(1, str[1], f_p_s->width);
	f_p_s->result = a;
}

void	ft_xo_write(t_param *f_p_s, char *ptr, char ho, char *str[2])
{
	int a;

	a = 0;
	if (f_p_s->is_hash)
	{
		f_p_s->width -= 2;
		if (f_p_s->width < 0)
		{
			f_p_s->result += f_p_s->width;
			f_p_s->width = 0;
		}
	}
	a += f_p_s->width;
	(f_p_s->is_zero) ? 0 : write(1, str[1], f_p_s->width);
	if (f_p_s->is_hash)
	{
		a += 2;
		(ho == 'x') ? write(1, "0x", 2) : 0;
		(ho == 'X') ? write(1, "0X", 2) : 0;
		// (ho == 'x') ? (write(1, "0x", 2) && (f_p_s->width -= 2)) : 0;
		// (ho == 'X') ? (write(1, "0X", 2) && (f_p_s->width -= 2)) : 0;
		// (f_p_s->width < 0) ? ((f_p_s->result += f_p_s->width) &&
		// 	(f_p_s->width = 0)) : 0;
	}
	// printf("\nWD = %d\n", f_p_s->width);
	(f_p_s->is_zero) ? (write(1, str[1], f_p_s->width)) : 0;
	// write(1, str[1], f_p_s->width);
	a = a + f_p_s->precision + f_p_s->len; 
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	f_p_s->result = a;
	// printf("\nA = %d\n", a);
}

void	ft_write_tail_xo(t_param *f_p_s, char *ptr, char ho)
{
	char	*str[2];

	// printf("\nPTR = |%d|\n", f_p_s->is_hash);
	if (f_p_s->is_pres && (f_p_s->precision == 0))
	{
		f_p_s->len  = 0;
		ptr = "";
	}
	if (f_p_s->is_hash && (ho == 'o'))
	{
		f_p_s->is_hash = 0;
		if (f_p_s->len >= f_p_s->precision)
		{
			(*ptr != '0') ? (f_p_s->precision = f_p_s->len + 1) : 0;
		}
	}
	ft_result_len_xo(f_p_s);
	// (f_p_s->is_pres && (f_p_s->precision == 0)) ?
	// 	((f_p_s->is_hash = 0) && (f_p_s->is_zero = 0) &&
	// 		(f_p_s->len  = 0) && (ptr = "")) : 0;
	// printf("\nPTR = |%s|\n", ptr);
	if (f_p_s->is_hash && (*ptr == '0'))
		f_p_s->is_hash = 0;
	(f_p_s->is_zero) ?
		(str[1] = ft_strnew_char(f_p_s->width, '0')) :
			(str[1] = ft_strnew_char(f_p_s->width, ' '));
	str[0] = ft_strnew_char(f_p_s->precision, '0');
	if (f_p_s->is_minus)
		ft_xo_write_min(f_p_s, ptr, ho, str);
	else
		ft_xo_write(f_p_s, ptr, ho, str);
	free(str[0]);
	free(str[1]);
}

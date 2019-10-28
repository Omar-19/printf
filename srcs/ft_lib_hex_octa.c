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
	// if (f_p_s->len == 0)
	// 	f_p_s->len = 1;
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
	// if (f_p_s->is_hash)
	// {
	// 	if (f_p_s->is_zero)
	// 	{
	// 		if (f_p_s->is_width > 2)
	// 		{
	// 		}
	// 	}
	// }
	if (f_p_s->is_hash)
	{
		(ho == 'x') ? (write(1, "0x", 2) && (f_p_s->result += 2) && (f_p_s->width -= 2)) : 0;
		(ho == 'X') ? (write(1, "0X", 2) && (f_p_s->result += 2) && (f_p_s->width -= 2)) : 0;
		//(ho == 'o') ? (write(1, "0", 1) && ++f_p_s->result) : 0;
		// if (f_p_s->precision > 2)
		// {
		// 	f_p_s->precision -= 2;
		// 	str[0][0] = [0];
		// 	(ho == 'x' || ho == 'X') ? ()
		// 	// (ho == 'x') ? (write(1, "0x", 2) && (f_p_s->result += 2)) : 0;
		// 	// (ho == 'X' && !(*ptr == '0')) ? (write(1, "0X", 2) && (f_p_s->result += 2)) : 0;
		// 	// (ho == 'o' && !(*ptr == '0')) ? (write(1, "0", 1) && ++f_p_s->result) : 0;
		// }
		(f_p_s->width < 0) ? ((f_p_s->result += f_p_s->width) &&
			(f_p_s->width = 0)) : 0;
	}
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	write(1, str[1], f_p_s->width);
}

void	ft_xo_write(t_param *f_p_s, char *ptr, char ho, char *str[2])
{
	// write(1, str[1], i[1]);
	// write(1, str[0], i[0]);
	// write(1, ptr, f_p_s->len);
}

void	ft_write_tail_xo(t_param *f_p_s, char *ptr, char ho)
{
    int		i[2];
	char	*str[2];
	int		flag;

	// printf("\nLEN = %d = %s\n", f_p_s->len, ptr);
	if (f_p_s->is_hash && (ho == 'o'))
		(f_p_s->len > f_p_s->precision) ?
			(f_p_s->precision = f_p_s->len + 1) : (++f_p_s->precision);
	ft_result_len_xo(f_p_s);
	// flag = 0;
	// if (ft_strchr((*f_p_s).flags, '#'))
	// 	flag = 1;
	// if (f_p_s->len == f_p_s->result)
	// {
	// 	if (f_p_s->is_hash)
	// 	{
	// 		(ho == 'x' && !(*ptr == '0')) ? (write(1, "0x", 2) && (f_p_s->result += 2)) : 0;
	// 		(ho == 'X' && !(*ptr == '0')) ? (write(1, "0X", 2) && (f_p_s->result += 2)) : 0;
	// 		(ho == 'o' && !(*ptr == '0')) ? (write(1, "0", 1) && ++f_p_s->result) : 0;
	// 	}
	// 	write(1, ptr, f_p_s->len);
	// 	return ;
	// }
	if (f_p_s->is_hash && (*ptr == '0'))
		f_p_s->is_hash = 0;
	// if ((i[0] = f_p_s->precision - f_p_s->len) < 0)
	// 	i[0] = 0;
	// if ((i[1] = f_p_s->result - f_p_s->len - i[0]) < 0)
	// 	i[1] = 0;
	// printf("i[0] = %d i[1] = %d\n", i[0], i[1]);
	// if (ho == 'o' && flag && i[0] == 0)
	// {
	// 	++f_p_s->result;
	// 	i[0] = 1;
	// }
	// if (flag && (ho == 'x' || ho == 'X'))
	// {
	// 	i[0] += 2;
	// 	i[1] -=2;
	// 	if (i[1] < 0)
	// 		f_p_s->result += -i[1];
	// }
	(f_p_s->is_zero) ?
		(str[1] = ft_strnew_char(f_p_s->width, '0')) :
			(str[1] = ft_strnew_char(f_p_s->width, ' '));
	str[0] = ft_strnew_char(f_p_s->precision, '0');
	// if (f_p_s->is_hash)
	// 	if (!(ho == 'o'))
	// 	{
	// 		(ft_strchr((*f_p_s).flags, '0') && !(ft_strchr((*f_p_s).flags, '-'))) ?
	// 			((str[1][0] = '0') && (str[1][1] = ho)) :
	// 				((str[0][0] = '0') && (str[0][1] = ho));
	// 		// str[0][0] = '0';
	// 		// str[0][1] = ho;
	// 	}
	if (f_p_s->is_minus)
		ft_xo_write_min(f_p_s, ptr, ho, str);
	else
		ft_xo_write(f_p_s, ptr, ho, str);
}

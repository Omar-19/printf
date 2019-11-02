/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:40:19 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 19:40:48 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		lib_int_help(int *i, t_param *f_p_s, int u)
{
	*i = 0;
	if (u)
	{
		f_p_s->is_plus = 0;
		f_p_s->is_space = 0;
	}
}

char		*ft_itoa_d(long long int value_i,
	unsigned long long value_u, t_param *f_p_s, int u)
{
	t_intp	par;
	int		i;

	lib_int_help(&i, f_p_s, u);
	itoa_flag_handling(value_i, value_u, f_p_s, &par);
	par.val[1] = par.val[0];
	while (par.val[1] /= 10)
		++f_p_s->len;
	par.size = ++f_p_s->len;
	((!par.val[0]) && (f_p_s->is_pres) && (f_p_s->precision == 0))
		? (--f_p_s->len) : 0;
	par.str = (char *)malloc(sizeof(char) * f_p_s->len + 1);
	par.str[f_p_s->len] = '\0';
	(par.flag == 3) ? (++i && (par.str[0] = '+')) : 0;
	(par.flag == 1) ? (++i && (par.str[0] = '-')) : 0;
	while (--par.size > i - 1)
	{
		par.str[par.size] = '0' + par.val[0] % 10;
		par.val[0] /= 10;
	}
	ft_result_len_int(f_p_s);
	ft_write_tail_int(f_p_s, par.str);
	return (par.str);
}

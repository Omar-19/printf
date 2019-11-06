/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_help_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:14:25 by btheia            #+#    #+#             */
/*   Updated: 2019/11/02 22:30:41 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_hex_help1(const char *str, size_t *i,
	va_list elem, t_param *form_place_spc)
{
	char *ptr;

	ptr = NULL;
	if (ft_strstr_num(str, "ll\0", i[0]) || ft_strstr_num(str, "l\0", i[0]) ||
		ft_strstr_num(str, "j\0", i[0]))
		ptr = hex_oct_main(elem, form_place_spc, i[1], 1);
	else if (ft_strstr_num(str, "hh\0", i[0]))
		ptr = hex_oct_main(elem, form_place_spc, i[1], -1);
	else if (ft_strstr_num(str, "h\0", i[0]) && ft_strstr_num(str, "o\0", i[0]))
		ptr = hex_oct_main(elem, form_place_spc, i[1], -2);
	else
		ptr = hex_oct_main(elem, form_place_spc, i[1], 0);
	return (ptr);
}

void	read_char_help(char *ptr, va_list elem, t_param *f_p_s)
{
	char *st;
	char *a;

	ptr = va_arg(elem, void *);
	if (!ptr)
	{
		if (f_p_s->is_pres)
			ptr = ft_strdup("0x");
		else
			ptr = ft_strdup("0x0");
	}
	else
	{
		f_p_s->is_pres = 0;
		ptr = point_hex(&ptr, f_p_s->precision);
		f_p_s->precision = 0;
	}
	if (f_p_s->is_pres)
	{
		a = ft_strnew(ft_strlen(ptr) + f_p_s->precision);
		ft_strcat(a, ptr);
		st = ft_strnewc(f_p_s->precision, '0');
		free(ptr);
		ptr = ft_strdup(ft_strcat(a, st));
		free(a);
		free(st);
		f_p_s->is_pres = 0;
		f_p_s->precision = 0;
	}
	f_p_s->len = ft_strlen(ptr);
	ft_write_tail_str(f_p_s, ptr);
	(ptr) ? free(ptr) : 0;
}

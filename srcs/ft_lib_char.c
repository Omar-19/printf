/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:32 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:34:35 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_result_len_str(t_param *f_p_s)
{
	if (f_p_s->len > f_p_s->precision && f_p_s->precision != 0)
		f_p_s->len = f_p_s->precision;
	f_p_s->result = f_p_s->len;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
}

void	ft_result_len_char(t_param *f_p_s)
{
	f_p_s->result = f_p_s->len;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
	
	// printf("fps->len = %d\n", f_p_s->len);
	// printf("fps->w = %d\n", f_p_s->width);
	// printf("fps->res = %d\n", f_p_s->result);
	
}

void		ft_write_tail_str(t_param *f_p_s, char *ptr)
{
	char *str;

	ft_result_len_str(f_p_s);
	str = ft_strnew_char((f_p_s->result - f_p_s->len), ' ');
	if (ft_strchr((*f_p_s).flags, '-'))
	{
		write(1, ptr, f_p_s->len);
		write(1, str, (f_p_s->result - f_p_s->len));
	}
	else
	{
		write(1, str, (f_p_s->result - f_p_s->len));
		write(1, ptr, f_p_s->len);
	}
	free(str);
}

void		ft_write_tail_char(t_param *f_p_s, char c)
{
	char *str;

	ft_result_len_char(f_p_s);
	// printf("fps->w = %d\n", f_p_s->width);
	// printf("fps->res = %d\n", f_p_s->result);
	str = ft_strnew_char((f_p_s->result - f_p_s->len), ' ');
	if (ft_strchr((*f_p_s).flags, '-'))
	{
		write(1, &c, 1);
		write(1, str, (f_p_s->result - f_p_s->len));
	}
	else
	{
		write(1, str, (f_p_s->result - f_p_s->len));
		write(1, &c, 1);
	}
	free(str);
}

// void		ft_write_tail_percent(t_param *f_p_s)
// {
// 	char *str;

// 	f_p_s->len = 1;
// 	ft_result_len_char(f_p_s);
// 	str = ft_strnew_char((f_p_s->result - f_p_s->len), ' ');
// 	if (ft_strchr((*f_p_s).flags, '-'))
// 	{
// 		write(1, &c, 1);
// 		write(1, str, (f_p_s->result - f_p_s->len));
// 	}
// 	else
// 	{
// 		write(1, str, (f_p_s->result - f_p_s->len));
// 		write(1, &c, 1);
// 	}
// 	free(str);
// }
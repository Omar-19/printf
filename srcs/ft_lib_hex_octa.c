/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_hex_octa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:35:06 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_xo_write_min(t_param *f_p_s, char *ptr, int i[2], char *str[2])
{
	write(1, str[1], i[1]);
	write(1, str[0], i[0]);
	write(1, ptr, f_p_s->len);
}

void	ft_xo_write(t_param *f_p_s, char *ptr, int i[2], char *str[2])
{
	write(1, str[0], i[0]);
	write(1, ptr, f_p_s->len);
	write(1, str[1], i[1]);
}

void	ft_write_tail_xo(t_param *f_p_s, char *ptr, char ho)
{
    int		i[2];
	char	*str[2];
	int		flag;

	// printf("PRES = %d LEN = %d W = %d\n",  f_p_s->precision, f_p_s->len, f_p_s->width);
	ft_result_len_xo(f_p_s);
	//printf("PRES = %d LEN = %d = |%s| W = %d RES = %d\n",  f_p_s->precision, f_p_s->len, ptr, f_p_s->width, f_p_s->result);
	flag = 0;
	if (ft_strchr((*f_p_s).flags, '#'))
		flag = 1;
    //f_p_s->len = ft_strlen(ptr);
    if (f_p_s->len == f_p_s->result)
	{
		write(1, ptr, f_p_s->len);
		return ;
	}
	if ((i[0] = f_p_s->precision - f_p_s->len) < 0)
		i[0] = 0;
	if ((i[1] = f_p_s->result - f_p_s->len - i[0]) < 0)
		i[1] = 0;
	if (ho == 'o' && flag && i[0] == 0)
	{
		++f_p_s->result;
		i[0] = 1;
	}
	if (flag && (ho == 'x' || ho == 'X')) //&& i[1] < 2
	{
		i[0] += 2;
		i[1] -=2;
		if (i[1] < 0)
			f_p_s->result += -i[1];
		//f_p_s->result += 2 - i[]; 0000000000000000000000
		//i[1] = 2;
	}
	str[0] = ft_strnew_char(i[0], '0');
	str[1] = ft_strnew_char(i[1], ' ');
	if (flag)
		if (!(ho == 'o'))
		{
			str[0][0] = '0';
			str[0][1] = ho;
		}
	if (ft_strnew_char(i[0], '-'))
		ft_xo_write_min(f_p_s, ptr, i, str);
	else
		ft_xo_write(f_p_s, ptr, i, str);
	// printf("---------------------%s--", "------------\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:34:32 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:34:35 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_result_len_int(t_param *f_p_s)
{
	(f_p_s->is_pres) ? (f_p_s->is_zero = 0) : 0;
	f_p_s->result = f_p_s->len;
	if (f_p_s->precision > f_p_s->result)
		f_p_s->result = f_p_s->precision;
	if (f_p_s->width > f_p_s->result)
		f_p_s->result = f_p_s->width;
	((f_p_s->precision = f_p_s->precision - f_p_s->len + f_p_s->is_plus) > 0) ?
		0 : (f_p_s->precision = 0);
	((f_p_s->width = f_p_s->result - f_p_s->len - f_p_s->precision) > 0) ?
		0 : (f_p_s->width = 0);
}

void		ft_write_no_min_int(t_param *f_p_s, char *ptr, char *str[2])
{
	if (f_p_s->is_space && !f_p_s->is_plus)
	{
		write(1, " ", 1);
		//(f_p_s->width == f_p_s->precision + f_p_s->len) ? (++f_p_s->result) : 0;
		++f_p_s->result;
		//--f_p_s->precision;
		--f_p_s->width;
	}
	// (f_p_s->is_space && !f_p_s->is_plus) ? ((write(1, " ", 1)) &&
	// 	(++f_p_s->result) && --f_p_s->precision && --f_p_s->width) : 0;
	// printf("f_p_s->width = %d str[1] = |%s|\n", f_p_s->is_width, str[1]);
	(f_p_s->is_zero) ? 0 : (write(1, str[1], f_p_s->width));
	(f_p_s->is_plus) ? ((write(1, ptr++, 1)) && --f_p_s->len) : 0;
	(f_p_s->is_zero) ? (write(1, str[1], f_p_s->width)) : 0;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
}

void		ft_write_min_int(t_param *f_p_s, char *ptr, char *str[2])
{
	if (f_p_s->is_space && !f_p_s->is_plus)
	{
		write(1, " ", 1);
		++f_p_s->result;
		// (f_p_s->width == f_p_s->precision + f_p_s->len) ? (++f_p_s->result) : 0;
		//--f_p_s->precision;
		--f_p_s->width;
	}
	// (f_p_s->is_space && !f_p_s->is_plus) ? ((write(1, " ", 1)) &&
	// 	(++f_p_s->result) && --f_p_s->precision && --f_p_s->width) : 0;
	(f_p_s->is_plus) ? ((write(1, ptr++, 1)) && --f_p_s->len) : 0;
	write(1, str[0], f_p_s->precision);
	write(1, ptr, f_p_s->len);
	write(1, str[1], f_p_s->width);
}

void		ft_write_tail_int(t_param *f_p_s, char *ptr)
{
	char *str[2]; // str[0] - 0 str[1] = ' '
	
	// str[0] = NULL;
	// str[1] = NULL;
	//if (f_p_s->is_pres)
	str[0] = ft_strnew_char(f_p_s->precision, '0');
	// printf("f_p_s->precision = %d str[0] = |%s|\n", f_p_s->precision, str[0]);
	//if (f_p_s->width)
	//{
	(f_p_s->is_zero) ? (str[1] = ft_strnew_char(f_p_s->width, '0')) :
		(str[1] = ft_strnew_char(f_p_s->width, ' '));
	// printf("f_p_s->width = %d str[1] = |%s|\n", f_p_s->width, str[1])
	//}
	(f_p_s->is_minus) ? (ft_write_min_int(f_p_s, ptr, str)) :
		(ft_write_no_min_int(f_p_s, ptr, str));
}

// void		ft_string_processing1(t_param *f_p_s, int *i, int flag, char *str)
// {
// 	while ((*f_p_s).result - i[0] > (*f_p_s).len - i[2])
// 	{
// 		if ((i[0] == 0 || (i[0] == 1 && str[0] != '-')) && flag == 1 && i[1])
// 			str[i[0]] = '-';
// 		else if ((i[0] == 0 || (i[0] == 1 && str[0] != '+'))
// 			&& flag == 3 && i[1])
// 			str[i[0]] = '+';
// 		else if (i[1] == 0)
// 			str[i[0]] = ' ';
// 		else
// 			str[i[0]] = '0';
// 		++i[0];
// 	}
// }

// void		ft_string_processing(t_param *f_p_s, char *str, int flag)
// {
// 	int i[3];

// 	i[2] = 0;
// 	i[0] = 0;
// 	i[1] = 0;
// 	if (flag)
// 		i[2] = 1;
// 	if (ft_strchr((*f_p_s).flags, '0'))
// 		i[1] = 1;
// 	if (ft_strchr((*f_p_s).flags, ' ') && (*f_p_s).width == (*f_p_s).result)
// 		str[i[0]++] = ' ';
// 	ft_string_processing1(f_p_s, i, flag, str);
// 	if (!i[1] && flag == 1)
// 		str[--i[0]] = '-';
// 	else if (!i[1] && flag == 3)
// 		str[--i[0]] = '+';
// 	if ((i[0] == 0 && flag == 1) || (i[0] == 1 && flag == 1 && str[0] != '-'))
// 		str[i[0]] = '-';
// 	else if ((i[0] == 0 && flag == 3) ||
// 		(i[0] == 1 && flag == 3 && str[0] != '+'))
// 		str[i[0]] = '+';
// }

void		itoa_flag_handling(long long int value_i,
	unsigned long long value_u, t_param *f_p_s, t_intp *par)
{
	par->flag = 0;
	f_p_s->len = 0;
	// par->size = 0;
	if (f_p_s->is_plus)
	{
		f_p_s->is_space = 0;
		par->flag = 3;
		++(f_p_s->len);
	}
	if (value_i < 0)
	{
		// printf("-------------------%c", '\n');
		(par->flag != 3) ? (++f_p_s->len) : 0;
		// if (par->flag != 3)
		// 	++par->size;
		f_p_s->is_plus = 1;
		par->flag = 1;
		par->val[0] = -value_i;
	}
	else if (value_i > 0)
		par->val[0] = value_i;
	else
		par->val[0] = value_u;
}

// char		*ft_itoa_d_flagmin(t_intp *par, t_param **f_p_s)
// {
// 	(*par).str = ft_strnew_char((*par).size, '0');
// 	(*par).str[(*par).size--] = '\0';
// 	if ((*par).flag == 3)
// 		(*par).str[0] = '+';
// 	if ((*par).flag == 1)
// 		(*par).str[0] = '-';
// 	(*par).size = (**f_p_s).len--;
// 	while ((*par).val[0] != 0)
// 	{
// 		(*par).str[(**f_p_s).len--] = '0' + (*par).val[0] % 10;
// 		(*par).val[0] /= 10;
// 	}
// 	if ((*par).size == (**f_p_s).len + 1)
// 		(*par).str[(*par).size - 1] = '0';
// 	while ((*par).str[(*par).size] != '\0')
// 		(*par).str[(*par).size++] = ' ';
// 	return ((*par).str);
// }

char		*ft_itoa_d(long long int value_i,
	unsigned long long value_u, t_param *f_p_s, int u)
{
	t_intp	par;
	int		i;

	i = 0;
	(u) ? (f_p_s->is_plus = 0) : 0;
	itoa_flag_handling(value_i, value_u, f_p_s, &par);
	par.val[1] = par.val[0];
	while (par.val[1] /= 10)
		++f_p_s->len;
	par.size = ++f_p_s->len;
	((!par.val[0]) && (f_p_s->is_pres) && (f_p_s->precision == 0)) ? (--f_p_s->len) : 0;
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
	// write(1, par.str, f_p_s->result);
	return (par.str);
}

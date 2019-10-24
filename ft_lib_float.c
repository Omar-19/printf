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

void		ft_flag_correction_1(t_param **f_p_s)
{
	int i;
	
	if (ft_strchr((**f_p_s).flags, '-'))
	{
		i = 0;
		while ((**f_p_s).flags[i] != '\0')
		{
			if ((**f_p_s).flags[i] == '0')
				(**f_p_s).flags[i] = '-';
			++i;
		}
	}
}

void        ft_write_min(char *str, int i, char *ptr, t_param *f_p_s)
{

	if (ptr[0] == '-')
	{
		write(1, ptr, (*f_p_s).len);
		write(1, str, i);
	}
	else if (str[i - 1] == '+')
	{
		write(1, "+", 1);
		write(1, ptr, (*f_p_s).len);
		write(1, str, i - 1);
	}
    else
	{
		if (ft_strchr((*f_p_s).flags, ' '))
		{
			write(1, " ", 1);
			--i;
		}
		write(1, ptr, (*f_p_s).len);
		write(1, str, i);
	}
}

void		ft_write_tail(t_param *f_p_s, char c, char *ptr)
{
	int		i;
	char	*str;
	int		l;

	if (f_p_s->len == f_p_s->result)
	{
		if (ft_strchr((*f_p_s).flags, '+') && c != '-')
		{
			++f_p_s->result;
			write(1, "+", 1);
		}
		else if (ft_strchr((*f_p_s).flags, ' '))
		{
			++f_p_s->result;
			write(1, " ", 1);
		}
		//if (!(ft_strchr((*f_p_s).flags, '+') && c == '-'))
		//	++f_p_s->result;
		write(1, ptr, (*f_p_s).len);
		//printf("\nlen = %d\n", (*f_p_s).len);
		return ;
	}
	i = f_p_s->result - f_p_s->len;
	if (c == '-')
		ft_flag_correction(&f_p_s);
	if (ft_strchr((*f_p_s).flags, '0'))
	{
		if (c == '-')
		{
			++i;
			--f_p_s->len;
			++ptr;
		}
		str = ft_strnew_char(i, '0');
		if (ft_strchr((*f_p_s).flags, '+'))
			(c == '-') ? (str[0] = '-') : (str[0] = '+');
		else if (ft_strchr((*f_p_s).flags, ' '))
			str[0] = ' ';

		write(1, str, i);
		write(1, ptr, (*f_p_s).len);
	}
	else
	{
		str = ft_strnew_char(i, ' ');
		if (ft_strchr((*f_p_s).flags, '+'))
			(c == '-') ? (str[i - 1] = ' ') : (str[i - 1] = '+');
        if (ft_strchr((*f_p_s).flags, '-'))
            ft_write_min(str, i, ptr, f_p_s);
        else
		{
            write(1, str, i);
		    write(1, ptr, (*f_p_s).len);
        }
	}
}

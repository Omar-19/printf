/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:19:07 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 20:38:40 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strstr_num(const char *str, const char *to_find, size_t len)
{
	const char *a;
	const char *b;

	while (len > 0)
	{
		a = str;
		b = to_find;
		while (*(a++) == *(b++))
		{
			if (*b == '\0')
				return (1);
		}
		++str;
		--len;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++) != '\0')
		++i;
	return (i);
}

void	ft_flag_correction(t_param *f_p_s)
{
	if (!f_p_s->is_plus)
	{
		f_p_s->is_plus = 1;
		f_p_s->is_space = 0;
	}
}

void	ft_flag_correction3(t_param *f_p_s)
{
	if (f_p_s->is_plus)
		f_p_s->is_space = 0;
}

void	ft_flag_correction2(t_param **f_p_s)
{
	int i;

	i = 0;
	if (!(ft_strchr((**f_p_s).flags, '+')))
	{
		while ((**f_p_s).flags[i] != '\0')
		{
			if ((**f_p_s).flags[i] == '+')
				(**f_p_s).flags[i] = ' ';
			++i;
		}
	}
}

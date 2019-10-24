/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:35:06 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_result_len(t_param *f_p_s, int flag)
{
	int f;

	f = 0;
	if (flag)
		f = 1;
	if ((*f_p_s).precision > (*f_p_s).len)
		(*f_p_s).len = (*f_p_s).precision + f;
	(*f_p_s).result = (*f_p_s).len;
	if ((*f_p_s).result < (*f_p_s).width)
		(*f_p_s).result = (*f_p_s).width;
	if (ft_only_space((*f_p_s).flags) && (*f_p_s).width == 0
		&& (*f_p_s).precision == 0)
		++(*f_p_s).result;
	return ((*f_p_s).result);
}

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

char		*ft_strnew_char(int size, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		ptr[i++] = c;
	ptr[i] = '\0';
	return (ptr);
}

char		*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr != '\0' || (*ptr == '\0' && c == '\0'))
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

int			ft_only_space(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str != ' ')
			return (0);
		++str;
	}
	return (1);
}

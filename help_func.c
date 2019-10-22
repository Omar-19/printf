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

int			ft_only_space(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ')
			return (0);
		++str;
	}
	return (1);
}

int			ft_result_len(t_param *f_p_s, int flag)
{
	int f;

	f = 0;
	//-----------
	if (flag)
		f = 1;
	if ((*f_p_s).precision > (*f_p_s).len)
		(*f_p_s).len = (*f_p_s).precision + f;
	(*f_p_s).result = (*f_p_s).len;
	if ((*f_p_s).result < (*f_p_s).width)
		(*f_p_s).result = (*f_p_s).width;
	if (ft_only_space((*f_p_s).flags))
		++(*f_p_s).result;
	return ((*f_p_s).result);
}

char	*ft_strchr(const char *s, int c)
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

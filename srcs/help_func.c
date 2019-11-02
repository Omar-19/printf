/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:04 by fyuko             #+#    #+#             */
/*   Updated: 2019/11/02 20:38:05 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_result_len_float(t_param *f_p_s, char c)
{
	if (c == '-' || f_p_s->is_plus)
		f_p_s->is_space = 0;
	if ((*f_p_s).precision > (*f_p_s).len)
		(*f_p_s).len = (*f_p_s).precision;
	(*f_p_s).result = (*f_p_s).len;
	if ((*f_p_s).result < (*f_p_s).width)
		(*f_p_s).result = (*f_p_s).width;
	if (f_p_s->is_space && (*f_p_s).width == 0
		&& (*f_p_s).precision == 0)
		++(*f_p_s).result;
	return ((*f_p_s).result);
}

void	ft_flag_correction_1(t_param *f_p_s)
{
	if (f_p_s->is_minus)
		f_p_s->is_zero = 0;
}

char	*ft_strnew_char(int size, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		ptr[i++] = c;
	ptr[i] = '\0';
	return (ptr);
}

int		ft_only_space(char *str)
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

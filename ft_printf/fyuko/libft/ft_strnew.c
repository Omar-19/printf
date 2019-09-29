/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:51:43 by fyuko             #+#    #+#             */
/*   Updated: 2019/09/10 21:11:05 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(size + 1 > size))
		return (NULL);
	if (!(ptr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		ptr[i] = '\0';
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}

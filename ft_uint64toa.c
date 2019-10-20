/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint64toa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:23:15 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 17:23:34 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		raz(__uint128_t num)
{
	int res;

	res = 0;
	while (num)
	{
		res++;
		num /= 10;
	}
	return (res);
}

char	*ft_uint64toa(uint64_t a, int d)
{
	__uint128_t	num;
	int			ras;
	char		*result;

	num = a;
	ras = 19;
	if (d == 0)
		ras = raz(num);
	if (!(result = ft_strnew(ras--)))
		return (NULL);
	while (ras >= 0)
	{
		result[ras] = num % 10 + '0';
		num /= 10;
		ras--;
	}
	return (result);
}

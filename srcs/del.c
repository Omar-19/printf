/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:07:16 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 16:08:21 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*del1_one(uint64_t *tmp, int deg, int ndb, int t)
{
	int			o;
	int			d[t];
	__uint128_t	a[3];
	int			i;

	init_help_del1(a, &o, deg);
	i = search_non(tmp, ndb - 1) - 1;
	umn1(tmp, -1, &i, ndb);
	while (++i < ndb)
	{
		a[2] = tmp[i] + a[1] * 10000000000000000000U;
		tmp[i] = a[2] / a[0];
		d[++o] = tmp[i];
		a[1] = a[2] % a[0];
	}
	while (++o < t)
	{
		a[1] *= 10;
		d[o] = a[1] / a[0];
		a[1] = a[1] % a[0];
	}
	return (mastos(d, t));
}

char	*mastos(int *a, int t)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = ft_strnew(t + 1)))
		return (NULL);
	while (i < t)
	{
		res[i] = a[i] + '0';
		++i;
	}
	return (res);
}

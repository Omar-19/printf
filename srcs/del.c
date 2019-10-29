/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:07:16 by btheia            #+#    #+#             */
/*   Updated: 2019/10/29 22:30:34 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*del1_one(uint64_t *tmp, int deg, int ndb, int t)
{
	int			o;
	int			d[t + ndb];
	__uint128_t	a[3];
	int			i;

	init_help_del1(a, &o, deg);
	i = search_non(tmp, ndb) - 1;
	if (i == -1)
		return (ft_strnewc(t + 1, '0'));
	umn1(tmp, -1, &i, ndb);
	while (++i < ndb)
	{
		a[2] = (__uint128_t)tmp[i] + (a[1] * 10000000000000000000UL);
		tmp[i] = a[2] / a[0];
		d[++o] = tmp[i];
		if (tmp[i] == 10)
			d[o] = 0;
		a[1] = a[2] % a[0];
	}
	while (++o < t)
	{
		a[1] *= (__uint128_t)10;
		d[o] = (a[1] / a[0]);
		a[1] = a[1] % a[0];
	}
	return (mastos(d, t));
}

char	*mastos(int *a, int t)
{
	int		i;
	char	res[t + 1];

	i = 0;
	while (i < t)
	{
		res[i] = a[i] + '0';
		++i;
	}
	return (strdup(res));
}

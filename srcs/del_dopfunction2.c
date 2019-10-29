/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dopfunction2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:08:03 by btheia            #+#    #+#             */
/*   Updated: 2019/10/29 22:30:59 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	del_m(uint64_t *tmp, int deg, int *min, int ndb)
{
	__uint128_t		b;
	__uint128_t		carry;
	__uint128_t		cur;
	int				i;

	i = *min - 1;
	b = (__uint128_t)2 << (deg - 1);
	carry = 0;
	cur = 0;
	while (++i < ndb)
	{
		cur = (__uint128_t)tmp[i] + (carry * 10000000000000000000UL);
		tmp[i] = cur / b;
		carry = cur % b;
	}
}

char	*del(uint64_t *tmp, int deg, int ndb, int t)
{
	int i;
	int min1;

	min1 = search_non(tmp, ndb);
	i = -1;
	if (deg <= 64)
		return (del1_one(tmp, deg, ndb, t));
	else
	{
		if (deg % 64)
		{
			del_m(tmp, deg % 64, &min1, ndb);
		}
		// for (int i = 0; i < ndb;i++)
		// 	printf("%llu\n", tmp[i]);
		min1 = search_non(tmp, ndb);
		while (++i < deg / 64 - 1)
		{
			del_m(tmp, 64, &min1, ndb);
		}
		return (del1_one(tmp, 64, ndb, t));
	}
}

int		search_non(uint64_t *tmp, int ndb)
{
	int i;

	i = 0;
	while (i < ndb)
	{
		if (tmp[i])
			return (i);
		++i;
	}
	return (0);
}

void	init_help_del1(__uint128_t *a, int *o, int deg)
{
	a[0] = (__uint128_t)2 << (deg - 1);
	a[1] = 0;
	*o = -1;
}

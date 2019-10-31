/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_umn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:08:48 by btheia            #+#    #+#             */
/*   Updated: 2019/10/31 19:04:16 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	break_umn(uint64_t *tmp, int pos, int *min, __uint128_t s)
{
	tmp[pos] = s;
	--(*min);
}

int		help_umn(uint64_t *tmp, int pos, __uint128_t f, __uint128_t *s)
{
	tmp[pos] = f % RAZR;
	*s = f / RAZR;
	return (1);
}

void	init_help(__uint128_t *s, __uint128_t *c, int *i, int deg)
{
	if (deg > 0)
		*c = ((__uint128_t)2 << (deg - 1));
	else if (deg < 0)
		*c = (__uint128_t)10;
	else
		*c = (__uint128_t)1;
	*s = 0;
	*i = -1;
}

void	umn1(uint64_t *tmp, int deg, int *min, int ndb)
{
	int			i;
	__uint128_t	a[3];

	init_help(&a[1], &a[2], &i, deg);
	while (*min <= ndb - (++i))
	{
		if (a[1])
		{
			if ((a[0] = (__uint128_t)tmp[ndb - i] * a[2] + a[1]) > RAZR - 1)
			{
				if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
					return (break_umn(tmp, ndb - i - 1, min, a[1]));
				++i;
			}
			else if (*min == ndb - i)
				return (break_umn(tmp, ndb - i, min, a[0]));
		}
		if ((a[0] = (__uint128_t)tmp[ndb - i] * a[2] + a[1]) > RAZR - 1)
		{
			if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
				return (break_umn(tmp, ndb - i - 1, min, a[1]));
		}
		else
			tmp[ndb - i] = a[0];
	}
}

void	umn(uint64_t *tmp, int deg, int *min, int ndb)
{
	int i;

	i = -1;
	if (deg <= 62)
	{
		umn1(tmp, deg, min, ndb);
		return ;
	}
	else
	{
		if (deg % 62)
			umn1(tmp, deg % 62, min, ndb);
		while (++i < deg / 62)
			umn1(tmp, 62, min, ndb);
	}
}


__uint128_t pow_5(int n)
{
	__uint128_t a = 5;
	__uint128_t res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return (res);
}

void	init_help5(__uint128_t *s, __uint128_t *c, int *i, int deg)
{
	if (deg > 0)
		*c = pow_5(deg);
	else if (deg < 0)
		*c = (__uint128_t)10;
	else
		*c = (__uint128_t)1;
	*s = 0;
	*i = -1;
}

void	umn5_1(uint64_t *tmp, int deg, int *min, int ndb)
{
	int			i;
	__uint128_t	a[3];

	init_help5(&a[1], &a[2], &i, deg);
	while (*min <= ndb - (++i))
	{
		if (a[1])
		{
			if ((a[0] = (__uint128_t)tmp[ndb - i] * a[2] + a[1]) > RAZR - 1)
			{
				if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
					return (break_umn(tmp, ndb - i - 1, min, a[1]));
				++i;
			}
			else if (*min == ndb - i)
				return (break_umn(tmp, ndb - i, min, a[0]));
		}
		if ((a[0] = (__uint128_t)tmp[ndb - i] * a[2] + a[1]) > RAZR - 1)
		{
			if ((help_umn(tmp, ndb - i, a[0], &a[1])) && *min == ndb - i)
				return (break_umn(tmp, ndb - i - 1, min, a[1]));
		}
		else
			tmp[ndb - i] = a[0];
	}
}

void	umn5(uint64_t *tmp, int deg, int *min, int ndb)
{
	int i;

	i = -1;
	if (deg <= 27)
	{
		umn5_1(tmp, deg, min, ndb);
		return ;
	}
	else
	{
		if (deg % 27)
			umn5_1(tmp, deg % 27, min, ndb);
		while (++i < deg / 27)
			umn5_1(tmp, 27, min, ndb);
	}
}

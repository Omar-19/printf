/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_funchelp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:14:56 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 17:25:59 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sum_mhelp(__uint128_t *s, int *i)
{
	*s = 0;
	*i = -1;
}

void	sum_mhelp2(__uint128_t *s, __uint128_t f, int pos, uint64_t *res)
{
	res[pos] = f % 10000000000000000000U;
	*s = f / 10000000000000000000U;
}

char	*get_val(char *s)
{
	char *res;
	char *l;

	l = strrchr(s, '1');
	res = ft_strnew(l - s + 1);
	memmove(res, s, l - s + 1);
	return (res);
}

char	*ft_strnewc(size_t n, char c)
{
	char *res;

	res = ft_strnew(n);
	memset(res, c, n);
	return (res);
}

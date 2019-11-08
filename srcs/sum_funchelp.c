/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_funchelp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:14:56 by btheia            #+#    #+#             */
/*   Updated: 2019/11/08 12:11:36 by btheia           ###   ########.fr       */
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

	l = ft_strrchr(s, '1');
	res = ft_strnew(l - s + 1);
	ft_memmove(res, s, l - s + 1);
	return (res);
}

char	*ft_strnewc(size_t n, char c)
{
	char *res;

	res = ft_strnew(n);
	ft_memset(res, c, n);
	return (res);
}

char	*okrug_zero(char **r, int sign)
{
	char	*point;
	char	*s;
	int		i;
	int 	ch;

	s = *r;
	ch = 0;
	point = ft_strchr(s, '.');
	i = point - s + 2;
	if (s[i-- - 1] >= '5')
	{
		while (--i >= 0)
		{
			if (s[i] != '9' && s[i] != '.')
			{
				if (ch && (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8'))
					break ;
				s[i] += 1;
				break ;
			}
			ch = 0;
			(s[i] != '.') ? s[i] = '0' : ++ch;
		}
		if (i == -1 && (*(s - 1) = '1'))
			pres2(&i, &s, r);
	}
	ft_memset(point, '\0', ft_strlen(point));
	(sign == 1) ? set_min(r, '-') : 0;
	return (ft_strdup(*r));
}
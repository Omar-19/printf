/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dopfunction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:01:44 by btheia            #+#    #+#             */
/*   Updated: 2019/10/31 23:10:05 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_min(char **d, char c)
{
	char *res;

	res = *d - 1;
	res[0] = c;
	*d = res;
}

int		check_c(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
			return (1);
		++i;
	}
	return (0);
}

int	okrug1(char **d, int t)
{
	char	*point;
	char	*s;
	int		i;
	int 	ch;

	ch = 0;
	s = *d;
	point = strchr(s, '.');
	i = point - s + t + 1;
	if (check_c(point + 1) == 1 && s[i] >= '5')
	{
		while (--i >= 0)
		{
			if (s[i] != '9' && s[i] != '.')
			{
				s[i] += 1;
				break ;
			}
			(s[i] != '.') ? s[i] = '0' : 0;
		}
		if (i == -1)
		{
			*(s - 1) = '1';
			*d = s - 1;
			ch = 1;
		}
	}
	memset(point + t + 1, '\0', strlen(point));
	if (t == 0)
		memset(point, '\0', strlen(point));
	return (ch);
}

char	*drob(char *s, int t)
{
	int		max_deg;
	int		n1;
	size_t	m1;

	max_deg = strlen(s);
	n1 = max_deg / 10 + 1;
	if (max_deg == 0 || !strrchr(s, '1'))
		return (ft_strnewc(t, '0'));
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1(s, m1 + 1, max_deg, t));
}

int		col_zero(uint64_t *a, int min, size_t m1, int max_deg)
{
	int b;

	b = raz(a[min]);
	return (max_deg - b - 19 * (m1 - min - 1));
}

char	*cr_sdc_drob(uint64_t *a, int min, size_t m1, int max_deg)
{
	char *res;
	int len;
	int l;

	// for (int k = min; k < m1; k++)
	// 		printf("%.19llu ", a[k]);
	// printf("\n");
	l = col_zero(a, min, m1, max_deg) + 1;
	len = 19 * (m1 - min) + l;
	if (!(res = ft_strnew(len)))
		return (NULL);
	memset(res, '0', len);
	res[l] = '\0';
	strcat(res, ft_uint64toa(a[min++], 0));
	while ((size_t)min < m1)
	{
		strcat(res, ft_uint64toa(a[min], 1));
		++min;
	}
	return (res);
}

char	*drob1(char *s, size_t m1, int max_d, int t)
{
	uint64_t	res[m1];
	uint64_t	tmp[m1];
	int			i;
	int			res_n;
	int			tmp_n;

	res_n = m1 - 1;
	tmp_n = m1 - 1;
	i = -1;
	init_massiv(res, tmp, m1);
	while (s[++i])
	{
		if (s[i] == '1')
		{
			umn1(res, -1, &res_n, m1);
			umn5(tmp, i + 1, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
	}
	// for (int k = 0; k < m1; k++)
	// 	printf("%llu\n", res[k]);
	return (strdup("1"));
}

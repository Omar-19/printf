#include "header.h"

void	get_mantis_d(t_double d, char *s, int type)
{
	int		i;
	int		j;
	char 	*n;

	n = NULL;
	j = 63 - 12 * type;
	i = type;
	while (j >= 0)
	{
		s[i] = ((*(__uint128_t *)(&d.numld) >> j) & 1) + '0';
		(s[i] == '0' && !n) ? (n = &s[i]) : 0;
		(s[i] == '1') ? (n = NULL) : 0;
		++i;
		--j;
	}
	s[i] = 0;
	(n != NULL) ? *n = 0 : 0;
}

char	*get_point_part2(char *m, int t)
{
	int		max_deg;
	int		n1;
	size_t	m1;

	max_deg = strlen(m);
	n1 = (max_deg - 1)/ 10 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1(m, m1 + 1, max_deg, t));
}

char	*get_point_part(char *m, int p, int t)
{
	int		max_deg[2];
	int		n1;
	size_t	m1;

	max_deg[0] = -1 * p + strlen(m) - 1;
	max_deg[1] = strlen(m);
	n1 = (max_deg[0] - strlen(m) + 1) / 10 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1_new(m, m1 + 1, max_deg, t));
}

char	*drob1_new(char *s, size_t m1, int *max_d, int t)
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
			umn(tmp, max_d[1] - i - 1, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
	}
	return (del(res, max_d[0], m1, t));
}

char	*cr_dc_new(char *s, size_t m1, int max_deg, int i)
{
	uint64_t	res[m1];
	uint64_t	tmp[m1];
	int			res_n;
	int			tmp_n;

	res_n = m1 - 1;
	tmp_n = m1 - 1;
	init_massiv(res, tmp, m1);
	while (s[i] && i < max_deg + 1)
	{
		if (s[i] == '1')
		{
			umn(tmp, max_deg - i, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
		++i;
	}
	return (cr_sdc(res, res_n, m1));
}

char	*get_dec_part(char *m, int p)
{
	int		max_deg;
	size_t	m1;
	int		n1;

	max_deg = p;
	n1 = max_deg / 10 + 1;
	m1 = (n1 * 3) / 19 + 1;
	return (cr_dc_new(m, m1 + 1, max_deg, 0));
}

char	*res_last_new(char *dec, char *point, int prs, int sign)
{
	char *rs;
	char *jk;

	rs = ft_strnew(strlen(dec) + 3 + strlen(point));
	jk = rs + 2;
	strcat(rs + 2, dec);
	strcat(rs + 2, ".");
	strcat(rs + 2, point);
	okrug1(&jk, prs);
	(sign == 1) ? set_min(&jk, '-') : 0;
	return (jk);
}

char	*get_float_all(char *m, int p, int prs, int sign)
{
	char *dec;
	char *point;

	if (p < 0)
	{
		dec = "0";
		point = get_point_part(m, p, prs);
		// printf("%s\n", point);
	}
	else if (p >= 0 && (size_t)p < strlen(m) - 1)
	{
		dec = get_dec_part(m, p);
		point = get_point_part2(m + p + 1, prs);
	}
	else
	{
		dec = get_dec_part(m, p);
		if (prs == 0)
			return (dec);
		point = ft_strnewc(prs + 1, '0');
		point[0] = '.';
		return (ft_strjoin(dec, point));
	}
	return (res_last_new(dec, point, prs, sign));
}

char	*new_float_d(t_double d, int prs)
{
	int		sign;
	char	mantis[54];
	int		p;

	mantis[0] = '1';
	get_mantis_d(d, mantis, 1);
	sign = (*(__uint128_t *)(&d.numld) >> 63 & 1);
	p = RETD(d.numd);
	return (get_float_all(mantis, p, prs, sign));
}

char	*new_float_ld(t_double d, int prs)
{
	int		sign;
	char	mantis[65];
	int		p;

	get_mantis_d(d, mantis, 0);
	sign = (*(__uint128_t *)(&d.numld) >> 79 & 1);
	p = RETLD(d.numld);
	return (get_float_all(mantis, p, prs, sign));
}

// int main()
// {
// 	// t_double d;
// 	// d.numld = 1313.3131;
// 	// new_float_d(d, 5);
// 	// printf("%Lf\n", d.numld);
// 	// printf("%s\n", new_float_ld(d, 6));
// 	printf("%llo\n", UINT64_MAX);
// 	long long a = UINT64_MAX;
// 	printf("%s\n", octa_int(&a));
// 	// printf("%Lf\n", d.numld);
// }

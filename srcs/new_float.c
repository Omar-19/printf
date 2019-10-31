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

void	get_mm(void *a, char *s)
{
	int		i;
	int		j;
	char 	*n;

	n = NULL;
	j = 51;
	i = 1;
	while (j >= 0)
	{
		s[i] = ((*(uint64_t*)(a) >> j) & 1) + '0';
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
	n1 = max_deg/ 4 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	return (drob1(m, m1 + 1 + max_deg, max_deg, t));
}

char	*get_point_part(char *m, int p, int t)
{
	int		max_deg[2];
	int		n1;
	size_t	m1;

	printf("d %d\n", p);
	max_deg[0] = (-1 * p) + strlen(m) - 1;
	max_deg[1] = strlen(m);
	printf("max = %d\n", max_deg[0]);
	n1 = max_deg[0] / 4 + 1;
	(t < 17) ? t = 18 : t++;
	m1 = (n1 * 3) / 19 + 1;
	printf("%s\n", ft_strnewc(-p, '0'));
	return (drob1_new(m, m1 + 1 + max_deg[0], max_deg, t));
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
	printf("bit %s\n", s);
	while (s[++i])
	{ 
		umn1(res, -1, &res_n, m1);
		if (s[i] == '1')
		{
			printf("s %d\n", max_d[0] - max_d[1] + i + 1);
			umn5(tmp, max_d[0] - max_d[1] + i + 1, &tmp_n, m1 - 1);
			res_n = sum_m(res, tmp, min_i(&res_n, &tmp_n), m1 - 1);
			toone(tmp, m1);
			tmp[m1 - 1] = 1;
			tmp_n = m1 - 1;
		}
	}
	for (int k = 0; k < m1; k++)
		printf("%llu\n", res[k]);
	// return (del(res, max_d[0], m1, t));
	return (cr_sdc_drob(res, res_n, m1, max_d[0]));
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
	char rs[ft_strlen(dec) + (size_t)3 + ft_strlen(point) + 1];
	char *jk;
	int ck;

	memset(rs, 0, ft_strlen(dec) + (size_t)3 + ft_strlen(point));
	jk = rs + 2;
	strcat(rs + 2, dec);
	strcat(rs + 2, ".");
	strcat(rs + 2, point);
	ck = okrug1(&jk, prs);
	(sign == 1) ? set_min(&jk, '-') : 0;
	if (ck && sign)
	{
		printf("dd");
		return (strdup(rs));
	}
	return (strdup(jk));
}

char	*get_float_all(char *m, int p, int prs, int sign)
{
	char *dec;
	char *point;

	if (p < 0)
	{
		dec = strdup("0");
		point = get_point_part(m, p, prs);
	}
	else if (p >= 0 && (size_t)p < strlen(m) - 1)
	{
		dec = get_dec_part(m, p);
		point = get_point_part2(m + p + 1, prs);
	}
	else
	{
		dec = get_dec_part(m, p);
		point = ft_strnewc(prs, '0');
	}
	return (res_last_new(dec, point, prs, sign));
}

char	*new_float_d(t_double d, int prs)
{
	int		sign;
	char	mantis[54];
	int		p;

	mantis[0] = '1';
	get_mm(&d.numd, mantis);
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

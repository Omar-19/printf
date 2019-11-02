/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:26:02 by btheia            #+#    #+#             */
/*   Updated: 2019/11/03 00:32:37 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*res_last3(char *point, int prs, int sign)
{
	int		sp;
	char	*jk;
	int		ck;

	sp = 0;
	while (*point == '0')
	{
		++sp;
		++point;
	}
	char	rs[ft_strlen(point) + 4 + raz(sp)];
	memset(rs, 0, ft_strlen(point) + 4 + raz(sp));
	jk = rs + 1;
	ft_strncat(rs + 1, point, 1);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point + 1);
	ck = okrug1(&jk, prs);
	if (*(jk + 1) != '\0' && *(jk + 1) != '.')
	{
		--sp;
		*(jk + 1) = '\0';
	}
	(sign == 1) ? set_min(&jk, '-'): 0;
	ft_strcat(jk, "e-");
	ft_strcat(jk, ft_uint64toa2(sp + 1, 0));
	if (ck && sign)
		return(strdup(rs));	
	return (strdup(jk));
}

char	*res_last2(char *dc, char *point, int prs, int sign)
{
	char 	rs[ft_strlen(dc) + 5 + ft_strlen(point)+ raz(ft_strlen(dc)) + prs];
	char 	*jk;
	int		ck;

	if (strcmp(dc, "0") == 0)
		return (res_last3(point, prs, sign));
	memset(rs, 0, ft_strlen(dc) + 5 + ft_strlen(point)+ raz(ft_strlen(dc)) + prs);
	jk = rs + 2;
	ft_strncat(rs + 2, dc, 1);
	ft_strcat(rs + 2, ".");
	ft_strcat(rs + 2, dc + 1);
	ft_strcat(rs + 2, point);
	ck = okrug1(&jk, prs);
	(sign == 1) ? set_min(&jk, '-'): 0;
	ft_strcat(jk, "e+");
	ft_strcat(jk, ft_uint64toa2(strlen(dc) - 1, 0));
	free(dc);
	free(point);
	if (ck && sign)
		return(strdup(rs));	
	return (strdup(jk));
}

char	*get_float_all_e(char *m, int p, int prs, int sign)
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
	return (res_last2(dec, point, prs, sign));
}

char	*float_de(t_double d, int prs, int *sign)
{
	// char *o1;
	// char *dc;
	// char *point;
	// char l[65];

	// *sign = 0;
	// ret_byties_float(d, sign, 64, l);
	// o1 = create_mantisfd(l + 12);
	// point = main_p(&o1, RETD(d.numd));
	// dc = memmove(ft_strnew(point - o1), o1, point - o1);
	// return (res_last2(dc, point, prs, *sign));
	// int		sign;
	char	mantis[54];
	int		p;

	printf("dadad");
	mantis[0] = '1';
	get_mm(&d.numd, mantis);
	*sign = (*(__uint128_t *)(&d.numld) >> 63 & 1);
	p = RETD(d.numd);
	return (get_float_all_e(mantis, p, prs, *sign));
}

char	*float_lde(t_double d, int prs, int *sign)
{
	char	mantis[65];
	int		p;

	get_mantis_d(d, mantis, 0);
	*sign = (*(__uint128_t *)(&d.numld) >> 79 & 1);
	p = RETLD(d.numld);
	return (get_float_all_e(mantis, p, prs, *sign));
}

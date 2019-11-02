/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:34:45 by btheia            #+#    #+#             */
/*   Updated: 2019/11/03 00:34:39 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*res_last4_g(char *des, char *point, int sign)
{
	char	*jk;
	char	*rs;
	int		i;

	rs = ft_strnew(7);
	jk = rs + 1;
	ft_strcat(rs + 1, des);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point);
	okrug1(&jk, 6 - strlen(des));
	if (sign == 1)
		set_min(&jk, '-');
	i = strlen(jk) - 1;
	while (jk[i] == '0')
		i--;
	jk[i + 1] = '\0';
	return (jk);
}

char	*res_last3_g(char *point, int prs, int sign)
{
	char	*jk;
	char	*rs;
	int		i;

	rs = ft_strnew(ft_strlen(point) + 2);
	jk = rs + 1;
	ft_strncat(rs + 1, "0", 1);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point);
	okrug1(&jk, prs);
	if (sign == 1)
		set_min(&jk, '-');
	i = strlen(jk) - 1;
	while (jk[i] == '0')
		i--;
	jk[i + 1] = '\0';
	return (jk);
}

char	*res_last_g(char *dc, char *point, int prs, int sign)
{
	char *resdec;
	char *rs;
	char *jk;
	char *dec_x;

	resdec = dc;
	dec_x = point;
	if (strcmp(resdec, "0") == 0)
		return (res_last3_g(dec_x, 6, sign));
	if (strlen(resdec) < 6)
		return (res_last4_g(resdec, dec_x, sign));
	rs = ft_strnew(ft_strlen(resdec) + 5 + ft_strlen(dec_x)
		+ raz(ft_strlen(resdec)));
	jk = rs + 1;
	ft_strncat(rs + 1, resdec, 1);
	ft_strcat(rs + 1, ".");
	ft_strncat(rs + 1, resdec + 1, 5);
	okrug1(&jk, prs);
	if (sign == 1)
		set_min(&jk, '-');
	ft_strcat(jk, "e+");
	ft_strcat(jk, ft_uint64toa2(strlen(resdec) - 1, 0));
	return (jk);
}

char	*float_dg(t_double d, int prs, int *sign)
{
	char *o1;
	char *dc;
	char *point;
	char l[65];

	*sign = 0;
	ret_byties_float(d, sign, 64, l);
	o1 = create_mantisfd(l + 12);
	point = main_p(&o1, RETD(d.numd));
	dc = memmove(ft_strnew(point - o1), o1, point - o1);
	return (res_last_g(dc, point, prs, *sign));
}

char	*float_ldg(t_double d, int prs, int *sign)
{
	char *o1;
	char *dc;
	char *point;
	char l[81];

	*sign = 0;
	ret_byties_float(d, sign, 80, l);
	o1 = strdup(l + 16);
	point = main_p(&o1, RETLD(d.numld));
	dc = memmove(ft_strnew(point - o1), o1, point - o1);
	return (res_last_g(dc, point, prs, *sign));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_my.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:51:16 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 18:04:51 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*create_mantisfd(char *s)
{
	char	*res;

	if (!(res = ft_strnew(strlen(s) + 1)))
		return (NULL);
	res[0] = '1';
	memmove(res + 1, s, strlen(s));
	return (res);
}

char	*res_last(char *dc, char *point, int prs, int sign)
{
	char *resdec;
	char *dec_x;
	char *rs;
	char *jk;

	resdec = main_c(dc);
	dec_x = drob(point + 1, prs);
	rs = ft_strnew(strlen(resdec) + 2 + strlen(dec_x));
	jk = rs + 1;
	strcat(rs + 1, resdec);
	strcat(rs + 1, ".");
	strcat(rs + 1, dec_x);
	okrug1(&jk, prs);
	if (sign == 1)
		set_min(&jk, '-');
	return (jk);
}

char	*float_f(t_double d, int prs, int *sign)
{
	char *o1;
	char *dc;
	char *point;
	char l[33];

	*sign = 0;
	ret_byties_float(d, sign, 32, l);
	o1 = create_mantisfd(l + 9);
	point = main_p(&o1, RETF(d.numf));
	dc = memmove(ft_strnew(point - o1), o1, point - o1);
	return (res_last(dc, point, prs, *sign));
}

char	*float_d(t_double d, int prs, int *sign)
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
	return (res_last(dc, point, prs, *sign));
}

char	*float_ld(t_double d, int prs, int *sign)
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
	return (res_last(dc, point, prs, *sign));
}
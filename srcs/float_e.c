/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_eg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:26:02 by btheia            #+#    #+#             */
/*   Updated: 2019/10/27 16:33:35 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*res_last3(char *point, int prs, int sign)
{
	int sp;
	char *rs;
	char *jk;

	sp = 0;
	while (*point == '0')
	{
		++sp;
		++point;
	}
	rs = ft_strnew(ft_strlen(point) + 4 + raz(sp));
	jk = rs + 1;
	ft_strncat(rs + 1, point, 1);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, point + 1);
	okrug1(&jk, prs);
	if	(*(jk + 1) != '\0' && *(jk + 1) != '.')
	{
		--sp;
		*(jk + 1) = '\0';
	}
	if (sign == 1)
		set_min(&jk, '-');
	ft_strcat(jk, "e-");
	ft_strcat(jk, ft_uint64toa2(sp + 1, 0));
	return (jk);
}

char	*res_last2(char *dc, char *point, int prs, int sign)
{
	char *resdec;
	char *rs;
	char *jk;
	char *dec_x;

	resdec = main_c(dc);
	dec_x = drob(point + 1, prs);
	if (strcmp(resdec, "0") == 0)
		return (res_last3(dec_x, prs, sign));
	rs = ft_strnew(ft_strlen(resdec) + 5 + ft_strlen(dec_x)+ raz(ft_strlen(resdec)));
	jk = rs + 1;
	ft_strncat(rs + 1, resdec, 1);
	ft_strcat(rs + 1, ".");
	ft_strcat(rs + 1, resdec + 1);
	ft_strcat(rs + 1, dec_x);
	okrug1(&jk, prs);
	if (sign == 1)
		set_min(&jk, '-');
	ft_strcat(jk, "e+");
	ft_strcat(jk, ft_uint64toa2(strlen(resdec) - 1, 0));
	return (jk);
}

char	*float_de(t_double d, int prs, int *sign)
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
	return (res_last2(dc, point, prs, *sign));
}

char	*float_lde(t_double d, int prs, int *sign)
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
	return (res_last2(dc, point, prs, *sign));
}

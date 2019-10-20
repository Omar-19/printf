/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_octa_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:18:02 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 16:21:29 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	hex_intc(char *s, int p)
{
	char c;

	strcmp(s, "0000") == 0 ? c = '0' : 0;
	strcmp(s, "0001") == 0 ? c = '1' : 0;
	strcmp(s, "0010") == 0 ? c = '2' : 0;
	strcmp(s, "0011") == 0 ? c = '3' : 0;
	strcmp(s, "0100") == 0 ? c = '4' : 0;
	strcmp(s, "0101") == 0 ? c = '5' : 0;
	strcmp(s, "0110") == 0 ? c = '6' : 0;
	strcmp(s, "0111") == 0 ? c = '7' : 0;
	strcmp(s, "1000") == 0 ? c = '8' : 0;
	strcmp(s, "1001") == 0 ? c = '9' : 0;
	strcmp(s, "1010") == 0 ? c = 'a' - p : 0;
	strcmp(s, "1011") == 0 ? c = 'b' - p : 0;
	strcmp(s, "1100") == 0 ? c = 'c' - p : 0;
	strcmp(s, "1101") == 0 ? c = 'd' - p : 0;
	strcmp(s, "1110") == 0 ? c = 'e' - p : 0;
	strcmp(s, "1111") == 0 ? c = 'f' - p : 0;
	return (c);
}

char	*hex_int(void *a, int typ, int p, int sd)
{
	char	res[17];
	char	buf[5];
	int		j;
	int		i;

	i = typ - 1;
	j = -1;
	memset(res, '0', 17);
	while (i >= 0)
	{
		buf[3 - (i % 4)] = ((*(__uint128_t *)a >> i) & 1) + '0';
		buf[4] = '\0';
		if (!(i % 4))
			res[++j] = hex_intc(buf, p);
		i--;
	}
	res[++j] = 0;
	j = 0;
	if (sd)
		while (res[j] == '0')
			j++;
	return (strdup(res + j));
}

char	octa_intc(char *s)
{
	char c;

	c = '0';
	strcmp(s, "000") == 0 ? c = '0' : 0;
	strcmp(s, "001") == 0 ? c = '1' : 0;
	strcmp(s, "010") == 0 ? c = '2' : 0;
	strcmp(s, "011") == 0 ? c = '3' : 0;
	strcmp(s, "100") == 0 ? c = '4' : 0;
	strcmp(s, "101") == 0 ? c = '5' : 0;
	strcmp(s, "110") == 0 ? c = '6' : 0;
	strcmp(s, "111") == 0 ? c = '7' : 0;
	return (c);
}

char	*octa_int(void *a, int typ)
{
	char	res[17];
	char	buf[4];
	int		j;
	int		i;

	i = typ - 1;
	j = -1;
	memset(res, '0', 17);
	while (i >= 0)
	{
		buf[2 - (i % 3)] = ((*(__uint128_t *)a >> i) & 1) + '0';
		buf[3] = '\0';
		if (!(i % 3))
			res[++j] = octa_intc(buf);
		i--;
	}
	res[++j] = 0;
	j = 0;
	while (res[j] == '0')
		j++;
	return (strdup(res + j));
}

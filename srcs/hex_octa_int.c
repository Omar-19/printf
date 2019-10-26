/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_octa_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:18:02 by btheia            #+#    #+#             */
/*   Updated: 2019/10/23 00:46:48 by btheia           ###   ########.fr       */
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

char	*point_hex(void *a)
{
	char	res[65];
	char	buf[5];
	int		j;
	int		i;

	i = 63;
	j = 2;
	memset(res, '0', 64);
	while (i >= 0)
	{
		buf[3 - (i % 4)] = ((*(__uint128_t *)a >> i) & 1) + '0';
		buf[4] = '\0';
		if (!(i % 4))
			res[++j] = hex_intc(buf, 0);
		i--;
	}
	res[++j] = 0;
	j = 0;
	while (res[j] == '0' && j < 15)
		j++;
	res[j - 2] = '0';
	res[j - 1] = 'x';
	return (strdup(res + j - 2));
}

char	*hex_int(void *a, int p)
{
	char	res[17];
	char	buf[5];
	int		j;
	int		i;

	i = 63;
	j = -1;
	memset(res, '0', 16);
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
	while (res[j] == '0' && j < 15)
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

char	*octa_int(void *a)
{
	char	res[23];
	char	buf[4];
	int		j;
	int		i;

	i = 63;
	j = -1;
	memset(res, '0', 22);
	memset(buf, '0', 3);
	while (i >= 0)
	{
		buf[2 - (i % 3)] = ((*(__uint128_t *)a >> i) & 1) + '0';
		buf[3] = '\0';
		if (!(i % 3))
		{
			res[++j] = octa_intc(buf);
			buf[0] = '0';
			buf[1] = '0';
			buf[2] = '0';
		}
		--i;
	}
	res[++j] = 0;
	j = 0;
	// printf("%s\n", res);
	while (res[j] == '0' && j <  21)
		j++;
	return (strdup(res + j));
}

char	*hex_oct_main(va_list elem, t_param *f_p_s, char ho, int ltype)
{
	long long a;
	char *ptr;

	if (ltype == 1)
		a = va_arg(elem, long long);
	else
		a = va_arg(elem, int);
	if (ho == 'X' || ho == 'x')
		ptr = hex_int(&a, 'x' - ho);
	else
		ptr = octa_int(&a);
	(*f_p_s).len = ft_strlen(ptr);
	//printf("len%d")
	// printf("PRES = %d LEN = %d W = %d\n",  f_p_s->precision, f_p_s->len, f_p_s->width);
	ft_write_tail_xo(f_p_s, ptr, ho);
	// printf("PRES = %d LEN = %d W = %d\n",  f_p_s->precision, f_p_s->len, f_p_s->width);
	//ft_write_tail(f_p_s, '0', ptr);
	//printf("PTR = %s\n", ptr);
	return (ptr);
}
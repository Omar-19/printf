/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_octa_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:18:02 by btheia            #+#    #+#             */
/*   Updated: 2019/10/28 20:47:16 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	hex_intc(char *s, int p)
{
	char c;

	(!(*(int*)s ^ *(int*)"0000"))? c = '0' : 0;
	(!(*(int*)s ^ *(int*)"0001"))? c = '1' : 0;
	(!(*(int*)s ^ *(int*)"0010"))? c = '2' : 0;
	(!(*(int*)s ^ *(int*)"0011"))? c = '3' : 0;
	(!(*(int*)s ^ *(int*)"0100"))? c = '4' : 0;
	(!(*(int*)s ^ *(int*)"0101"))? c = '5' : 0;
	(!(*(int*)s ^ *(int*)"0110"))? c = '6' : 0;
	(!(*(int*)s ^ *(int*)"0111"))? c = '7' : 0;
	(!(*(int*)s ^ *(int*)"1000"))? c = '8' : 0;
	(!(*(int*)s ^ *(int*)"1001"))? c = '9' : 0;
	(!(*(int*)s ^ *(int*)"1010"))? c = 'a' - p : 0;
	(!(*(int*)s ^ *(int*)"1011")) ? c = 'b' - p : 0;
	(!(*(int*)s ^ *(int*)"1100")) ? c = 'c' - p : 0;
	(!(*(int*)s ^ *(int*)"1101")) ? c = 'd' - p : 0;
	(!(*(int*)s ^ *(int*)"1110")) ? c = 'e' - p : 0;
	(!(*(int*)s ^ *(int*)"1111")) ? c = 'f' - p : 0;
	return (c);
}

char	*point_hex(void *a)
{
	char	res[17];
	char	buf[5];
	int		j;
	int		i;

	i = 63;
	j = 2;
	memset(res, '0', 17);
	while (i >= 0)
	{
		buf[3 - (i % 4)] = ((*(long long *)a >> i) & 1) + '0';
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

char	*hex_int(void *a, int p, int type)
{
	char	res[17];
	char	buf[5];
	int		j;
	int		i;

	i = type - 1;
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
	(type == 32) ? (i = 7) : (i = 15);
	res[++j] = 0;
	j = 0;
	while (res[j] == '0' &&  j < i)
		j++;
	return (strdup(res + j));
}

char	octa_intc(char *s)
{
	char c;

	c = '0';
	(!(*(int*)s ^ *(int*)"000"))? c = '0' : 0;
	(!(*(int*)s ^ *(int*)"001"))? c = '1' : 0;
	(!(*(int*)s ^ *(int*)"010"))? c = '2' : 0;
	(!(*(int*)s ^ *(int*)"011"))? c = '3' : 0;
	(!(*(int*)s ^ *(int*)"100"))? c = '4' : 0;
	(!(*(int*)s ^ *(int*)"101"))? c = '5' : 0;
	(!(*(int*)s ^ *(int*)"110"))? c = '6' : 0;
	(!(*(int*)s ^ *(int*)"111"))? c = '7' : 0;
	return (c);
}

char	*octa_int(void *a)
{
	char	res[23];
	char	buf[4];
	int		j;
	int		i;

	i = 64 - 1;
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
		a = va_arg(elem, long long);
	if (ho == 'X' || ho == 'x')
		ptr = hex_int(&a, 'x' - ho, 32 + 32 * ltype);
	else if (ho == 'o')
		ptr = octa_int(&a);
	else 
		ptr = bit_out(&a);
	(*f_p_s).len = ft_strlen(ptr);
	ft_write_tail_xo(f_p_s, ptr, ho);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:54:50 by btheia            #+#    #+#             */
/*   Updated: 2019/10/26 14:59:06 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*bit_out(void *a)
{
	char	res[65];
	char	buf[5];
	int		j;
	int		i;

	i = 63;
	j = -1;
	memset(res, '0', 64);
	while (i >= 0)
	{
		res[++j] = ((*(__uint128_t *)a >> i) & 1) + '0';
		i--;
	}
	res[++j] = 0;
	j = 0;
	while (res[j] == '0' && j < 63)
		j++;
	return (strdup(res + j));
}

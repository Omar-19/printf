/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyuko <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:29 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/22 14:35:32 by fyuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*main_p(char **s, int pos)
{
	char *res;

	if (pos >= 0)
	{
		res = ft_strnewc(pos + strlen(*s) + 1, '0');
		memmove(res, *s, strlen(*s));
		res[pos + 1] = ',';
		if (pos < strlen(*s) - 1)
			memmove(res + pos + 2, *s + pos + 1, strlen(*s + pos));
		free(*s);
		*s = res;
		return (&res[pos + 1]);
	}
	else
	{
		pos = -pos + 1;
		res = ft_strnewc(strlen(*s) + pos, '0');
		memmove(res + pos, *s, strlen(*s));
		res[1] = ',';
		free(*s);
		*s = res;
		return (&res[1]);
	}
}

char	*set_p(char *s, int pos)
{
	char	*l;
	int		i;

	l = ft_strnew(strlen(s) + pos + 1);
	i = -1;
	while (++i < pos)
		l[i] = s[i];
	l[pos] = ',';
	memmove(l + pos + 1, s + i, strlen(s + i));
	return (l);
}

int		min_i(int *a, int *b)
{
	if (*a > *b)
		return (*b);
	return (*a);
}

char	*float_c(va_list a, int prs, char *type)
{
	t_double		d;
	char			*l;
	int				sign;

	if (!strncmp("Lf", type, 2))
	{
		d.numld = va_arg(a, long double);
		return (float_ld(d, prs, &sign));
	}
	else if (!strncmp("lf", type, 2))
	{
		d.numd = va_arg(a, double);
		return (float_d(d, prs, &sign));
	}
	else
	{
		d.numf = (float)va_arg(a, double);
		return (float_f(d, prs, &sign));
	}
}

int		main()
{
	//printf("%d\n", printf("%f\n", 0.1234567));
	//printf("%d\n", ft_printf("%f\n", 0.1234567));

	printf("%d\n", printf("%+d\n", -10));
	printf("%d\n", ft_printf("%+d\n", -10));
	// printf("%d\n", printf("---%+5d\n", 10));
	// printf("%d\n", ft_printf("---%+5d\n", 10));
	// printf("%d\n", printf("---%5d\n", -10));
	// printf("%d\n", ft_printf("---%5d\n", -10));
	/*printf("--------------------- %d\n", printf("abc%+010d def\n", 43));
	printf("--------------------- %d\n\n", ft_printf("abc%+010d def\n", 43));

	printf("--------------------- %d\n", printf("abc% +05.5d def\n", 123456));
	printf("--------------------- %d\n\n", ft_printf("abc% +05.5d def\n", 123456));

	printf("--------------------- %d\n", printf("abc% +10d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% +10d def\n", -123456));

	printf("--------------------- %d\n", printf("abc% +.10d def\n", 123456));
	printf("--------------------- %d\n\n", ft_printf("abc% +.10d def\n", 123456));

	printf("--------------------- %d\n", printf("abc% +.10d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% +.10d def\n", -123456));

	printf("--------------------- %d\n", printf("abc%+d def\n", 123456));
	printf("--------------------- %d\n\n", ft_printf("abc%+d def\n", 123456));

	printf("--------------------- %d\n", printf("%c %c %c %%%%%% %s = %ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7));
	printf("--------------------- %d\n\n", ft_printf("%c %c %c %%%%%% %s = %ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7));
	
	printf("--------------------- %d\n", printf("%d\n", 0));
	printf("--------------------- %d\n\n", ft_printf("%d\n", 0));
	
	printf("--------------------- %d\n", printf("abc% 09.7d def\n", -82));
	printf("--------------------- %d\n\n", ft_printf("abc% 09.7d def\n", -82));
	
	printf("--------------------- %d\n", printf("abc% 0*.*d def\n", 5, 7, -123));
	printf("--------------------- %d\n\n", ft_printf("abc% 0*.*d def\n", 5, 7, -123));
	
	printf("--------------------- %d\n", printf("abc%01.*d def\n", 4, 5));
	printf("--------------------- %d\n\n", ft_printf("abc%01.*d def\n", 4, 5));
	
	printf("--------------------- %d\n", printf("abc%010d def\n", -43));
	printf("--------------------- %d\n\n", ft_printf("abc%010d def\n", -43));
	
	printf("--------------------- %d\n", printf("abc% 05.5d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% 05.5d def\n", -123456));
	
	printf("--------------------- %d\n", printf("abc% 10d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% 10d def\n", -123456));
	
	printf("--------------------- %d\n", printf("abc% .10d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% .10d def\n", -123456));
	
	printf("--------------------- %d\n", printf("abc% .10d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc% .10d def\n", -123456));
	
	printf("--------------------- %d\n", printf("abc%d def\n", -123456));
	printf("--------------------- %d\n\n", ft_printf("abc%d def\n", -123456));
	
	printf("--------------------- %d\n", printf("%c\n", 'a'));
	printf("--------------------- %d\n\n", ft_printf("%c\n", 'a'));
	
	printf("--------------------- %d\n", printf("%s\n", "qwert"));
	printf("--------------------- %d\n\n", ft_printf("%s\n", "qwert"));
	
	printf("--------------------- %d\n", printf("%c --- %s\n", 'a', "qawa!"));
	printf("--------------------- %d\n\n", ft_printf("%c --- %s\n", 'a', "qawa!"));
	*/
	/*printf("--------------------- %d\n", printf("%s\n", "*"));
	printf("--------------------- %d\n\n", ft_printf("%s\n", "*"));*/
	return (0);
	//ft_printf("d %s\n", "f");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:35:29 by fyuko             #+#    #+#             */
/*   Updated: 2019/10/26 18:40:37 by btheia           ###   ########.fr       */
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
		//if (pos < strlen(*s) - 1)
		if (pos < 0 || ((unsigned long)pos < strlen(*s) - 1))
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

static void test_func(int a, int b)
{
	if (a == b)
		printf("%d-------------------------------------------------%s\n", a, "OK");
	else
		printf("(sist)%d != %d-------------------------------------------------%s\n", a, b, "FAIL");
}

int		main()
{
	int b;
	int *a;
	char *n;
	char m;
	char *s = "dd";
	n = &m;
	a = &b;
//  	test_func(printf("x%fx\n", 0.1234567), ft_printf("x%fx\n", 0.1234567));

// 	test_func(printf("%+d\n", -10), ft_printf("%+d\n", -10));

	// test_func(printf("---%+5d\n", 10), ft_printf("---%+5d\n", 10));

	// test_func(printf("%-10dd\n", -10), ft_printf("%-10dd\n", -10));

	// test_func(printf("abc%-+010d def\n", 43), ft_printf("abc%-+010d def\n", 43));

	// test_func(printf("abc% -+05.5d def\n", 123456), ft_printf("abc% -+05.5d def\n", 123456));

	// test_func(printf("abc% -+10d def\n", -123456), ft_printf("abc% -+10d def\n", -123456));

// 	test_func(printf("abc%-+10d def\n", 123456), ft_printf("abc%-+10d def\n", 123456));

// 	test_func(printf("abc%-+.10d def\n", 123456), ft_printf("abc%-+.10d def\n", 123456));

// 	test_func(printf("abc%-+d def\n", 0), ft_printf("abc%-+d def\n", 0));

// 	test_func(printf("abc% -+.10d def\n", -123456), ft_printf("abc% -+.10d def\n", -123456));

// 	test_func(printf("abc%-+d def\n", 123456), ft_printf("abc%-+d def\n", 123456));

// 	test_func(printf("%c %c %c %%%%%% %s = %-ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7),
// 					ft_printf("%c %c %c %%%%%% %s = %-ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7));

// 	test_func(printf("%-+6d\n", 0), ft_printf("%-+6d\n", 0));

// 	test_func(printf("abc% -09.7d def\n", -82), ft_printf("abc% -09.7d def\n", -82));

// 	test_func(printf("abc% 0*.*d def\n", 5, 7, -123), ft_printf("abc% 0*.*d def\n", 5, 7, -123));

// 	test_func(printf("abc%01.*d def\n", 4, 5), ft_printf("abc%01.*d def\n", 4, 5));

	// test_func(printf("abc%010d def\n", -43), ft_printf("abc%010d def\n", -43));

	// test_func(printf("abc% 05.5d def\n", -123456), ft_printf("abc% 05.5d def\n", -123456));

	// test_func(printf("abc% 10d def\n", -123456), ft_printf("abc% 10d def\n", -123456));

	// test_func(printf("abc% .10d def\n", -123456), ft_printf("abc% .10d def\n", -123456));

	// test_func(printf("%s\n", "qwert"), ft_printf("%s\n", "qwert"));

	// test_func(printf("%c\n", 'a'), ft_printf("%c\n", 'a'));

	// test_func(printf("%c --- %s\n", 'a', "qawa!"), ft_printf("%c --- %s\n", 'a', "qawa!"));

	// test_func(printf("%s\n", "*"), ft_printf("%s\n", "*"));

// 	test_func(printf("%f\n", 0.1234567), ft_printf("%f\n", 0.1234567));

// 	test_func(printf("% f\n", 0.1234567), ft_printf("% f\n", 0.1234567));

// 	test_func(printf("% +f\n", 0.1234567), ft_printf("% +f\n", 0.1234567));

// 	test_func(printf("%+010f\n", 0.123), ft_printf("%+010f\n", 0.123));

// 	test_func(printf("%+.7f\n", -0.12), ft_printf("%+.7f\n", -0.12));

// 	test_func(printf("%-7f\n", 0.1), ft_printf("%-7f\n", 0.1));

// 	test_func(printf("%-.7f\n", 0.1), ft_printf("%-.7f\n", 0.1));

// 	test_func(printf("x%10fx\n", 0.1), ft_printf("x%10fx\n", 0.1));

// 	test_func(printf("x%-10fx\n", 0.1), ft_printf("x%-10fx\n", 0.1));

// test_func(printf("x%+fx\n", 0.1), ft_printf("x%+fx\n", 0.1));

// test_func(printf("x% fx\n", 0.1), ft_printf("x% fx\n", 0.1));

// test_func(printf("x%+fx\n", 0.1), ft_printf("x% +fx\n", 0.1));

// test_func(printf("x%+fx\n", -0.1), ft_printf("x%+fx\n", -0.1));

// test_func(printf("x% -11fx\n", 0.1), ft_printf("x% -11fx\n", 0.1));

// test_func(printf("x% -11dx\n", -1), ft_printf("x% -11dx\n", -1));

// test_func(printf("x% 11fx\n", 0.1), ft_printf("x% 11fx\n", 0.1));

// test_func(printf("x% +11fx\n", 0.1), ft_printf("x% +11fx\n", 0.1));

// test_func(printf("x% 11fx\n", -0.1), ft_printf("x% 11fx\n", -0.1));

// test_func(printf("x%-11fx\n", 0.1), ft_printf("x%-11fx\n", 0.1));

// test_func(printf("x%-11fx\n", -0.1), ft_printf("x%-11fx\n", -0.1));

// test_func(printf("x%-+11fx\n", 0.1), ft_printf("x%-+11fx\n", 0.1));

// test_func(printf("x% -+11fx\n", 0.1), ft_printf("x% -+11fx\n", 0.1));

// test_func(printf("x% -11fx\n", 0.1), ft_printf("x% -11fx\n", 0.1));

// test_func(printf("x% -+11fx\n", -0.1), ft_printf("x% -+11fx\n", -0.1));

// test_func(printf("x% -11fx\n", -0.1), ft_printf("x% -11fx\n", -0.1));

// test_func(printf("x%-+011fx\n", 0.1), ft_printf("x%-+011fx\n", 0.1));

// test_func(printf("x%-+011fx\n", -0.1), ft_printf("x%-+011fx\n", -0.1));

//test_func(printf("x% 011xx\n", 1), ft_printf("x% 011xx\n", 1));

	// test_func(printf("m%#10.5xm\n", 1), ft_printf("m%#10.5xm\n", 1));

	//ft_printf("m%#10.5xm\n", 1);

	// test_func(printf("m%#10.5Xm\n", 1), ft_printf("m%#10.5Xm\n", 1));

	// test_func(printf("m%#10.5om\n", 1), ft_printf("m%#10.5om\n", 1));

	// test_func(printf("m%10.5om\n", 1), ft_printf("m%10.5om\n", 1));

	// test_func(printf("m%om\n", 0), ft_printf("m%om\n", 0));

	// test_func(printf("m%xm\n", 0), ft_printf("m%xm\n", 0));

	// test_func(printf("m%Xm\n", 0), ft_printf("m%Xm\n", 0));

	// test_func(printf("m%#om\n", 0), ft_printf("m%#om\n", 0));

	// test_func(printf("m%#xm\n", 0), ft_printf("m%#xm\n", 0));

	// test_func(printf("m%#Xm\n", 0), ft_printf("m%#Xm\n", 0));

	//printf("|%-7.10s|\n", "lalala");

	// test_func(printf("|%-7.0s|\n", "lalala"), ft_printf("|%-7.0s|\n", "lalala"));

	// test_func(printf("|%-7.10s|\n", "lalala"), ft_printf("|%-7.10s|\n", "lalala"));

	// test_func(printf("|%7.0s|\n", "lalala"), ft_printf("|%7.0s|\n", "lalala"));

	// test_func(printf("|%7.10s|\n", "lalala"), ft_printf("|%7.10s|\n", "lalala"));

	// test_func(printf("|%.6s|\n", "lalala"), ft_printf("|%.6s|\n", "lalala"));

	// test_func(printf("|%-s|\n", "lalala"), ft_printf("|%-s|\n", "lalala"));

	// test_func(printf("|%.3s|\n", "lalala"), ft_printf("|%.3s|\n", "lalala"));

	// printf("|%3c|\n", 'c');

	// test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

	// test_func(printf("|%-3c|\n", 'c'), ft_printf("|%-3c|\n", 'c'));

	//test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

	// test_func(printf("|%5%%d|\n", 7), ft_printf("|%5%%d|\n", 7));

	// test_func(printf("|%-5%%d|\n", 7), ft_printf("|%-5%%d|\n", 7));

	// test_func(printf("------------|%5%%d|\n", 7), ft_printf("------------|%5%%d|\n", 7));

	// ft_printf("|%10%|\n", 7);

	// test_func(printf("|%d|%%\n", 7), ft_printf("|%d|%%\n", 7));

	// test_func(printf("|%p|\n", n), ft_printf("|%p|\n", n));
	
	// test_func(printf("|%20p|\n", a), ft_printf("|%20p|\n", a));

	// test_func(printf("|%-20p|\n", a), ft_printf("|%-20p|\n", a));

	// test_func(printf("|%20p|\n", n), ft_printf("|%20p|\n", n));

	// test_func(printf("|%-20p|\n", n), ft_printf("|%-20p|\n", n));

	// test_func(printf("|%p|\n", s), ft_printf("|%p|\n", s));

	// test_func(printf("|%20p|\n", &a), ft_printf("|%20p|\n", &a));

	// test_func(printf("|%-20p|\n", &a), ft_printf("|%-20p|\n", &a));

	// printf("|%p|\n", &a);

	// printf("|%20p|\n", &a);

	// printf("|%-20p|\n", &a);

	// printf("|%20p|\n", &a);

	// printf("|%-20p|\n", &a);
	
	//printf("|%-7.0d|\n", 7);

	// printf("m%#10.5xm\n", 1);
	// printf("m%#10.5Xm\n", 1);
	// printf("m%#10.5om\n", 1);
	// printf("m%10.5om\n", 1);

	// test_func(printf("|%-10.0f|\n", -7.111), ft_printf("|%-10.0f|\n", -7.111));
	// printf("|%+10.0f|\n", 0.1);
	// printf("|%+10.0e|\n", 0.1);
	t_double d;
	// d.numd = -0.098;
	d.numld = LDBL_MAX;
	// d.numd = DBL_MAX;
	// int prs = 1;
	int sign = 0;
	// test_func(printf("|%-10.0e|\n", d.numd), ft_printf("|%-10.0e|\n", d.numd));
	// test_func(printf("|%-+20.7e|\n", d.numd), ft_printf("|%-+20.7e|\n", d.numd));
	// test_func(printf("|%+21.7e|\n", d.numd), ft_printf("|%+21.7e|\n", d.numd));
	// test_func(printf("|%e|\n", d.numd), ft_printf("|%e|\n", d.numd));
	// test_func(printf("|%-10.0Le|\n", d.numld), ft_printf("|%-10.0Le|\n", d.numld));
	// test_func(printf("|%-+20.7Le|\n", d.numld), ft_printf("|%-+20.7Le|\n",d.numld));
	// test_func(printf("|%+21.7Le|\n", d.numld), ft_printf("|%+21.7Le|\n", d.numld));
	// test_func(printf("|%Le|\n", d.numld), ft_printf("|%Le|\n", d.numld));
	// printf("%s\n", float_de(d, prs, &sign));

	ft_printf("%b\n", 5);
	//int i = 0;
	//printf("%s\n", float_lde(d, prs, &sign));
	// printf("%lf\n", d.numd);
	// ft_printf("%lf\n", d.numd);
	// printf("%s\n", float_lde(d, prs, &sign));
	// printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "XXX", "YYY");
// 	// char *s = "f";
// 	// test_func(printf("%p\n", s), ft_printf("%p\n", s));
// 	// printf("%X\n", 11);
// 	// ft_printf("%X\n", 11);
// 	// printf("%o\n", 112);
	// test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%o\n", ULLONG_MAX));
	// write(1, NULL, 0);
	// printf("+%+-10o+\n", 7123);
	// test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%llo\n", ULLONG_MAX));
	// test_func(printf("%+ #llx\n", ULLONG_MAX), ft_printf("%+ #llx\n", ULLONG_MAX));
	// printf("%o\n", ULLONG_MAX);
	// ft_printf("%x\n", 0);
	// printf("%#x\n", ULLONG_MAX);
	return (0);
}
// %#o 0 = 0
// %#x 0 = 0

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:56:29 by btheia            #+#    #+#             */
/*   Updated: 2019/10/26 21:06:29 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void test_func(int a, int b)
{
	if (a == b)
		printf("%d-------------------------------------------------%s\n", a, "OK");
	else
		printf("(sist)%d != %d-------------------------------------------------%s\n", a, b, "FAIL");
}

int		main()
{
// 	int b;
// 	int *a;
// 	char *n;
// 	char m;
// 	char *s = "dd";
// 	n = &m;
// 	a = &b;
//  	test_func(printf("x%fx\n", 0.1234567), ft_printf("x%fx\n", 0.1234567));

// 	test_func(printf("%+d\n", -10), ft_printf("%+d\n", -10));

// 	test_func(printf("---%+5d\n", 10), ft_printf("---%+5d\n", 10));

// 	test_func(printf("%-10dd\n", -10), ft_printf("%-10dd\n", -10));

// 	test_func(printf("abc%-+010d def\n", 43), ft_printf("abc%-+010d def\n", 43));

// 	test_func(printf("abc% -+05.5d def\n", 123456), ft_printf("abc% -+05.5d def\n", 123456));

// 	test_func(printf("abc% -+10d def\n", -123456), ft_printf("abc% -+10d def\n", -123456));

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

// 	test_func(printf("abc%010d def\n", -43), ft_printf("abc%010d def\n", -43));

// 	test_func(printf("abc% 05.5d def\n", -123456), ft_printf("abc% 05.5d def\n", -123456));

// 	test_func(printf("abc% 10d def\n", -123456), ft_printf("abc% 10d def\n", -123456));

// 	test_func(printf("abc% .10d def\n", -123456), ft_printf("abc% .10d def\n", -123456));

// 	test_func(printf("%s\n", "qwert"), ft_printf("%s\n", "qwert"));

// 	test_func(printf("%c\n", 'a'), ft_printf("%c\n", 'a'));

// 	test_func(printf("%c --- %s\n", 'a', "qawa!"), ft_printf("%c --- %s\n", 'a', "qawa!"));

// 	test_func(printf("%s\n", "*"), ft_printf("%s\n", "*"));

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

// test_func(printf("x% 011xx\n", 1), ft_printf("x% 011xx\n", 1));

// 	test_func(printf("m%#10.5xm\n", 1), ft_printf("m%#10.5xm\n", 1));

// 	ft_printf("m%#10.5xm\n", 1);

// 	test_func(printf("m%#10.5Xm\n", 1), ft_printf("m%#10.5Xm\n", 1));

// 	test_func(printf("m%#10.5om\n", 1), ft_printf("m%#10.5om\n", 1));

// 	test_func(printf("m%10.5om\n", 1), ft_printf("m%10.5om\n", 1));

// 	test_func(printf("m%om\n", 0), ft_printf("m%om\n", 0));

// 	test_func(printf("m%xm\n", 0), ft_printf("m%xm\n", 0));

// 	test_func(printf("m%Xm\n", 0), ft_printf("m%Xm\n", 0));

// 	test_func(printf("m%#om\n", 0), ft_printf("m%#om\n", 0));

// 	test_func(printf("m%#xm\n", 0), ft_printf("m%#xm\n", 0));

// 	test_func(printf("m%#Xm\n", 0), ft_printf("m%#Xm\n", 0));

// 	printf("|%-7.10s|\n", "lalala");

// 	test_func(printf("|%-7.0s|\n", "lalala"), ft_printf("|%-7.0s|\n", "lalala"));

// 	test_func(printf("|%-7.10s|\n", "lalala"), ft_printf("|%-7.10s|\n", "lalala"));

// 	test_func(printf("|%7.0s|\n", "lalala"), ft_printf("|%7.0s|\n", "lalala"));

// 	test_func(printf("|%7.10s|\n", "lalala"), ft_printf("|%7.10s|\n", "lalala"));

// 	test_func(printf("|%.6s|\n", "lalala"), ft_printf("|%.6s|\n", "lalala"));

// 	test_func(printf("|%-s|\n", "lalala"), ft_printf("|%-s|\n", "lalala"));

// 	test_func(printf("|%.3s|\n", "lalala"), ft_printf("|%.3s|\n", "lalala"));

// 	printf("|%3c|\n", 'c');

// 	test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

// 	test_func(printf("|%-3c|\n", 'c'), ft_printf("|%-3c|\n", 'c'));

// 	test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

// 	test_func(printf("|%5%%d|\n", 7), ft_printf("|%5%%d|\n", 7));

// 	test_func(printf("|%-5%%d|\n", 7), ft_printf("|%-5%%d|\n", 7));

// 	test_func(printf("------------|%5%%d|\n", 7), ft_printf("------------|%5%%d|\n", 7));

// 	ft_printf("|%10%|\n", 7);

// 	test_func(printf("|%d|%%\n", 7), ft_printf("|%d|%%\n", 7));

// 	test_func(printf("|%p|\n", n), ft_printf("|%p|\n", n));
	
// 	test_func(printf("|%20p|\n", a), ft_printf("|%20p|\n", a));

// 	test_func(printf("|%-20p|\n", a), ft_printf("|%-20p|\n", a));

// 	test_func(printf("|%20p|\n", n), ft_printf("|%20p|\n", n));

// 	test_func(printf("|%-20p|\n", n), ft_printf("|%-20p|\n", n));

// 	test_func(printf("|%p|\n", s), ft_printf("|%p|\n", s));

// 	test_func(printf("|%20p|\n", &a), ft_printf("|%20p|\n", &a));

// 	test_func(printf("|%-20p|\n", &a), ft_printf("|%-20p|\n", &a));

// 	printf("|%p|\n", &a);

// 	printf("|%20p|\n", &a);

// 	printf("|%-20p|\n", &a);

// 	printf("|%20p|\n", &a);

// 	printf("|%-20p|\n", &a);
	
// 	printf("|%-7.0d|\n", 7);

// 	printf("m%#10.5xm\n", 1);
// 	printf("m%#10.5Xm\n", 1);
// 	printf("m%#10.5om\n", 1);
// 	printf("m%10.5om\n", 1);

// 	test_func(printf("|%-10.0f|\n", -7.111), ft_printf("|%-10.0f|\n", -7.111));
// 	printf("|%+10.0f|\n", 0.1);
// 	printf("|%+10.0e|\n", 0.1);
// 	t_double d;
// 	d.numd = -0.098;
// 	d.numld = LDBL_MAX;
// 	d.numd = DBL_MAX;
// 	int prs = 1;
// 	int sign = 0;
// 	test_func(printf("|%-10.0e|\n", d.numd), ft_printf("|%-10.0e|\n", d.numd));
// 	test_func(printf("|%-+20.7e|\n", d.numd), ft_printf("|%-+20.7e|\n", d.numd));
// 	test_func(printf("|%+21.7e|\n", d.numd), ft_printf("|%+21.7e|\n", d.numd));
// 	test_func(printf("|%e|\n", d.numd), ft_printf("|%e|\n", d.numd));
// 	test_func(printf("|%-10.0Le|\n", d.numld), ft_printf("|%-10.0Le|\n", d.numld));
// 	test_func(printf("|%-+20.7Le|\n", d.numld), ft_printf("|%-+20.7Le|\n",d.numld));
// 	test_func(printf("|%+21.7Le|\n", d.numld), ft_printf("|%+21.7Le|\n", d.numld));
// 	test_func(printf("|%Le|\n", d.numld), ft_printf("|%Le|\n", d.numld));
// 	printf("%s\n", float_de(d, prs, &sign));

// 	test_func(printf("%s %s", "this", "is"), ft_printf("%s %s", "this", "is"));
// 	test_func(printf("%s %s", "a", "aaaa"), ft_printf("%s %s", "a", "aaaa"))
// 	printf("%s %s", "this", "is");
// 	ft_printf("%s %s %s %s %s", "a", "b", "c", "d", "e");
// 	ft_printf("%s %s", "this", "is");
// 	ft_printf("%s %s", "this", "is");
// 	ft_printf("%s %s", "this", "is");
// 	ft_printf("%s %s", "this", "is");
// 	ft_printf("%s %s", "a", "b");
// 	ft_printf("%b\n", 5);
// 	printf("%g\n", (double)0.1234568);
// 	int i = 0;
// 	printf("%s\n", float_lde(d, prs, &sign));
// 	printf("%lf\n", d.numd);
// 	ft_printf("%lf\n", d.numd);
// 	printf("%s\n", float_lde(d, prs, &sign));
// 	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "XXX", "YYY");
// 	// char *s = "f";
// 	// test_func(printf("%p\n", s), ft_printf("%p\n", s));
// 	// printf("%X\n", 11);
// 	// ft_printf("%X\n", 11);
// 	// printf("%o\n", 112);
// 	test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%o\n", ULLONG_MAX));
// 	write(1, NULL, 0);
// 	printf("+%+-10o+\n", 7123);
// 	test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%llo\n", ULLONG_MAX));
// 	test_func(printf("%+ #llx\n", ULLONG_MAX), ft_printf("%+ #llx\n", ULLONG_MAX));
// 	printf("%o\n", ULLONG_MAX);
// 	ft_printf("%x\n", 0);
// 	printf("%#x\n", ULLONG_MAX);
	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));
	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));

	// test_func(printf("%-10x\n", 42), ft_printf("%-10x\n", 42));

	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));
	// test_func(printf("%#x\n", 0), ft_printf("%#x\n", 0));
	// test_func(printf("%10s\n", NULL), ft_printf("%10s\n", NULL));
	//test_func(printf("|%.03s|\n", "qw"), ft_printf("|%.03s|\n", "qw"));
	// test_func(printf("|%+05d|\n", -7), ft_printf("|%+05d|\n", -7));
	// test_func(printf("|%08.5d|\n", 34), ft_printf("|%08.5d|\n", 34));
	// test_func(printf("|% d|\n", -1), ft_printf("|% d|\n", -1));
	// test_func(printf("|% .3d|\n", 13862), ft_printf("|% .3d|\n", 13862));
	// test_func(printf("|% 03.3d|\n", 6983), ft_printf("|% 03.3d|\n", 6983));
	// test_func(printf("|%5.0d|\n", 0), ft_printf("|%5.0d|\n", 0));
	// test_func(printf("|%+5.0d|\n", 0), ft_printf("|%+5.0d|\n", 0));
	// test_func(printf("|%+5.d|\n", 0), ft_printf("|%+5.d|\n", 0));
	// test_func(printf("|% 03.3d|\n", 6983), ft_printf("|% 03.3d|\n", 6983));
	// test_func(printf("|% 06.3d|\n", 6983), ft_printf("|% 06.3d|\n", 6983));
	// test_func(printf("|%06.3d|\n", 6983), ft_printf("|%06.3d|\n", 6983));

	// test_func(printf("|%+.d|\n", 0), ft_printf("|%+.d|\n", 0));

	// printf("%g\n", 123456.923);
	//write(1, ANSI_COLOR_CYAN "This text is CYAN!", 18);

	// test_func(printf("%.0d\n", 0), ft_printf("%.0d\n", 0));

	// test_func(printf("%+.0d\n", 0), ft_printf("%+.0d\n", 0));

	// test_func(printf("%+.0d\n", -0), ft_printf("%+.0d\n", -0));

	// test_func(printf("%.0d\n", 1), ft_printf("%.0d\n", 1));

	// test_func(printf("|%+d|\n", 6983), ft_printf("|%+d|\n", 6983));

	// test_func(printf("|%+d|\n", -6983), ft_printf("|%+d|\n", -6983));

	// test_func(printf("|%d|\n", -6983), ft_printf("|%d|\n", -6983));

	// test_func(printf("|%+5.d|\n", 0), ft_printf("|%+5.d|\n", 0));

	// test_func(printf("% d\n", -42, 0), ft_printf("% d\n", -42));

	// test_func(printf("%-+10.5d\n", 4242), ft_printf("%-+10.5d\n", 4242));

	// test_func(printf("this % d number\n", 17), ft_printf("this % d number\n", 17));

	// test_func(printf("|% .5d|\n", 2), ft_printf("|% .5d|\n", 2));

	test_func(printf("%.03s\n", NULL), ft_printf("%.03s\n", NULL));

	// printf("|%.5s|\n", "aaa");

	// test_func(printf("|% .2d|\n", 2), ft_printf("|% .2d|\n", 2));

	// test_func(printf("%03.2d\n", 0), ft_printf("%03.2d\n", 0));

	// test_func(printf("%5.d %5.0d\n", 0, 0), ft_printf("%5.d %5.0d\n", 0, 0));

	// test_func(printf("% hhd\n", (char)(-128)), ft_printf("% hhd\n", (char)(-128)));

	//printf("%+u\n", (unsigned)4294967295);

	// printf("%.0g\n", 16.01234567890);

	// printf("|%+05d|\n", -7);
	// ft_printf("|%+05d|\n", -7);
	// ft_printf("%#08o", 42);
	return (0);
}
// %#o 0 = 0
// %#x 0 = 0

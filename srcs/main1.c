// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main1.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/10/26 19:56:29 by btheia            #+#    #+#             */
// /*   Updated: 2019/10/26 21:06:29 by btheia           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "header.h"

static void test_func(int a, int b)
{
	if (a == b)
		printf("%d-------------------------------------------------%s\n", a, "OK");
	else
		printf("(sist)%d != %d-------------------------------------------------%s\n", a, b, "FAIL");
}

//1100110011001100110011001100110011001100110011001101
//1100110011001100110011001100110011001100110011001101
int		main()
{
	// 0000000000000000499
	// printf("%.19llu\n", (uint64_t)499);
	printf("%.7lf\n", 0.062152);
	ft_printf("%.7lf\n", 0.062152);
	// printf("%d\n", binpow(5,1));
	// 	int a01;
	// 	int a02;
	// 	int a03;
	// 	int a04;
	// 	int a05;
	// 	int a06;
	// 	int a07;
	// 	int a08;
	// 	int a09;
	// 	int a10;
	// 	int a11;
	// 	int a12;
	// // 	int b;
	// // 	int *a;
	// // 	char *n;
	// // 	char m;
	// // 	char *s = "dd";
	// // 	n = &m;
	// // 	a = &b;
	// //  	test_func(printf("x%fx\n", 0.1234567), ft_printf("x%fx\n", 0.1234567));

	// // 	test_func(printf("%+d\n", -10), ft_printf("%+d\n", -10));

	// // 	test_func(printf("---%+5d\n", 10), ft_printf("---%+5d\n", 10));

	// // 	test_func(printf("%-10dd\n", -10), ft_printf("%-10dd\n", -10));

	// // 	test_func(printf("abc%-+010d def\n", 43), ft_printf("abc%-+010d def\n", 43));

	// // 	test_func(printf("abc% -+05.5d def\n", 123456), ft_printf("abc% -+05.5d def\n", 123456));

	// // 	test_func(printf("abc% -+10d def\n", -123456), ft_printf("abc% -+10d def\n", -123456));

	// // 	test_func(printf("abc%-+10d def\n", 123456), ft_printf("abc%-+10d def\n", 123456));

	// // 	test_func(printf("abc%-+.10d def\n", 123456), ft_printf("abc%-+.10d def\n", 123456));

	// // 	test_func(printf("abc%-+d def\n", 0), ft_printf("abc%-+d def\n", 0));

	// // 	test_func(printf("abc% -+.10d def\n", -123456), ft_printf("abc% -+.10d def\n", -123456));

	// // 	test_func(printf("abc%-+d def\n", 123456), ft_printf("abc%-+d def\n", 123456));

	// // 	test_func(printf("%c %c %c %%%%%% %s = %-ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7),
	// // 					ft_printf("%c %c %c %%%%%% %s = %-ld c %%%dmal\n", 'a', 'b', 'c', "def", -92233720368775808, 7));

	// // 	test_func(printf("%-+6d\n", 0), ft_printf("%-+6d\n", 0));

	// // 	test_func(printf("abc% -09.7d def\n", -82), ft_printf("abc% -09.7d def\n", -82));

	// // 	test_func(printf("abc% 0*.*d def\n", 5, 7, -123), ft_printf("abc% 0*.*d def\n", 5, 7, -123));

	// // 	test_func(printf("abc%01.*d def\n", 4, 5), ft_printf("abc%01.*d def\n", 4, 5));

	// // 	test_func(printf("abc%010d def\n", -43), ft_printf("abc%010d def\n", -43));

	// // 	test_func(printf("abc% 05.5d def\n", -123456), ft_printf("abc% 05.5d def\n", -123456));

	// // 	test_func(printf("abc% 10d def\n", -123456), ft_printf("abc% 10d def\n", -123456));

	// // 	test_func(printf("abc% .10d def\n", -123456), ft_printf("abc% .10d def\n", -123456));

	// // 	test_func(printf("%s\n", "qwert"), ft_printf("%s\n", "qwert"));

	// // 	test_func(printf("%c\n", 'a'), ft_printf("%c\n", 'a'));

	// // 	test_func(printf("%c --- %s\n", 'a', "qawa!"), ft_printf("%c --- %s\n", 'a', "qawa!"));

	// // 	test_func(printf("%s\n", "*"), ft_printf("%s\n", "*"));

	// // 	test_func(printf("%f\n", 0.1234567), ft_printf("%f\n", 0.1234567));

	// // 	test_func(printf("% f\n", 0.1234567), ft_printf("% f\n", 0.1234567));

	// // 	test_func(printf("% +f\n", 0.1234567), ft_printf("% +f\n", 0.1234567));

	// // 	test_func(printf("%+010f\n", 0.123), ft_printf("%+010f\n", 0.123));

	// // 	test_func(printf("%+.7f\n", -0.12), ft_printf("%+.7f\n", -0.12));

	// // 	test_func(printf("%-7f\n", 0.1), ft_printf("%-7f\n", 0.1));

	// // 	test_func(printf("%-.7f\n", 0.1), ft_printf("%-.7f\n", 0.1));

	// // 	test_func(printf("x%10fx\n", 0.1), ft_printf("x%10fx\n", 0.1));

	// // 	test_func(printf("x%-10fx\n", 0.1), ft_printf("x%-10fx\n", 0.1));

	// // test_func(printf("x%+fx\n", 0.1), ft_printf("x%+fx\n", 0.1));

	// // test_func(printf("x% fx\n", 0.1), ft_printf("x% fx\n", 0.1));

	// // test_func(printf("x%+fx\n", 0.1), ft_printf("x% +fx\n", 0.1));

	// // test_func(printf("x%+fx\n", -0.1), ft_printf("x%+fx\n", -0.1));

	// // test_func(printf("x% -11fx\n", 0.1), ft_printf("x% -11fx\n", 0.1));

	// // test_func(printf("x% -11dx\n", -1), ft_printf("x% -11dx\n", -1));

	// // test_func(printf("x% 11fx\n", 0.1), ft_printf("x% 11fx\n", 0.1));

	// // test_func(printf("x% +11fx\n", 0.1), ft_printf("x% +11fx\n", 0.1));

	// // test_func(printf("x% 11fx\n", -0.1), ft_printf("x% 11fx\n", -0.1));

	// // test_func(printf("x%-11fx\n", 0.1), ft_printf("x%-11fx\n", 0.1));

	// // test_func(printf("x%-11fx\n", -0.1), ft_printf("x%-11fx\n", -0.1));

	// // test_func(printf("x%-+11fx\n", 0.1), ft_printf("x%-+11fx\n", 0.1));

	// // test_func(printf("x% -+11fx\n", 0.1), ft_printf("x% -+11fx\n", 0.1));

	// // test_func(printf("x% -11fx\n", 0.1), ft_printf("x% -11fx\n", 0.1));

	// // test_func(printf("x% -+11fx\n", -0.1), ft_printf("x% -+11fx\n", -0.1));

	// // test_func(printf("x% -11fx\n", -0.1), ft_printf("x% -11fx\n", -0.1));

	// // test_func(printf("x%-+011fx\n", 0.1), ft_printf("x%-+011fx\n", 0.1));

	// // test_func(printf("x%-+011fx\n", -0.1), ft_printf("x%-+011fx\n", -0.1));

	// // test_func(printf("x% 011xx\n", 1), ft_printf("x% 011xx\n", 1));

	// // 	test_func(printf("m%#10.5xm\n", 1), ft_printf("m%#10.5xm\n", 1));

	// // 	ft_printf("m%#10.5xm\n", 1);

	// // 	test_func(printf("m%#10.5Xm\n", 1), ft_printf("m%#10.5Xm\n", 1));

	// // 	test_func(printf("m%#10.5om\n", 1), ft_printf("m%#10.5om\n", 1));

	// // 	test_func(printf("m%10.5om\n", 1), ft_printf("m%10.5om\n", 1));

	// // 	test_func(printf("m%om\n", 0), ft_printf("m%om\n", 0));

	// // 	test_func(printf("m%xm\n", 0), ft_printf("m%xm\n", 0));

	// // 	test_func(printf("m%Xm\n", 0), ft_printf("m%Xm\n", 0));

	// // 	test_func(printf("m%#om\n", 0), ft_printf("m%#om\n", 0));

	// // 	test_func(printf("m%#xm\n", 0), ft_printf("m%#xm\n", 0));

	// // 	test_func(printf("m%#Xm\n", 0), ft_printf("m%#Xm\n", 0));

	// // 	printf("|%-7.10s|\n", "lalala");

	// // 	test_func(printf("|%-7.0s|\n", "lalala"), ft_printf("|%-7.0s|\n", "lalala"));

	// // 	test_func(printf("|%-7.10s|\n", "lalala"), ft_printf("|%-7.10s|\n", "lalala"));

	// // 	test_func(printf("|%7.0s|\n", "lalala"), ft_printf("|%7.0s|\n", "lalala"));

	// // 	test_func(printf("|%7.10s|\n", "lalala"), ft_printf("|%7.10s|\n", "lalala"));

	// // 	test_func(printf("|%.6s|\n", "lalala"), ft_printf("|%.6s|\n", "lalala"));

	// // 	test_func(printf("|%-s|\n", "lalala"), ft_printf("|%-s|\n", "lalala"));

	// // 	test_func(printf("|%.3s|\n", "lalala"), ft_printf("|%.3s|\n", "lalala"));

	// // 	printf("|%3c|\n", 'c');

	// // 	test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

	// // 	test_func(printf("|%-3c|\n", 'c'), ft_printf("|%-3c|\n", 'c'));

	// // 	test_func(printf("|%3c|\n", 'c'), ft_printf("|%3c|\n", 'c'));

	// // 	test_func(printf("|%5%%d|\n", 7), ft_printf("|%5%%d|\n", 7));

	// // 	test_func(printf("|%-5%%d|\n", 7), ft_printf("|%-5%%d|\n", 7));

	// // 	test_func(printf("------------|%5%%d|\n", 7), ft_printf("------------|%5%%d|\n", 7));

	// // 	ft_printf("|%10%|\n", 7);

	// // 	test_func(printf("|%d|%%\n", 7), ft_printf("|%d|%%\n", 7));

	// // 	test_func(printf("|%p|\n", n), ft_printf("|%p|\n", n));

	// // 	test_func(printf("|%20p|\n", a), ft_printf("|%20p|\n", a));

	// // 	test_func(printf("|%-20p|\n", a), ft_printf("|%-20p|\n", a));

	// // 	test_func(printf("|%20p|\n", n), ft_printf("|%20p|\n", n));

	// // 	test_func(printf("|%-20p|\n", n), ft_printf("|%-20p|\n", n));

	// // 	test_func(printf("|%p|\n", s), ft_printf("|%p|\n", s));

	// // 	test_func(printf("|%20p|\n", &a), ft_printf("|%20p|\n", &a));

	// // 	test_func(printf("|%-20p|\n", &a), ft_printf("|%-20p|\n", &a));

	// // 	printf("|%p|\n", &a);

	// // 	printf("|%20p|\n", &a);

	// // 	printf("|%-20p|\n", &a);

	// // 	printf("|%20p|\n", &a);

	// // 	printf("|%-20p|\n", &a);

	// // 	printf("|%-7.0d|\n", 7);

	// // 	printf("m%#10.5xm\n", 1);
	// // 	printf("m%#10.5Xm\n", 1);
	// // 	printf("m%#10.5om\n", 1);
	// // 	printf("m%10.5om\n", 1);

	// // 	test_func(printf("|%-10.0f|\n", -7.111), ft_printf("|%-10.0f|\n", -7.111));
	// // 	printf("|%+10.0f|\n", 0.1);
	// // 	printf("|%+10.0e|\n", 0.1);
	// // 	t_double d;
	// // 	d.numd = -0.098;
	// // 	d.numld = LDBL_MAX;
	// // 	d.numd = DBL_MAX;
	// // 	int prs = 1;
	// // 	int sign = 0;
	// // 	test_func(printf("|%-10.0e|\n", d.numd), ft_printf("|%-10.0e|\n", d.numd));
	// // 	test_func(printf("|%-+20.7e|\n", d.numd), ft_printf("|%-+20.7e|\n", d.numd));
	// // 	test_func(printf("|%+21.7e|\n", d.numd), ft_printf("|%+21.7e|\n", d.numd));
	// // 	test_func(printf("|%e|\n", d.numd), ft_printf("|%e|\n", d.numd));
	// // 	test_func(printf("|%-10.0Le|\n", d.numld), ft_printf("|%-10.0Le|\n", d.numld));
	// // 	test_func(printf("|%-+20.7Le|\n", d.numld), ft_printf("|%-+20.7Le|\n",d.numld));
	// // 	test_func(printf("|%+21.7Le|\n", d.numld), ft_printf("|%+21.7Le|\n", d.numld));
	// // 	test_func(printf("|%Le|\n", d.numld), ft_printf("|%Le|\n", d.numld));
	// // 	printf("%s\n", float_de(d, prs, &sign));

	// // 	test_func(printf("%s %s", "this", "is"), ft_printf("%s %s", "this", "is"));
	// // 	test_func(printf("%s %s", "a", "aaaa"), ft_printf("%s %s", "a", "aaaa"))
	// // 	printf("%s %s", "this", "is");
	// // 	ft_printf("%s %s %s %s %s", "a", "b", "c", "d", "e");
	// // 	ft_printf("%s %s", "this", "is");
	// // 	ft_printf("%s %s", "this", "is");
	// // 	ft_printf("%s %s", "this", "is");
	// // 	ft_printf("%s %s", "this", "is");
	// // 	ft_printf("%s %s", "a", "b");
	// // 	ft_printf("%b\n", 5);
	// // 	printf("%g\n", (double)0.1234568);
	// // 	int i = 0;
	// // 	printf("%s\n", float_lde(d, prs, &sign));
	// // 	printf("%lf\n", d.numd);
	// // 	ft_printf("%lf\n", d.numd);
	// // 	printf("%s\n", float_lde(d, prs, &sign));
	// // 	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "XXX", "YYY");
	// // 	// char *s = "f";
	// // 	// test_func(printf("%p\n", s), ft_printf("%p\n", s));
	// // 	// printf("%X\n", 11);
	// // 	// ft_printf("%X\n", 11);
	// // 	// printf("%o\n", 112);
	// // 	test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%o\n", ULLONG_MAX));
	// // 	write(1, NULL, 0);
	// // 	printf("+%+-10o+\n", 7123);
	// // 	test_func(printf("%llo\n", ULLONG_MAX), ft_printf("%llo\n", ULLONG_MAX));
	// // 	test_func(printf("%+ #llx\n", ULLONG_MAX), ft_printf("%+ #llx\n", ULLONG_MAX));
	// // 	printf("%o\n", ULLONG_MAX);
	// // 	ft_printf("%x\n", 0);
	// // 	printf("%#x\n", ULLONG_MAX);
	// 	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));
	// 	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));

	// 	// test_func(printf("%-10x\n", 42), ft_printf("%-10x\n", 42));

	// 	// test_func(printf("%10x\n", 42), ft_printf("%10x\n", 42));
	// 	// test_func(printf("%#x\n", 0), ft_printf("%#x\n", 0));
	// 	// test_func(printf("%10s\n", NULL), ft_printf("%10s\n", NULL));
	// 	//test_func(printf("|%.03s|\n", "qw"), ft_printf("|%.03s|\n", "qw"));
	// 	// test_func(printf("|%+05d|\n", -7), ft_printf("|%+05d|\n", -7));
	// 	// test_func(printf("|%08.5d|\n", 34), ft_printf("|%08.5d|\n", 34));
	// 	// test_func(printf("|% d|\n", -1), ft_printf("|% d|\n", -1));
	// 	// test_func(printf("|% .3d|\n", 13862), ft_printf("|% .3d|\n", 13862));
	// 	// test_func(printf("|% 03.3d|\n", 6983), ft_printf("|% 03.3d|\n", 6983));
	// 	// test_func(printf("|%5.0d|\n", 0), ft_printf("|%5.0d|\n", 0));
	// 	// test_func(printf("|%+5.0d|\n", 0), ft_printf("|%+5.0d|\n", 0));
	// 	// test_func(printf("|%+5.d|\n", 0), ft_printf("|%+5.d|\n", 0));
	// 	// test_func(printf("|% 03.3d|\n", 6983), ft_printf("|% 03.3d|\n", 6983));
	// 	// test_func(printf("|% 06.3d|\n", 6983), ft_printf("|% 06.3d|\n", 6983));
	// 	// test_func(printf("|%06.3d|\n", 6983), ft_printf("|%06.3d|\n", 6983));

	// 	// test_func(printf("|%+.d|\n", 0), ft_printf("|%+.d|\n", 0));

	// 	// printf("%g\n", 123456.923);
	// 	//write(1, ANSI_COLOR_CYAN "This text is CYAN!", 18);

	// 	// test_func(printf("%.0d\n", 0), ft_printf("%.0d\n", 0));

	// 	// test_func(printf("%+.0d\n", 0), ft_printf("%+.0d\n", 0));

	// 	// test_func(printf("%+.0d\n", -0), ft_printf("%+.0d\n", -0));

	// 	// test_func(printf("%.0d\n", 1), ft_printf("%.0d\n", 1));

	// 	// test_func(printf("|%+d|\n", 6983), ft_printf("|%+d|\n", 6983));

	// 	// test_func(printf("|%+d|\n", -6983), ft_printf("|%+d|\n", -6983));

	// 	// test_func(printf("|%d|\n", -6983), ft_printf("|%d|\n", -6983));

	// 	// test_func(printf("|%+5.d|\n", 0), ft_printf("|%+5.d|\n", 0));

	// 	// test_func(printf("% d\n", -42, 0), ft_printf("% d\n", -42));

	// 	// test_func(printf("%-+10.5d\n", 4242), ft_printf("%-+10.5d\n", 4242));

	// 	// test_func(printf("this % d number\n", 17), ft_printf("this % d number\n", 17));

	// 	// test_func(printf("|% .5d|\n", 2), ft_printf("|% .5d|\n", 2));

	// test_func(printf("|%p %p %p %p%p %p %p%5p%5p%5p%5p%5p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12),
	// 	ft_printf("|%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p|\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));

// 	// printf("|%.5s|\n", "aaa");

// test_func(printf("|%-#10.7x|\n", 7), ft_printf("|%-#10.7x|\n", 7));

// test_func(printf("|%-#10.7X|\n", 6), ft_printf("|%-#10.7X|\n", 6));

// test_func(printf("|%-#10.7o|\n", 5), ft_printf("|%-#10.7o|\n", 5)); // tut

	// test_func(printf("|%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p|\n", 
	// 	&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12),
	// 		ft_printf("|%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p|\n", 
	// 			&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));
// "%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10
	
// 	// test_func(printf("|%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p|\n", 
// 	// 	&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12),
// 	// 		ft_printf("|%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p|\n", 
// 	// 			&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12));

// 	// test_func(printf("|%-32p%-32p%-32p|\n", &a01,&a02,&a03),
// 	// 		ft_printf("|%-32p%-32p%-32p|\n", &a01,&a02,&a03));

// 	// test_func(printf("%03.2d\n", 0), ft_printf("%03.2d\n", 0));

// 	// test_func(printf("%5.d %5.0d\n", 0, 0), ft_printf("%5.d %5.0d\n", 0, 0));

// 	// test_func(printf("|%05%|\n"), ft_printf("|%05%|\n"));

// 	// test_func(printf("|%5%|\n"), ft_printf("|%5%|\n"));

// 	// test_func(printf("|% %|\n"), ft_printf("|% %|\n"));

// 	// test_func(printf("|%-10%|\n"), ft_printf("|%-10%|\n"));

// 	// test_func(printf("|% 03%|\n"), ft_printf("|% 03%|\n"));

// test_func(printf("|% Z|\n", 42), ft_printf("|% Z|\n", 42));

// test_func(printf("|%-#10.7x|\n", 7), ft_printf("|%-#10.7x|\n", 7));

// test_func(printf("|%-#10.7X|\n", 6), ft_printf("|%-#10.7X|\n", 6));
// ft_printf("%x\n", -42);
// test_func(printf("|%x|\n", -42), ft_printf("|%x|\n", -42)); // tut
// ft_printf("%x\n", -42);
	// printf("2 %f\n", 0.000039);
	// ft_printf("3 %f\n", 0.000039);
	// ft_printf("%f\n", 0.000039);
	// ft_printf("%f\n", 0.000039);
	// ft_printf("%f\n", 0.000039);
	// ft_printf("%f\n", 0.000039);
	// ft_printf("%f\n", 0.000039);
	// printf("%.0f", 7.4);
	// site 10100011100100111110111001011110111011011100110000100
	//		10100011100100111110111001011110111011011100110000100
	//		0100011100100111110111001011110111011011100110000100
	//		0100011100100111110111001011110111011011100110000100
	// t_double d;
	// d.numd = (double)-0.00039;
	// int prs = 50;
	// int sign;
	// //
	// // close(1);
	// printf("%.*lf\n", prs, d.numd);
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("%s\n", new_float_d(d, prs));
	// printf("\n%s\n", new_float_d(d, 6));
	// printf("\n%s\n", new_float_d(d, 6));
	// printf("\n%s\n", new_float_d(d, 6));
	// printf("\n%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// printf("%s\n", new_float_d(d, 6));
	// 100000000000
	// printf("|%0100000000000x|\n", 1);

	// test_func(printf("|%08.5x|\n", 34), ft_printf("|%08.5x|\n", 34));

	// test_func(printf("|%#08.5x|\n", 7), ft_printf("|%#08.5x|\n", 7));

	// test_func(printf("|%#-3x|\n", 0), ft_printf("|%#-3x|\n", 0));

	// test_func(printf("|%#010.x|\n", 0), ft_printf("|%#010.x|\n", 0));

	// test_func(printf("abc%M"), ft_printf("abc%M"));
	// printf("abc%M");

	// 	//printf("%+u\n", (unsigned)4294967295);

	// 	// printf("%.0g\n", 16.01234567890);

	// test_func(printf("|%f|\n", -8000.0), ft_printf("|%f|\n", -8000.0));

	// ft_printf("|%f|\n", -8000.0);

	// printf("%d\n", 5 << 3);
	//"%ju", 4999999999

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));

	// test_func(printf("|% |\n"), ft_printf("|% |\n"));
	// printf("|%#.0f|\n", -7.0);
	// 	// ft_printf("|%+05d|\n", -7);
	// 	// ft_printf("%#08o", 42);
	return (0);
}
// // %#o 0 = 0
// // %#x 0 = 0

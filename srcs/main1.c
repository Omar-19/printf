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
// // //1100110011001100110011001100110011001100110011001101
// int		main()
// {
// 	int a;
// 	// 0000000000000000499
// 	// test_func(printf("%*d\n", 5, 42), ft_printf("%*d\n", 5, 42));
// 	// printf("%o, %ho, %hho\n", -42, -42, -42);
// 	// ft_printf("%o, %ho, %hho\n", -42, -42, -42);
// 	//"%.0p, %.p", 0, 0
// 	// test_func(printf("%.0p, %.p\n", 0, 0), ft_printf("%.0p, %.p\n", 0, 0));
// 	// test_func(printf("%9.2p\n", 1234), ft_printf("%9.2p\n", 1234));
// 	//printf("{%.*s}", 0, "42")
// 	// test_func(printf("{%s}\n", "42"), ft_printf("{%s}\n", "42"));
// 	// printf("{%.*s}\n", -5, "42")
// 	// printf("a%ob\n%oc\n%od\n", 0, 55555, 100000);
// 	// ft_printf("a%ob\n%oc\n%od\n", 0, 55555, 100000);
// 	// printf("%#.o\n", 42);
// 	// ft_printf("%#.o\n", 42);
// 	printf("1 %2.9p\n", 1234);
// 	ft_printf("2 %2.9p\n", 1234);
// 	return (0);
// }
// // // %#o 0 = 0
// // %#x 0 = 0

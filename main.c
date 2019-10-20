#include "header.h"
#include <stdio.h>
/*#include <stdarg.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
*/

int main()
{

	printf("--------------------- %d\n", printf("abc%+010d def\n", 43));
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


/*
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
	return (0);
}

 /*
int sum(int n, ...)
{
	int result = 0;
	va_list factor;         //указатель va_list
	va_start(factor, n);    // устанавливаем указатель
	printf("factor = %p\n", factor);
	printf("n = %d\n", n);
	for(int i=0; i<n; i++)
	{
		printf("factor = %p\n", factor);
		result += va_arg(factor, int);  // получаем значение текущего параметра типа int
	}
	printf("end factor = %d\n", va_arg(factor, int));
	printf("factor = %p\n", factor);
	va_end(factor); // завершаем обработку параметров
	return result;
}
 */
/*
static void	ft_abs(long long *value, char **str, int *size, int *flag)
{
	*flag = 1;
	(*str)[0] = '-';
	(*str)[(*size)--] = '0' - *value % 10;
	*value /= 10;
	*value *= -1;
}

char		*ft_itoa_base(long long value_i, unsigned long long value_u)
{
	unsigned long long	value;
	unsigned long long	val;
	char			*str;
	int				size;
	int				flag;

	flag = 0;
	size = 0;
	if (value_i < 0)
	{
		++size;
		flag = 1;
		val = -value_i;
	}
	else if (value_i > 0)
		val = value_i;
	else
		val = value_u;
	value = val;
	while (value /= 10)
		++size;
	++size;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size--] = '\0';
	if (flag == 1)
		str[0] = '-';
	while ((size > 0 && flag == 1) || (size >= 0 && flag == 0))
	{
		str[size--] = '0' + val % 10;
		val /= 10;
	}
	return (str);
}

int main(void)
{	
	// long long int a;
	//float a = 0.123;
	double b = 0.123;
	signed char a = 11;
	char *str;
	long long int z = 11;

	int c = 6;
	printf("%d\n", c);
	b = ULLONG_MAX;
	printf("%lf\n",b);
	printf("%llu\n", (unsigned long long int)b);
	// printf("%.30f\n", a);
	// printf("%.30lf\n", b);

	// a = (short int)123457;
	// //char a[5] = "abcde";
	// //printf("%d \n", sum(4, 1, 2, 3, 4));
	//printf("%s", "a");
	//ft_itoa_base(z);
	//printf("%s\n", ft_itoa_base(-123));
	printf("%s\n", ft_itoa_base(0, 0));
	//printf("%lld\n", -9223372036854775808LL);
	free(str);
	//printf("%6.5d\n", 12);
	// //printf("%d \n", sum(5, 12, 21, 13, 4, 5));
	// // printf("%lld == %hd", a, (short int)123457);
	// printf("%Lf", (long double)(pow(2,53) * pow(10,53)));
	//write(1, a, 5);
	
	return 0;
}*/

/*
int main()
{
   // printf("abc %.38f a\n", 1.111111111111111111111111111111111111111111111119);
   // printf("abc %d a\n", 7000760777778458528544512745128451800);    
}*/

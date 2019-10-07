#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>

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
int main(void)
{	
	// long long int a;
	float a = 0.123;
	double b = 0.123;

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
	// //printf("%hd", (short int)32);
	// //printf("%d \n", sum(5, 12, 21, 13, 4, 5));
	// // printf("%lld == %hd", a, (short int)123457);
	// printf("%Lf", (long double)(pow(2,53) * pow(10,53)));
	//write(1, a, 5);
	return 0;
}

/*
int main()
{
   // printf("abc %.38f a\n", 1.111111111111111111111111111111111111111111111119);
   // printf("abc %d a\n", 7000760777778458528544512745128451800);    
}*/
#include <stdio.h>
#include <stdarg.h>
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
	//printf("%d \n", sum(4, 1, 2, 3, 4));
	printf("%X", 10);
	//printf("%d \n", sum(5, 12, 21, 13, 4, 5));
	return 0;
}

/*
int main()
{
   // printf("abc %.38f a\n", 1.111111111111111111111111111111111111111111111119);
   // printf("abc %d a\n", 7000760777778458528544512745128451800);    
}*/
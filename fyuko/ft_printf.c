#include "header.h"
#include <stdio.h>

void	ft_write_str(const char *str, size_t len)
{
	write(1, str, len);
}

int		print_elem(const char *format, va_list elem)
{
	const char	*ptr;
	const char	*str;
	size_t		len;
	int			res;
	int			i;

	str = format;
	res = 0;
	ptr = str;
	i = 0;
	len = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			len = str + i - ptr;
			if (len != 0)
			{
				ft_write_str(ptr, len);
				res += len;
				ptr = str + ++i;
			}
			else
				ptr = str + ++i;
			if (str[i] == '%')
				++i;
			else
			{
				//printf("i = %d\n", i);
				//printf("res = %p\n", str);
				//printf("ptr = %p\n", ptr);
				//printf("i = %d\n", i);
				while(!(ft_is_conversion(str[i])))
					++i;
				//printf("i = %d\n", i);
				len = str + i - ptr + 1;
				ft_param_processing(ptr, len, elem);
				//if (ft_param_processing(ptr, len, elem))
				//	return(0);
				//ft_write_str(ptr, len);
				//printf("i = %d\n", i);
				ptr = str + ++i;
			}
			continue;
		}
		++i;
	}
	if ((len = str + i - ptr))
		ft_write_str(ptr, len);
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list	elem;
	int		result;

	va_start(elem, format);
	result = print_elem(format, elem);
	va_end(elem);
	return (result);
}

int main()
{
	//ft_printf("%cmbc%hdc%%mal", 7, 8, 9);
	printf("abc% 09.7d def\n", -82);
	ft_printf("abc% 09.7d def\n", -82);
	
	printf("abc% 0*.*d def\n", 5, 7, -123);
	ft_printf("abc% 0*.*d def\n", 5, 7, -123);
	
	printf("abc%01.*d def\n", 4, 5);
	ft_printf("abc%01.*d def\n", 4, 5);
	
	printf("abc%010d def\n", -43);
	ft_printf("abc%010d def\n", -43);
	
	printf("abc% 05.5d def\n", -123456);
	ft_printf("abc% 05.5d def\n", -123456);

	//ft_printf("%daaa\n");
	//ft_printf("d = %lld %% lololo lld = %lld\n", 9223372036854775807, -9223372036854775808);
	//ft_printf("-----pepepe------\n");
	//ft_printf("rabotaet: llu = %llu\n", 18446744073709551615);
	//write(1, "\n", 1);
	return (0);
}

/*
int		ft_write(const char *str, const size_t num)
{
	write(1, str, num);
	return (num);
}

int		ft_repeat(const char c, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_write(&c, 1);
		++i;
	}
	return (i);
}
*/
/*
int		get_arg(const char *str, size_t num, int val, va_list elem)
{
	if (*str == '%' && val)
		//
	return (ft_write(str, num));
}
*/
/*
int		check_prc(const char *str, size_t *i, int *val)
{
	if (!str[*i])
		return (1);
		//проверка на принадлежность к какому-либо типу кроме символов
	while (str[*i] && ft_is_valid_param(str[*i]) && !ft_is_conversion(str[*i]))
		(*i)++;
		//символ:
	if ((*val = str[*i] && ft_is_valid_param(str[*i])))
		(*i)++;
	else
		return (1);
	return (0);
}
*/
// подсчитывание числа выведеннных символов
// -> get
/*
int		print_elem(const char *str, va_list elem)
{
	size_t	i;
	size_t	begin;
	int		count;
	int		val;

	i = 0;
	count = 0;
	while (str[i])
	{
		begin = i;
		val = 0;
		if (str[i] == '%')
		{
			i++;
			if (check_prc(str, &i, &val))
				continue;
		}
		else
			while (str[i] && str[i] != '%')
				++i;
		// get_arg - 
		count += get_arg(str + begin, i - begin, val, elem);
	}
	return (count);
}*/

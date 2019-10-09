#include "header.h"
#include <stdio.h>

void	ft_write_str(const char *str, size_t len)
{
	write(1, str, len);
	write(1, " ", 1);
}

int		print_elem(const char *format, va_list elem)
{
	const char	*ptr;
	const char	*str;
	size_t		len;
	int			i;

	str = format;
	ptr = str;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			len = str + i - ptr;
			if (len != 0)
			{
				ft_write_str(ptr, len);
				ptr = str + ++i;
			}
			//	ptr = ft_lst_push_back(str + ++i, ptr);
			else
				ptr = str + ++i;
			if (str[i] == '%')
				++i;
			else
			{
				while(!(ft_is_conversion(str[i])))
					++i;
				len = str + i + 1 - ptr;
				if (!ft_param_processing(ptr, len, elem))
					return(0);
				//ft_write_str(ptr, len);
				ptr = str + ++i;
			}
			continue;
		}
		++i;
	}
	if ((len = str + i - ptr))
		ft_write_str(ptr, len);
	return (0);
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
	ft_printf("d = %d", 7);
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

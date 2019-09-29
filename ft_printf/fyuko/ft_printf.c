#include "header.h"
#include <stdio.h>
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


int		print_elem(const char *format, va_list elem)
{
	t_string	*head;
	t_string	*ptr;
	const char	*str;
	int			i;
	int			f;

	str = format;
	i = 0;
	f = 0;
	head = ft_lst_new(str);
	// check
	ptr = head;
	while(str[i])
	{
		if (str[i] == '%')
		{
			ptr->len = str + i - ptr->str;
			if (ptr->len != 0)
				ptr = ft_lst_push_back(str + ++i, ptr);
			else
				ptr->str = str + ++i;
			if (str[i] == '%')
				++i;
			else
			{
				while(!(ft_is_conversion(str[i])))
					++i;
				ptr->len = str + i + 1 - ptr->str;
				ptr->flag = 1;
				if (!ft_paramater_processing(ptr, format))
					ft_error(&head);
				ptr = ft_lst_push_back(str + ++i, ptr);
			}
			continue;
		}
		++i;
	}
	ptr->len = str + i - ptr->str;
	ptr = head;
	while(head)
	{
		printf("header = %s, len = %zu, f = %d\n", head->str, head->len, head->flag);
		head = head->next;
	}
	ft_lst_delet(&head);
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
	ft_printf("%cmbc%dcm%%", 7);
	return (0);
}
#include "header.h"

static inline int		ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+' ", c) == NULL));
}

int		ft_atoi_n(const char *str, int *j)
{
	long	number;

	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		++(*j);
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + 1 * (*str - '0');
		str++;
	}
	return (number);
}

void	ft_format_specification_description(const char *str, size_t len, va_list elem, t_param *f_p_s)
{
	int i;
	int j;

	i = 0;
	while (ft_is_flag(*(str + i)) && i < len)
	{
		*((*f_p_s).flags + i) = *(str + i);
		++i;
	}
	j = i;
	while (i < 5)
		*((*f_p_s).flags + i++) = '\0';
	i = 0;
	if (*(str + j) == '*')
	{
		(*f_p_s).width = va_arg(elem, int);
		++j;
	}
	else if (*(str + j) >= '0' && *(str + j) <= '9')
		(*f_p_s).width = ft_atoi_n(str + j, &j);
	else
		(*f_p_s).width = 0;
	if (*(str + j) == '.')
	{
		if (*(str + ++j) == '*')
			(*f_p_s).precision = va_arg(elem, int);
		else
			(*f_p_s).precision = ft_atoi_n(str + j, &j);
	}
	else
		(*f_p_s).precision = 0;
}

int		read_variable(const char *str, size_t len, va_list elem)
{
	int		var;
	char	*ptr;
	int		flag;
	// Format placeholder specification
	t_param				form_place_spc;

	//*l = 5;
	ft_format_specification_description(str, len, elem, &form_place_spc);
	//printf("\nform_place_spc.flags = %s\n form_place_spc.width = %d\n form_place_spc.precision = %d\n",
	//							 form_place_spc.flags, form_place_spc.width, form_place_spc.precision);
	if (ft_strstr_num(str, "hhd\0", len) || ft_strstr_num(str, "hhi\0", len))
		ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, &form_place_spc);
	else if (ft_strstr_num(str, "hd\0", len) || ft_strstr_num(str, "hi\0", len))
		ptr = ft_itoa_d((short int)va_arg(elem, int), 0, &form_place_spc);
	else if (ft_strstr_num(str, "lld\0", len) || ft_strstr_num(str, "lli\0", len))
		ptr = ft_itoa_d(va_arg(elem, long long int), 0, &form_place_spc);
	else if (ft_strstr_num(str, "ld\0", len) || ft_strstr_num(str, "li\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, &form_place_spc);
	else if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
		ptr = ft_itoa_d(va_arg(elem, int), 0, &form_place_spc);
	else if (ft_strstr_num(str, "llu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), &form_place_spc);
	else if (ft_strstr_num(str, "lu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), &form_place_spc);
	else if (ft_strstr_num(str, "hhu\0", len))
		ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), &form_place_spc);
	else if (ft_strstr_num(str, "hu\0", len))
		ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), &form_place_spc);
	else if (ft_strstr_num(str, "u\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned int), &form_place_spc);
	else
	{
		return (0);
	}
	//write(1, "--hd--", 6);
	//write(1, "0", 1);
	write(1, ptr, form_place_spc.result);
	return (3);
}

int		ft_param_processing(const char *str, size_t len, va_list elem)
{
	int		l;
	char	*ptr;
	l = 7;

	l = read_variable(str, len, elem);
	return (l);
}

/*
static int	ft_len(int n)
{
	int i;

	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_nitoa(int n)
{
	char	*s;
	int		flag;
	int		len;
	long	n1;

	n1 = n;
	len = ft_len(n1);
	flag = (n1 < 0 && (n1 *= -1)) ? 1 : 0;
	if (!(s = (char*)malloc(sizeof(char) * (len += flag))))
		return (NULL);
	if (n1 == 0 && (s[0] = '0'))
		return (s);
	s[--len] = '\0';
	while (n1 != 0)
	{
		s[--len] = n1 % 10 + '0';
		n1 /= 10;
	}
	if (flag == 1)
		s[--len] = '-';
	return (s);
}*/

/*
int		read_variable(t_string *str, va_list elem)
{
	t_type	var;
	
	if (str->str[str->len - 1] == "d" || str->str[str->len - 1] == "x" ||
		str->str[str->len - 1] == "X" || str->str[str->len - 1] == "o" ||
		str->str[str->len - 1] == "i")
		var.type_int = va_arg(elem, int);
	else if (str->str[str->len - 1] == "f" || str->str[str->len - 1] == "F" ||
		str->str[str->len - 1] == "g" || str->str[str->len - 1] == "G" ||
		str->str[str->len - 1] == "a" || str->str[str->len - 1] == "A")
		var.type_doub = va_arg(elem, double);
	else if (str->str[str->len - 1] == "u")
		var.type_un_int = va_arg(elem, unsigned int);
	else if (str->str[str->len - 1] == "c")
		var.type_char = va_arg(elem, char);
	else if (str->str[str->len - 1] == "p")
		var.type_ptr = va_arg(elem, void *);
	else if (str->str[str->len - 1] == "s" || str->str[str->len - 1] == "S")
		var.type_string = va_arg(elem, char *);
	else
		return (0);
	return (1);
}

int		ft_param_processing(t_string *str, va_list elem)
{
	read_variable(str, elem);
	return (1);
}
*/
//va_arg

/*
static int	ft_len(int n)
{
	int i;
​
	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
char		*ft_nitoa(int n)
{
	char	*s;
	int		flag;
	int		len;
	long	n1;
​
	n1 = n;
	len = ft_len(n1);
	flag = (n1 < 0 && (n1 *= -1)) ? 1 : 0;
	if (!(s = (char*)malloc(sizeof(char) * (len += flag))))
		return (NULL);
	if (n1 == 0 && (s[0] = '0'))
		return (s);
	s[--len] = '\0';
	while (n1 != 0)
	{
		s[--len] = n1 % 10 + '0';
		n1 /= 10;
	}
	if (flag == 1)
		s[--len] = '-';
	return (s);
}
char	*param_processing(t_string *str, void *elem)
{
	return (0);
}*/
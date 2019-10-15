#include "header.h"

int		ft_strstr_num(const char *str, const char *to_find, size_t len)
{
	//char *str;
	//char *to_find;
	const char *a;
	const char *b;

	//str = (char *)haystack;
	//to_find = (char *)needle;
	while (len > 0)
	{
		a = str;
		b = to_find;
		while (*(a++) == *(b++))
		{
			if (*b == '\0')
				return (1);
		}
		++str;
		--len;
	}
	return (0);
}

/*char	*ft_int_processing(long long int elem)
{
	return (NULL);
}

char	*ft_char_processing(char elem)
{
	return (NULL);
}
*/
int		read_variable(const char *str, size_t len, va_list elem, int *l)
{
	int var;
	char *ptr;
	int flag;
	
	//*l = 0;
	//var = va_arg(elem, int);
	//if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "i\0", len))
	//	ptr = ft_itoa_d(va_arg(elem, int), 0, l);
	if (ft_strstr_num(str, "hhd\0", len) || ft_strstr_num(str, "hhi\0", len))
		ptr = ft_itoa_d((signed char)va_arg(elem, int), 0, l);
	else if (ft_strstr_num(str, "hd\0", len) || ft_strstr_num(str, "hi\0", len))
		ptr = ft_itoa_d((short int)va_arg(elem, int), 0, l);
	else if (ft_strstr_num(str, "lld\0", len) || ft_strstr_num(str, "lli\0", len))
		ptr = ft_itoa_d(va_arg(elem, long long int), 0, l);
	else if (ft_strstr_num(str, "ld\0", len) || ft_strstr_num(str, "li\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, l);
	else if (ft_strstr_num(str, "d\0", len) || ft_strstr_num(str, "li\0", len))
		ptr = ft_itoa_d(va_arg(elem, long int), 0, l);
	else if (ft_strstr_num(str, "llu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long long int), l);
	else if (ft_strstr_num(str, "lu\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned long int), l);
	else if (ft_strstr_num(str, "hhu\0", len))
		ptr = ft_itoa_d(0, (unsigned char)va_arg(elem, int), l);
	else if (ft_strstr_num(str, "hu\0", len))
		ptr = ft_itoa_d(0, (unsigned short int)va_arg(elem, int), l);
	else if (ft_strstr_num(str, "u\0", len))
		ptr = ft_itoa_d(0, va_arg(elem, unsigned int), l);
	else
	{
		return (0);
	}
	//write(1, "--hd--", 6);
	//write(1, "0", 1);
	write(1, ptr, *l);
	return (1);
}

int		ft_param_processing(const char *str, size_t len, va_list elem)
{
	int l;
	char *ptr;

	l = 0;
	read_variable(str, len, elem, &l);
	return (1);
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
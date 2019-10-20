// ft_printf.c


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



// check_symbol.c

// добавить полное описание:
// %[флаги][ширина][.точность][размер]тип


// ft_lib_int.c

// 	if (ft_strchr((*f_p_s).flags, ' ') && (*f_p_s).width == (*f_p_s).result)//&& (*f_p_s).precision + flag != (*f_p_s).result)


// help_func.c



// parameter_processing.c

//t_param				form_place_spc;
	//ft_format_specification_description(str, len, elem, &form_place_spc);
	//printf("\nform_place_spc.flags = %s\n form_place_spc.width = %d\n form_place_spc.precision = %d\n",
	//							 form_place_spc.flags, form_place_spc.width, form_place_spc.precision);
	
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


// header

/*
typedef struct		s_string
{
	const char		*str;
	size_t			len;
	int				flag;
    struct s_string	*next;
}					t_string;

typedef struct				s_type
{
	//???
	//eEn
	//jtL
	
	//dxXoi
	int						type_int;
	//fFgGaA
	double					type_doub;
	//u
	unsigned int			type_un_int;
	//c
	char					type_char;
	//p
	void					*type_ptr;
	//sS
	char					*type_string;

	//-----------------------------------

	//l
	long int				type_l_int;
	unsigned long int		type_uns_l_int;
	//hh
	signed char				type_sig_char;
	unsigned char			type_uns_char;
	//h
	short int				type_sh_int;
	unsigned short int		type_uns_sh_int;
	//ll
	long long int			type_ll_int;
	unsigned long long int	type_uns_ll_int;
	//z
	size_t					type_size_t;
	//j
	//intmax_t				type_intmax_t;
	//uintmax_t				type_uintmax_t;
}							t_type;

union double_d
{
	double a;
	char bytes[8];
};
*/
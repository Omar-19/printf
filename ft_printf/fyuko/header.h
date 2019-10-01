#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_val
{
	char			type;
	char			length[2];
}					t_val;

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

int					read_variable(t_string *str, va_list elem);
int					ft_param_processing(t_string *str, va_list elem);
void				ft_error(t_string **lst);
char				*ft_nitoa(int n);
//char				*param_processing(t_string *str, void *elem);
int					ft_is_conversion(const char c);
void				ft_lst_delet(t_string **alst);
t_string			*ft_lst_new(char const *ptr);
t_string			*ft_lst_push_back(char const *ptr, t_string *elem);
int					ft_is_valid_param(const char c);
int					print_elem(const char *str, va_list elem);

#endif
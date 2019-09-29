#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_string
{
	const char		*str;
	size_t			len;
	int				flag;
    struct s_string	*next;
}					t_string;

typedef struct 		s_type
{
	//eESn
	//dxXoi
	int				type_int;
	//fFgGaA
	double			type_doub;
	//u
	unsigned int	type_un_int;
	//c
	char			type_char;
	//p
	void			*type_ptr;
	//sS
	char			*type_string;

};

int					*ft_param_processing(t_string *str, const char format);
void				ft_error(t_string **lst);
char				*ft_nitoa(int n);
char				*param_processing(t_string *str, void *elem);
int					ft_is_conversion(const char c);
void				ft_lst_delet(t_string **alst);
t_string			*ft_lst_new(char const *ptr);
t_string			*ft_lst_push_back(char const *ptr, t_string *elem);
int					ft_is_valid_param(const char c);
int					print_elem(const char *str, va_list elem);

#endif
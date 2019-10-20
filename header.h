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

typedef struct				s_param
{
	int		precision ;
	char	flags[5];
	int		width;
	int		len;
	int		result;
}							t_param;

size_t				ft_strlen(const char *s);
int					read_variable_char(const char *str, size_t len, va_list elem);
void				ft_string_processing(t_param *f_p_s, char *str, int flag);
int					ft_result_len(t_param *f_p_s, int flag);
int					ft_atoi_n(const char *str, int *j);
char				*ft_strchr(const char *s, int c);
void				ft_format_specification_description(const char *str, size_t len, va_list elem, t_param *f_p_s);
char				*ft_itoa_d(long long int value_i, unsigned long long value_u, t_param *f_p_s);
int					ft_strstr_num(const char *str, const char *to_find, size_t len);
void				ft_write_str(const char *str, size_t len);
int					read_variable_int(const char *str, size_t len, va_list elem, t_param *form_place_spc);
int					ft_param_processing(const char *str, size_t len, va_list elem);
char				*ft_nitoa(int n);
int					ft_is_conversion(const char c);
int					ft_is_valid_param(const char c);
void				ft_write_str(const char *str, size_t len);
int					print_elem(const char *format, va_list elem);
int					ft_printf(const char *format, ...);

#endif
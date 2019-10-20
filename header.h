/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:44:46 by btheia            #+#    #+#             */
/*   Updated: 2019/10/20 18:08:15 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdarg.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stddef.h>
# include <float.h>
# include <stdlib.h>
# include "libft/libft.h"
# define MY_LONG_MIN (-0x7fffffffffffffffL-1)
# define RAZR (__uint128_t)10000000000000000000UL
# define RETF(x) (((*(uint32_t*)(&x) >> 23) & (uint32_t)0xFF)  - 127)
# define RETD(x) (((*(uint64_t *)(&d.numd) >> 52) & 0x7FF) - 1023)
# define RETLD(x) (((*(__uint128_t*)(&d.numld) >> 64) & 0x7FFF) - 16383)

typedef union	u_double
{
	long double		numld;
	double			numd;
	float			numf;
}				t_double;

typedef struct        s_val
{
	char            type;
	char            length[2];
}                    t_val;

typedef struct                s_param
{
	int		precision ;
	char	flags[5];
	int		width;
	int		len;
	int		result;
}                              t_param;


int				read_variable_float(const char *str, size_t len, va_list elem, t_param *form_place_spc);
int				ft_printf(const char *format, ...);
char			*ft_ltoa_base(long long num, int base);
char			*ft_strnew(size_t size);
char			*arrayreverse(char *s);
char			*ft_uint64toa(uint64_t a, int d);
void			okrug(char **d, int t);
void			set_min(char **d, char c);
char			*ft_strnewc(size_t n, char c);
char			*set_p(char *s, int pos);
char			*main_c(char *s);
void			wr(uint64_t *res, int len, FILE *f);
void			wf(uint64_t *res, int len);
char			*cr_dc(char *s, size_t m1, int len, int i);
void			umn(uint64_t *tmp, int deg, int *min, int ndb);
int				min_i(int *a, int *b);
int				sum_m(uint64_t *res, uint64_t *tmp, int min, int ndb);
char			*drob(char *s, int t);
char			*drob1(char *s, size_t m1, int max_d, int t);
char			*drob2(uint64_t *res, int t, int m1, int res_n, int max_d);
void			umn10(uint64_t *tmp, int *min, int ndb);
char			*del(uint64_t *tmp, int deg, int ndb, int t);
char			*del1_one(uint64_t *tmp, int deg, int ndb, int t);
char			*mastos(int *a, int t);
void			toone(uint64_t *tmp, int min, int m1);
char			*cr_sdc(uint64_t *a, int min, size_t m1);
char			*hex_int(void *a, int typ, int p, int sd);
char			*get_val(char *s);
char			*main_p(char **s, int pos);
char			*float_f(t_double d, int prs, int *sign);
char			*float_d(t_double d, int prs, int *sign);
char			*float_ld(t_double d, int prs, int *sign);
void			init_massiv(uint64_t *res, uint64_t *tmp, size_t m1);
void			umn1(uint64_t *tmp, int deg, int *min, int ndb);
void			okrug1(char **d, int t);
void			init_help_del1(__uint128_t *a, int *o, int deg);
int				search_non(uint64_t *tmp, int ndb);
void			ret_byties_float(t_double d, int *a, int type, char *l);
void			sum_mhelp(__uint128_t *s, int *i);
void			sum_mhelp2(__uint128_t *s, __uint128_t f,
	int pos, uint64_t *res);
int				sum_mhelp3(uint64_t *res, int pos, int min, __uint128_t s);
void			sum_mhelp4(uint64_t *res, int pos,
	__uint128_t *s, __uint128_t f);
int				sum_mhelp5(__uint128_t *a, uint64_t *res, int pos, int min);
int				sum_mhelp6(__uint128_t *a, uint64_t *res, int pos);
char			*ft_strnewc(size_t n, char c);
char			*get_val(char *s);
size_t                ft_strlen(const char *s);
int                    read_variable_char(const char *str, size_t len, va_list elem);
void                ft_string_processing(t_param *f_p_s, char *str, int flag);
int                    ft_result_len(t_param *f_p_s, int flag);
int                    ft_atoi_n(const char *str, int *j);
char                *ft_strchr(const char *s, int c);
void                ft_format_specification_description(const char *str, size_t len, va_list elem, t_param *f_p_s);
char                *ft_itoa_d(long long int value_i, unsigned long long value_u, t_param *f_p_s);
int                    ft_strstr_num(const char *str, const char *to_find, size_t len);
void                ft_write_str(const char *str, size_t len);
int                    read_variable_int(const char *str, size_t len, va_list elem, t_param *form_place_spc);
int                    ft_param_processing(const char *str, size_t len, va_list elem);
char                *ft_nitoa(int n);
int                    ft_is_conversion(const char c);
int                    ft_is_valid_param(const char c);
void                ft_write_str(const char *str, size_t len);
int                    print_elem(const char *format, va_list elem);
int                    ft_printf(const char *format, ...);

#endif

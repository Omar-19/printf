#include "header.h"

int		ft_is_conversion(const char c)
{
	return (!(ft_strchr("diuoxXfFeEgGaAcsSpn", c) == NULL));
}

static inline int		ft_is_length(const char c)
{
	return (!(ft_strchr("hhllLzjt", c) == NULL));
}

static inline int		ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+' ", c) == NULL));
}

static inline int		ft_is_precision(const char c)
{
	return (!(ft_strchr("*.", c) == NULL));
}

static inline int		ft_is_num(const char c)
{
	return (c >= '0' && c <= '9');
}

int						ft_is_valid_param(const char c)
{
	return (ft_is_conversion(c) || ft_is_flag(c) ||
			ft_is_num(c) || ft_is_precision(c) || ft_is_length(c));
}
#include "header.h"

// жобавить полное описание:
// %[флаги][ширина][.точность][размер]тип

char	*ft_strchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr != '\0' || (*ptr == '\0' && c == '\0'))
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

int		ft_is_conversion(const char c)
{
	return (!(ft_strchr("diuoxXfFeEgGaAcsSpn", c) == NULL));
}

static inline int		ft_is_flag(const char c)
{
	return (!(ft_strchr("#0-+' ", c) == NULL));
}

static inline int		ft_is_precision(const char c)
{
	return (!(ft_strchr("*.", c) == NULL));
}

//хуй знает пока зачем это
static inline int		ft_is_num(const char c)
{
	return (c >= '0' && c <= '9');
}

int						ft_is_valid_param(const char c)
{
	return (ft_is_conversion(c) || ft_is_flag(c) ||
			ft_is_num(c) || ft_is_precision(c));
}
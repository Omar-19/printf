#include "header.h"

void	ft_error(t_string **lst)
{
	ft_lst_delet(lst);
	write(1, "error\n", 5);
}
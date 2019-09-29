#include "header.h"

void	ft_lst_delet(t_string **alst)
{
	t_string *nxt;
	t_string *tmp;

	if (alst != NULL)
	{
		nxt = *alst;
		while (nxt)
		{
			tmp = nxt->next;
			free(nxt);
			nxt = tmp;
		}
		free(*alst);
		*alst = NULL;
	}
}

t_string	*ft_lst_new(char const *ptr)
{
	t_string *new;

	if (!(new = (t_string *)malloc(sizeof(t_string))))
		return (NULL);
	new->str = ptr;
	new->len = 0;
	new->flag = 0;
	new->next = NULL;
	return (new);
}

t_string	*ft_lst_push_back(char const *ptr, t_string *elem)
{
	if(!(elem->next = ft_lst_new(ptr)))
		return (NULL);
	return (elem->next);
}
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyuko <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:39:18 by fyuko             #+#    #+#              #
#    Updated: 2019/09/11 21:48:19 by fyuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

all:$(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c ./$(CNAME)
	@ar rc $(NAME) $(ONAME)
clean:
	@rm -f $(ONAME)
fclean: clean
	@rm -f libft.a
re: fclean all

.PHONY: all fclean clean re
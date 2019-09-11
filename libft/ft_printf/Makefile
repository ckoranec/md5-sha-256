#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 22:38:18 by jkertgat          #+#    #+#              #
#    Updated: 2018/08/08 19:49:59 by jkertgat         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = parse.c tools.c percision.c ft_printf.c print.c parse2.c parse3.c \
 print2.c print3.c print4.c print5.c

NAME := ../libft.a

OBJ = $(SRC:.c=.o)

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -I includes -c $(SRC) -g
	ar rc $(NAME) $(OBJ) ../*.o

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

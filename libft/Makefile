#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 22:38:18 by jkertgat          #+#    #+#              #
#    Updated: 2018/12/13 17:47:34 by jkertgat         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_lstmap.c ft_striter.c ft_strsplit.c ft_atoi.c ft_lstnew.c \
ft_putendl_fd.c ft_striteri.c ft_bzero.c ft_memalloc.c ft_putnbr.c \
ft_strjoin.c ft_strstr.c ft_isalnum.c ft_memccpy.c ft_putnbr_fd.c ft_strlcat.c \
ft_strsub.c ft_isalpha.c ft_memchr.c ft_putstr.c ft_strlen.c ft_strtrim.c \
ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strmap.c ft_swap.c ft_isdigit.c \
ft_memcpy.c ft_strcat.c ft_strmapi.c ft_tolower.c ft_isprint.c ft_memdel.c \
ft_strchr.c ft_strncat.c ft_toupper.c ft_isspace.c ft_memmove.c ft_strclr.c \
ft_strncmp.c ft_wordcnt.c ft_itoa.c ft_memset.c ft_strcmp.c ft_strncpy.c \
ft_lstadd.c ft_num_len.c ft_strcpy.c ft_strnequ.c ft_lstdel.c ft_putchar.c \
ft_strdel.c ft_strnew.c ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c \
ft_lstiter.c ft_putendl.c ft_strequ.c ft_strrchr.c ft_itoa_base.c ft_strrev.c \
ft_intlen.c  ft_longint.c

NAME := libft.a

OBJ = $(SRC:.c=.o)

.PHONY:
	clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -g -I includes -c $(SRC)
	make -C ft_printf

clean:
	@/bin/rm -f $(OBJ)
	make clean -C ft_printf

fclean: clean
	make fclean -C ft_printf

re: fclean all

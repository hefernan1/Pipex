# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 15:53:44 by hefernan          #+#    #+#              #
#    Updated: 2022/02/21 11:33:01 by hefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_printdeuxfreres.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_itoa.c \
		ft_itoa_base.c \

OBJ =	ft_printf.o \
		ft_printdeuxfreres.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_itoa.o \
		ft_itoa_base.o \

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

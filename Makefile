# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 02:05:36 by hefernan          #+#    #+#              #
#    Updated: 2022/03/04 12:00:15 by hefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -Wall -Werror -Wextra

SRCS =		pipex.c \
			childs_paths.c \
			free.c \
			msg_err.c \
			ft_strncmp.c \
			ft_strdup.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \


OBJ =	$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

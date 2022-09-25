# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 22:55:16 by skrairab          #+#    #+#              #
#    Updated: 2022/09/25 20:26:39 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c\
		ft_opened.c\
		ft_flodfill.c



NAME = so_long

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) -g (CC_FLAGS) -o $(NAME) $(SRCS)

clean: rm -rf $(NAME)
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)
		rm -rf *.o
		rm -rf so_long

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 22:55:16 by skrairab          #+#    #+#              #
#    Updated: 2022/09/25 21:46:34 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c\
		ft_opened.c\
		ft_floodfill.c


NAME = so_long

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

LIBDIR = ./Libftc

INCLUDE = -Llibftc -lft

$(NAME):
	make -C $(LIBDIR)
	$(CC) -g $(CC_FLAGS) -o $(NAME) $(SRCS) $(INCLUDE)


clean:
	   rm -rf *.o
		make -C $(LIBDIR) clean

fclean: clean
		rm -rf $(NAME)
		rm -rf so_long
		make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
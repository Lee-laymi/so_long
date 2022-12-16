# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ami <ami@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 22:55:16 by skrairab          #+#    #+#              #
#    Updated: 2022/12/15 21:38:12 by ami              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c\
		ft_opened.c\
		ft_floodfill.c\
		checker1.c\
		checker2.c\
		create_map.c\
		ft_getnextline/get_next_line_utils.c\
		ft_getnextline/get_next_line.c\

NAME = so_long

OBJS = $(SRCS:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

LIBDIR = ./Libfts

LIBPRINTF = ./ft_printf

INCLUDE = -L Libfts -lft -L ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	make -C $(LIBPRINTF)
	$(CC) -g $(CC_FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)


clean:
	   rm -rf *.o
		make -C $(LIBDIR) clean

fclean: clean
		rm -rf $(NAME)
		rm -rf so_long
		make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
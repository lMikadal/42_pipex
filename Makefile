# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 10:57:04 by pmikada           #+#    #+#              #
#    Updated: 2022/09/19 10:57:07 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_A = pipex.a

MAIN = main.c

SRCS =	ft_pipex.c ft_utils.c ft_split.c ft_free.c ft_error.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

all: $(NAME)

$(NAME): $(OBJS)
		$(GCC) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJS)

clean:
		rm -rf *.o

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

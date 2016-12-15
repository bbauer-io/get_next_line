# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:20:35 by bbauer            #+#    #+#              #
#    Updated: 2016/11/15 15:46:28 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRC = get_next_line.c
OPT = $(SRC:.c=.o)
HEADER = get_next_line.h
INCLUDE = -I./libft/
LIBFT = libft/libft.a
FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libft/ all
	gcc $(OPTIONS) $(INCLUDE) $(HEADER) $(SRC) $(FLAGS)
	ar rc $(NAME) $(OPT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OPT)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f get_next_line.h.gch

re: fclean all

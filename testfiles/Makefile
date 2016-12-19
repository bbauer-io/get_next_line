# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 16:20:35 by bbauer            #+#    #+#              #
#    Updated: 2016/12/15 15:59:06 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRC = get_next_line.c testmain.c
OPT = $(SRC:.c=.o)
HEADER = get_next_line.h
INCLUDE = -I./libft/
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ./libft/ re
	gcc $(OPTIONS) $(INCLUDE) $(LIBFT) $(HEADER) $(SRC) $(FLAGS)

test:
	make -C ./libft/ re
	gcc $(OPTIONS) $(INCLUDE) $(LIBFT) $(HEADER) $(SRC) $(FLAGS) -g

clean:
	/bin/rm -f $(OPT)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f get_next_line.h.gch

re: fclean all

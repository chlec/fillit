# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 13:15:43 by clecalie          #+#    #+#              #
#    Updated: 2017/09/20 11:29:10 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = main.c ft_func.c store_data.c check_square.c ft_create_elem.c ft_list_push_back.c tab_is_val.c set_params.c ft_open.c

OBJ = main.o ft_func.o store_data.o check_square.o ft_create_elem.o ft_list_push_back.o tab_is_val.o set_params.o ft_open.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

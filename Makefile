# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 16:17:06 by clecalie          #+#    #+#              #
#    Updated: 2017/11/24 13:36:04 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c \
		check_tetrim.c \
		ft_create_elem.c \
		get_length.c \
		ft_list_push_back.c \
		store_data.c

OBJ = $(SRCS:.c=.o)

LIBFT = ./libft

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) $(SRCS) -c
	gcc $(OBJ) $(LIBFT)/libft.a -o $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

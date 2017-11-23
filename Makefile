# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 16:17:06 by clecalie          #+#    #+#              #
#    Updated: 2017/11/14 16:18:42 by clecalie         ###   ########.fr        #
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

all:
	make -C $(LIBFT)
	$(MAKE) $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -c
	gcc $(OBJ) $(LIBFT)/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

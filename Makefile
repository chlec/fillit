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

SRCS = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	gcc $(SRCS) -c
	gcc $(OBJ) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

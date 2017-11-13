/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:53:29 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 16:01:13 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# define BUF_SIZE 20

char	**split_by_jumpline(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
typedef struct	s_tetrim
{
	char	**content;
	int		x;
	int		y;
	struct s_tetrim *next;
}				t_tetrim;
t_tetrim *ft_create_elem(char **content, int x, int y);
#endif

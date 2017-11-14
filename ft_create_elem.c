/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:18:31 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/14 17:07:58 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_create_elem(char **content, int x, int y)
{
	t_tetrim	*list;
	char		**c;
	int			i;

	list = malloc(sizeof(t_tetrim));
	c = (char**)malloc(sizeof(char*) * 20);
	if (list)
	{
		i = 0;
		while (content[i])
		{
			c[i] = ft_strdup(content[i]);
			i++;
		}
		list->content = c;
		list->x = x;
		list->y = y;
	}
	return (list);
}

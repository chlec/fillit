/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:18:31 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 15:01:33 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_create_elem(char **content, int x, int y)
{
	t_tetrim	*list;

	list = malloc(sizeof(t_tetrim));
	if (list)
	{
		list->content = content;
		list->x = x;
		list->y = y;
		list->next = NULL;
	}
	return (list);
}

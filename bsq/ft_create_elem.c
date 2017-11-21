/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:18:31 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/19 17:30:25 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_pos_square	*ft_create_elem(int x, int y, int size)
{
	t_pos_square	*list;

	list = malloc(sizeof(t_pos_square));
	if (list)
	{
		list->x = x;
		list->y = y;
		list->size = size;
		list->next = NULL;
	}
	return (list);
}

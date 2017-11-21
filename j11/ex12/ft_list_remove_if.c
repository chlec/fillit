/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:51:27 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/20 17:41:53 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list;
	t_list	*after;
	t_list	*before;

	list = *begin_list;
	before = *begin_list;
	while (list)
	{
		if ((*cmp)(list->data, data_ref) == 0)
		{
			after = list->next;
			free(list);
			before->next = after;
			list = after;
		}
		else
			list = list->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:43:36 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/18 16:46:19 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*temp;

	list = *begin_list;
	temp = 0;
	while (list)
	{
		temp = list;
		if (list->next)
		{
			free(temp);
			list = list->next;
		}
		else
			free(temp);
	}
	*begin_list = NULL;
}

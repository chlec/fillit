/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:35:24 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/20 15:45:31 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*list;
	t_list	*tab;
	t_list	*tab2;

	tab = NULL;
	list = *begin_list;
	if (!list || !(list->next))
		return ;
	tab = list->next;
	tab2 = tab->next;
	list->next = NULL;
	tab->next = list;
	while (tab2)
	{
		list = tab;
		tab = tab2;
		tab2 = tab2->next;
		tab->next = list;
	}
	*begin_list = tab;
}

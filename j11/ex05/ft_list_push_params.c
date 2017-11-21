/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:08:44 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/21 12:53:14 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*list;

	list = ft_create_elem(data);
	list->next = *begin_list;
	*begin_list = list;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;

	(void)ac;
	list = NULL;
	i = 1;
	while (av[i])
	{
		ft_list_push_front(&list, av[i]);
		i++;
	}
	return (list);
}

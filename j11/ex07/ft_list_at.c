/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:31:39 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/20 14:39:45 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list)
	{
		i = 0;
		while (begin_list)
		{
			i++;
			if (i == nbr)
				return (begin_list);
			begin_list = begin_list->next;
		}
	}
	return (0);
}

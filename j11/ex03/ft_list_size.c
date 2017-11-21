/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:00:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/18 11:34:49 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;

	if (begin_list)
	{
		i = 0;
		while (begin_list)
		{
			begin_list = begin_list->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}

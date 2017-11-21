/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_is_val.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 09:44:49 by mdaunois          #+#    #+#             */
/*   Updated: 2017/09/19 17:40:39 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		tab_is_val(char **tab, t_params *params)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	k = params->width;
	while (tab[i])
	{
		j = 0;
		while (tab[i] && tab[i][j])
		{
			if (tab[i][j] != params->block && tab[i][j] != params->empty)
				return (0);
			j++;
		}
		if (j != k)
			return (0);
		i++;
	}
	i--;
	if (i != params->lines)
		return (0);
	return (1);
}

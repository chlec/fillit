/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_carre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaunois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:31:43 by mdaunois          #+#    #+#             */
/*   Updated: 2017/09/20 10:52:09 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void			remplir_carre(char **tab, t_pos_square *big, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	while (i < big->size)
	{
		j = 0;
		while (j < big->size)
		{
			if (tab[i + big->x] && tab[i + big->x][j + big->y])
				tab[i + big->x][j + big->y] = params->filled;
			j++;
		}
		i++;
	}
	i = 1;
	while (tab[i])
	{
		ft_putstr(1, tab[i]);
		ft_putchar(1, '\n');
		free(tab[i]);
		i++;
	}
}

int				verif_carre(char **tab, t_pos_square *pos, int t, t_params *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= t && i <= p->lines)
	{
		while (j <= t && j <= p->width)
		{
			if (!tab[i + pos->x] || !tab[i + pos->x][j + pos->y]
					|| tab[i + pos->x][j + pos->y] != p->empty)
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

t_pos_square	*parcour_verif(t_params *params, t_pos_square *pos, char **tab)
{
	int						i;
	t_pos_square			*big;
	int						max;

	max = 0;
	big = ft_create_elem(0, 0, 0);
	while (pos)
	{
		i = max;
		while (i <= params->lines)
		{
			if (verif_carre(tab, pos, i, params))
			{
				pos->size = i + 1;
				max = pos->size - 1;
				if (pos->size > big->size)
					big = pos;
			}
			i++;
		}
		pos = pos->next;
	}
	return (big);
}

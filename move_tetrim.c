/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:16:41 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:31:52 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	replace_diese(char **tab, char c)
{
	int		i;
	int		j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '#')
				tab[j][i] = c;
			i++;
		}
		j++;
	}
}

void	move_tetrim_x(char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strcmp(tab[0], "...."))
	{
		while (tab[j])
		{
			if (ft_strcmp(tab[j], "....") != 0)
			{
				while (tab[j])
				{
					tab[i] = ft_strdup(tab[j]);
					tab[j] = ft_strdup("....");
					i++;
					j++;
				}
			}
			j++;
		}
	}
}

void	move_tetrim_ybis(char **tab, int *i, int *j, int *y)
{
	while (*i < 4)
	{
		while (*j < 4)
		{
			tab[*j][*y] = tab[*j][*i];
			tab[*j][*i] = '.';
			(*j)++;
		}
		(*j) = 0;
		(*y)++;
		(*i)++;
	}
}

void	move_tetrim_y(char **tab)
{
	int		i;
	int		j;
	int		y;

	y = 0;
	i = 1;
	if (tab[0][0] == '.' && tab[1][0] == '.' && tab[2][0] == '.'
			&& tab[3][0] == '.')
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (tab[j][i] != '.')
				{
					move_tetrim_ybis(tab, &i, &j, &y);
					return ;
				}
				j++;
			}
			i++;
		}
}

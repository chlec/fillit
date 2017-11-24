/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:18:31 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:59:40 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*ft_create_elem(char **content, int x, int y, char letter)
{
	t_tetrim	*list;
	char		**c;
	int			i;

	list = malloc(sizeof(t_tetrim));
	c = (char**)malloc(sizeof(char*) * 21);
	if (list)
	{
		i = 0;
		while (content[i])
		{
			c[i] = ft_strdup(content[i]);
			i++;
		}
		list->content = c;
		list->x = x;
		list->y = y;
		list->letter = letter;
	}
	return (list);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

char		**create_tab(int size)
{
	char	**tab;
	int		x;
	int		j;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (x < size)
	{
		j = 0;
		if (!(tab[x] = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
		while (j < size)
		{
			tab[x][j] = '.';
			j++;
		}
		tab[x][j] = '\0';
		x++;
	}
	tab[x] = 0;
	return (tab);
}

void		print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void		add_tetrim(t_tetrim *aa, char **tab, int size)
{
	int		x;
	int		y;
	int		a;
	int		b;

	a = aa->x;
	x = 0;
	while (a < size)
	{
		y = 0;
		b = aa->y;
		while (b < size)
		{
			if (x < 4 && y < 4 && aa->content[x][y] != '.' &&
					tab[a] && tab[a][b] && tab[a][b] == '.')
				tab[a][b] = aa->content[x][y];
			b++;
			y++;
		}
		a++;
		x++;
	}
}

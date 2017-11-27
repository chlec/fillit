/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:50:28 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/27 12:02:00 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	store_tetrim(char **tab, char c, t_list **head, char *str)
{
	int		i;
	char	**tetrim;

	if (!(tetrim = (char**)malloc(sizeof(char*) * (ft_strlen(str) + 2))))
		return ;
	i = 0;
	while (i < 4)
	{
		if (!(tetrim[i] = ft_strnew(5)))
			return ;
		tetrim[i] = tab[i];
		i++;
	}
	tetrim[i] = 0;
	replace_diese(tetrim, c);
	move_tetrim_x(tetrim);
	move_tetrim_y(tetrim);
	ft_list_push_back(head, ft_create_elem(tetrim, 0, 0, c));
	free_tab(tetrim);
}

t_list	*split_by_jumpline(char *str)
{
	t_list		*head;
	char		**tab;
	int			id;
	char		c;

	if (!(tab = ft_strsplit(str, '\n')))
		return (0);
	id = 0;
	head = 0;
	c = 'A';
	while (tab[id])
	{
		if (id % 4 == 0)
		{
			store_tetrim(&tab[id], c++, &head, str);
		}
		id++;
	}
	free(tab);
	return (head);
}

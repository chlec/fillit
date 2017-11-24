/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:28:05 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 17:00:59 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lstnew(data, sizeof(t_tetrim));
	}
	else
		*begin_list = ft_lstnew(data, sizeof(t_tetrim));
}

int		isintab(char **tab, t_tetrim *aa)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == aa->letter)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		isvalid(char **tab, int size, t_list *list)
{
	t_tetrim	*aa;

	if (!list)
		return (1);
	aa = (t_tetrim*)(list->content);
	aa->x = 0;
	aa->y = 0;
	while (aa->x <= size - get_height(aa))
	{
		if (chek(aa, tab, size))
		{
			add_tetrim(aa, tab, size);
			if (isvalid(tab, size, list->next) == 1)
				return (1);
			else
				remove_tetrim(tab, size, aa);
		}
		aa->y++;
		if (aa->y > size - get_width(aa))
		{
			aa->y = 0;
			aa->x++;
		}
	}
	return (0);
}

char	**put_content(t_list *list, int size)
{
	char	**tab;

	tab = create_tab(size);
	if (isvalid(tab, size, list))
		return (tab);
	else
	{
		free_tab(tab);
		return (put_content(list, size + 1));
	}
	return (tab);
}

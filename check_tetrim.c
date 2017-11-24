/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:28:19 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:53:12 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_sticked(int *tab)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i] != tab[j])
				if (tab[j] + 5 == tab[i] || tab[j] - 1 == tab[i]
						|| tab[j] + 1 == tab[i] || tab[j] - 5 == tab[i])
					count++;
			j++;
		}
		i++;
	}
	return (count >= 6);
}

int		check_together(char *str)
{
	size_t	i;
	int		count;
	int		*tab;

	i = 0;
	count = 0;
	tab = (int*)malloc(sizeof(int) * 4);
	while (str[i])
	{
		if (str[i] == '#')
			tab[count++] = i;
		else if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (count != 4)
				return (0);
			if (!check_sticked(tab))
				return (0);
			free(tab);
			tab = (int*)malloc(sizeof(int) * 4);
			count = 0;
		}
		i++;
	}
	return (1);
}

int		check_square(char *str)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (str[i])
	{
		j++;
		if (str[i] == '\n')
		{
			if (j != 5 && j != 1)
				return (0);
			j = 0;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		check_jumpline(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0' && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n'
				&& str[i + 2] && str[i + 2] == '\n')
			return (0);
		if (str[i] == '\n' && str[i - 1] != '\n')
			count++;
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (count != 4)
				return (0);
			count = 0;
		}
		i++;
	}
	return (1);
}

int		check_content(char *str)
{
	if ((check_jumpline(str)
				&& check_square(str) && check_together(str)))
		return (1);
	return (0);
}

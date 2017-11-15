/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:28:19 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/15 17:44:37 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			{
				printf("j: %d\n", j);
				return (0);
			}
			j = 0;
		}
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
		if (str[i] == '\n')
			count++;
		i++;
	}
	if ((count + 1) % 5 == 0)
		return (1);
	return (0);
}

int		check_charac(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		check_content(char *str)
{
	if (check_charac(str) && check_jumpline(str) && check_square(str))
		return (1);
	return (0);
}
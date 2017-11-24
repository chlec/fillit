/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:35:27 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_height(t_tetrim *aa)
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
			if (aa->content[i][j] != '.')
			{
				count++;
				j = 3;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int		get_width(t_tetrim *aa)
{
	int		i;
	int		j;

	j = 3;
	while (j >= 0)
	{
		i = 3;
		while (i >= 0)
		{
			if (aa->content[i][j] != '.')
				return (j + 1);
			i--;
		}
		j--;
	}
	return (0);
}

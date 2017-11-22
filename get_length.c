/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/17 12:57:28 by mdaunois         ###   ########.fr       */
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
	while (aa->content[i])
	{
		j = 0;
		while (aa->content[i][j])
		{
			if (aa->content[i][j] != '.') {
				count++;
				break;
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
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (aa->content[i])
	{
		j = j;
		while (aa->content[i][j])
		{
			if (aa->content[i][j] != '.') {
				count++;
			}
			else if (aa->content[i][j] == '.')
				break;
			j++;
		}
		i++;
	}
	return (count);
}
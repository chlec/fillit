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
	int		count;

	i = 0;
	count = 0;
	while (aa->content[i] && aa->content[i][0] != '.')
	{
		count++;
		i++;
	}
	return (count);
}

int		get_width(t_tetrim *aa)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (aa->content[0][i] && aa->content[0][i] != '.')
	{
		count++;
		i++;
	}
	return (count);
}
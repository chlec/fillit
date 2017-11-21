/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 10:56:38 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/19 17:46:44 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char		*ft_strndup(char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;
	char			*copy;

	len = 0;
	while (src[len])
		len++;
	copy = (char*)malloc(sizeof(*src) * (len + 1));
	i = 0;
	while (i < len && i <= size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_params	*set_params(char **tab)
{
	t_params	*params;
	int			len;

	params = malloc(sizeof(t_params));
	if (tab[0] && tab[1] && ft_strlen(tab[0]) > 3 && ft_strlen(tab[1]) > 0)
	{
		len = ft_strlen(tab[0]);
		params->lines = ft_atoi(ft_strndup(tab[0], len - 4));
		params->width = ft_strlen(tab[1]);
		params->filled = tab[0][len - 1];
		params->block = tab[0][len - 2];
		params->empty = tab[0][len - 3];
	}
	else
		params->lines = 0;
	return (params);
}

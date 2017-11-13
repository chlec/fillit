/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:50:28 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 14:57:39 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	if (end >= 0)
	{
		word = (char*)malloc(sizeof(char) * (end + 1));
		i = 0;
		while (start <= end)
		{
			word[i] = str[start];
			start++;
			i++;
		}
		word[i] = '\0';
		return (word);
	}
	else
		return ("\n");
}

int		nb_words(char *str)
{
	int		words;
	int		i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			words++;
		i++;
	}
	return (words);
}

char	**split_by_jumpline(char *str)
{
	char	**tab;
	int		start;
	int		end;
	int		id;

	tab = (char**)malloc(sizeof(*tab) * nb_words(str) + 1);
	end = 0;
	start = 0;
	id = 0;
	while (str[end])
	{
		if (str[end + 1] == '\n')
		{
			if (get_word(str, start, end)[0] != '\n')
				tab[id++] = get_word(str, start, end);
			start = end + 2;
		}
		end++;
	}
	tab[id] = 0;
	return (tab);
}

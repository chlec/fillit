/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:50:28 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/15 13:07:13 by clecalie         ###   ########.fr       */
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

t_list	*split_by_jumpline(char *str)
{
	t_list	*head;
	t_tetrim *content;
	char	**tab;
	char	*word;
	int		start;
	int		end;
	int		id;
	int		j;
	int		e = 0;

	tab = (char**)malloc(sizeof(*tab) * (nb_words(str) + 1));
	end = 0;
	start = 0;
	id = 0;
	content = 0;
	head = 0;
	while (str[end])
	{
		if (str[end + 1] == '\n')
		{
			word = get_word(str, start, end);
			if (word[0] != '\n' && word[0] != '\0' && str[end + 1] != '\0')
			{
				tab[id++] = word;
			}
			else
			{
				tab[id] = 0;
				content = ft_create_elem(tab, 0, 0);
				ft_list_push_back(&head, content);
				free(content);
				free(tab);
				tab = (char**)malloc(sizeof(*tab) * (nb_words(str) + 1));
				id = 0;
			}
			start = end + 2;
		}
		end++;
	}
	free(tab);
	return (head);
}

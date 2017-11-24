/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:50:28 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 17:02:26 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	**store_tetrim(char **tab, char *c, t_list **head, char *str)
{
	replace_diese(tab, *c);
	move_tetrim_x(tab);
	move_tetrim_y(tab);
	ft_list_push_back(head, ft_create_elem(tab, 0, 0, *c));
	free_tab(tab);
	if (!(tab = (char**)malloc(sizeof(*tab) * (nb_words(str) + 1))))
		return (0);
	(*c)++;
	return (tab);
}

t_list	*split_by_jumpline(char *str)
{
	t_list		*head;
	char		**tab;
	char		*word;
	int			start;
	int			end;
	int			id;
	char		c;

	if (!(tab = (char**)malloc(sizeof(*tab) * (nb_words(str) + 1))))
		return (0);
	end = 0;
	start = 0;
	id = 0;
	head = 0;
	c = 'A';
	while (str[end])
	{
		if (str[end + 1] == '\n' || str[end + 1] == '\0')
		{
			word = get_word(str, start, end);
			if (word[0] != '\n' && word[0] != '\0' && str[end + 1] != '\0')
				tab[id++] = word;
			else
			{
				tab[id] = 0;
				tab = store_tetrim(tab, &c, &head, str);
				id = 0;
			}
			start = end + 2;
		}
		end++;
	}
	free_tab(tab);
	return (head);
}

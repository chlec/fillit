/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:50:28 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/22 13:51:13 by clecalie         ###   ########.fr       */
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

void	replace_diese(char **tab, char c)
{
	int		i;
	int		j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '#')
				tab[j][i] = c;
			i++;
		}
		j++;
	}
}

void	move_tetrim_x(char	**tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strcmp(tab[0], "...."))
	{		
		while (tab[j])
		{
			if (ft_strcmp(tab[j], "....") != 0)
			{
				while (tab[j])
				{
					tab[i] = ft_strdup(tab[j]);
					tab[j] = ft_strdup("....");
					i++;
					j++;
				}
			}
			j++;
		}
	}
}

void	move_tetrim_y(char	**tab)
{
	int		i;
	int		j;
	int		y;

	y = 0;
	i = 1;
	if (tab[0][0] == '.' && tab[1][0] == '.' && tab[2][0] == '.' && tab[3][0] == '.')
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (tab[j][i] != '.')
				{
					while (i < 4)
					{
						while (j < 4)
						{
							tab[j][y] = tab[j][i];
							tab[j][i] = '.';
							j++;
						}
						j = 0;
						y++;
						i++;
					}
					return ;
				}
				j++;
			}
			i++;
		}
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
	char	c;

	tab = (char**)malloc(sizeof(*tab) * (nb_words(str) + 1));
	end = 0;
	start = 0;
	id = 0;
	content = 0;
	head = 0;
	c = 'A';
	while (str[end])
	{
		if (str[end + 1] == '\n' || str[end + 1] == '\0')
		{
			word = get_word(str, start, end);
			if (word[0] != '\n' && word[0] != '\0' && str[end + 1] != '\0')
			{
				tab[id++] = word;
			}
			else
			{
				tab[id] = 0;
				replace_diese(tab, c);
				move_tetrim_x(tab);
				move_tetrim_y(tab);
				content = ft_create_elem(tab, 0, 0, c);
				c++;
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

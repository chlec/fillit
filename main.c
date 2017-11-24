/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/24 16:56:01 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_file_content(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	*tab1;
	char	*tab2;
	int		len;

	len = BUF_SIZE;
	tab2 = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (0);
		buf[ret] = '\0';
		if (!(tab1 = malloc(sizeof(char) * (len + 1))))
			return (0);
		if (tab2)
			tab1 = tab2;
		len += ret;
		if (!(tab2 = malloc(sizeof(char) * (len + 1))))
			return (0);
		tab2 = ft_strcpy(tab2, tab1);
		tab2 = ft_strcat(tab2, buf);
		free(tab1);
	}
	return (tab2);
}

int		chek(t_tetrim *aa, char **tab, int size)
{
	int x;
	int y;
	int a;
	int b;

	a = aa->x;
	x = 0;
	while (a < size)
	{
		y = 0;
		b = aa->y;
		while (b < size)
		{
			if (x < 4 && y < 4 && aa->content[x][y] != '.' && tab[a][b] != '.')
				return (0);
			b++;
			y++;
		}
		a++;
		x++;
	}
	return (1);
}

void	remove_tetrim(char **tab, int size, t_tetrim *aa)
{
	int a;
	int b;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size)
		{
			if (tab[a][b] == aa->letter)
				tab[a][b] = '.';
			b++;
		}
		a++;
	}
}

int		get_lowersize(t_list *list)
{
	int			size;
	t_tetrim	*aa;

	aa = (t_tetrim*)(list->content);
	size = get_width(aa);
	if (size < get_height(aa))
		size = get_height(aa);
	return (size);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	char	*content;
	char	**tab;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > -1)
		{
			content = get_file_content(fd);
			if (content != NULL && check_content(content))
			{
				list = split_by_jumpline(content);
				tab = put_content(list, get_lowersize(list));
				print_tab(tab);
				free_tab(tab);
				free(content);
				close(fd);
			}
			else
				ft_putendl("error");
		}
	}
}

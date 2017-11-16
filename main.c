/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/16 16:22:56 by mdaunois         ###   ########.fr       */
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

void	add_tetrim(t_tetrim *aa, char **tab, int size)
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
			if (x < 4 && y < 4 && aa->content[x][y] != '.')
			{
				tab[a][b] = aa->content[x][y];
			}
			b++;
			y++;
		}
		a++;
		x++;
	}
}


int		chek(t_tetrim *aa, char **tab, int size)
{
	int x;
	int y;
	int a;
	int b;

	a = aa->x;
	x = 0;
	while (a <= size)
	{
		y = 0;
		b = aa->y;
		while (b <= size)
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

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_tetrim *aa;
	char	*content;
	char	**tab;
	int		x;
	int 	good;
	int		i;
	int		j;
	int size = 8;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(**tab) * 200)))
		return (0);
	while (x < size)
	{
		j = 0;
		if (!(tab[x] = (char*)malloc(sizeof(char) * 200)))
			return (0);
		while (j < size)
		{

			tab[x][j] = '.';
			j++;
		}
		x++;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd > -1)
	{
		content = get_file_content(fd);
		if (check_content(content))
		{
			list = split_by_jumpline(content);
			while (list)
			{
				aa = (t_tetrim*)(list->content);
				while (!(good = chek(aa, tab, size)))// || aa->x == size - 1)
				{
					aa->y++;
					if (aa->y == size)
					{
						aa->x++;
						aa->y = 0;
					}	
				//	printf("(%d %d)\n", aa->x, aa->y);
				}
				if (good)
					add_tetrim(aa, tab, size);
				else
					printf("pas possible\n");
				list = list->next;
			}
			j = 0;
			while (tab[j])
			{
				i = 0;
				while (tab[j][i])
				{
					ft_putchar(tab[j][i]);
					i++;
				}
				ft_putchar('\n');
				j++;
			}	
			free(content);
			close(fd);
		}
		else
			printf("error\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/16 12:37:00 by mdaunois         ###   ########.fr       */
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
	int erreur;
	
	a = aa->x;
	b = aa->y;
	x = 0;
	erreur = 0;
	while (x < size)
	{
		y = 0;
		b = 0;
		while (y < size)
		{
			if (a < aa->x + 4 && b < aa->y + 4 && aa->content[a][b] != '.' && tab[x][y] == '.')
			{
				tab[x][y] = aa->content[a][b];
				erreur = 1;
			}
			ft_putchar(tab[x][y]);
			b++;
			y++;
		}
		ft_putchar('\n');
		a++;
		x++;
	}
	ft_putchar('\n');
	return (erreur);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_tetrim *aa;
	char	*content;
	char	**tab;
	int		x;
	int 	y;
	int		i;
	int		j;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(**tab) * 200)))
		return (0);
	while (x < 10)
	{
		j = 0;
		if (!(tab[x] = (char*)malloc(sizeof(char) * 200)))
			return (0);
		while (j < 10)
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
			i = 0;
			while (list)
			{
				y = chek((t_tetrim*)(list->content), tab, 10);
				printf("%d\n", y);
				list = list->next;
			}
			/*while (list)
			{
				aa = (t_tetrim*)(list->content);
				while (aa->content[i])
				{
					printf("%s\n", aa->content[i]);
					i++;
				}
				printf("\n");
				i = 0;
				list = list->next;
			}*/
			free(content);
			close(fd);
		}
		else
			printf("error\n");
	}
}

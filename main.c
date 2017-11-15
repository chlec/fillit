/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/15 17:45:12 by mdaunois         ###   ########.fr       */
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

	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			if (aa->content[x][y] != '.' && tab[x][y] != '.')
				return (0);
			y++;
		}
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
	int 	y;
	int		i;
	
	tab = (char**)malloc(sizeof(**tab) * 20);
	while (x < 20)
	{
		while (j < 20)
		{
			tab[x][j] = '.';
			j++;
		}
		i++;
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
				aa = (t_tetrim*)(list->content);
				while (aa->content[i])
				{
					printf("%s\n", aa->content[i]);
					i++;
				}
				printf("\n");
				i = 0;
				list = list->next;
			}
			free(content);
			close(fd);
		}
		else
			printf("error\n");
	}
}

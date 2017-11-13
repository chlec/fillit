/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/13 16:11:33 by clecalie         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		fd;
	char	**tab;
	char	**c;
	char	*content;
	int		x;
	int		i;
	t_tetrim *list;
	t_tetrim *first;

	fd = open(argv[1], O_RDONLY);
	if (fd > -1)
	{
		content = get_file_content(fd);
		tab = split_by_jumpline(content);
		i = 0;
		//while (tab[i])
		//	printf("%s\n", tab[i++]);
		free(content);
		close(fd);
	}
	x = 4;
	i = 0;
	list = 0;
	first = 0;
	while (x < 13)
	{
		c = malloc(sizeof(char) * 1000);
		while (i < x)
		{
			c[i] = tab[i];
			i++;
		}
		c[i] = 0;
		list = ft_create_elem(c, 0, 0);
		list = list->next;
		if (first == 0) 
		{
			first = list;
			printf("first made\n");
		}
		x += 4;
	}
	i = 0;
	printf("%s\n", first->content[0]);
	/*while ((first->content)[i])
	{
		printf("%s\n", (first->content)[i++]);
	}*/
}

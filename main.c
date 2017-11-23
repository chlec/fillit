/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/23 12:52:04 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

char	**create_tab(int size)
{
	char	**tab;
	int		x;
	int		j;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	while (x < size)
	{
		j = 0;
		if (!(tab[x] = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
		while (j < size)
		{
			tab[x][j] = '.';
			j++;
		}
		tab[x][j] = '\0';
		x++;
	}
	tab[x] = 0;
	return (tab);
}

void	print_tab(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j]) {
			ft_putchar(tab[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	reset(t_list **list)
{
	t_list		*head;
	t_tetrim	*aa;

	head = *list;
	while (head) {
		aa = (t_tetrim*)(head->content);
		aa->y = 0;
		aa->x = 0;
		head = head->next;
	}
}

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
			if (x < 4 && y < 4 && aa->content[x][y] != '.' && tab[a] && tab[a][b] && tab[a][b] == '.')
				tab[a][b] = aa->content[x][y];
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
	while (a < size)
	{
		y = 0;
		b = aa->y;
		while (b < size)
		{
			printf("Check %c: x%d y%d a%d b%d\n", aa->letter, x,y,a,b);
			if (x < 4  && y < 4 && aa->content[x][y] != '.' && tab[a][b] != '.')
			{
			//	printf("not available: aa: %c, tab %c\n", aa->content[x][y], tab[a][b]);
				return (0);
			}
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
	aa->y = 0;
	aa->x = 0;
}

int		isintab(char **tab, t_tetrim *aa)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == aa->letter)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		isValid(char **tab, int size, t_list **head)
{
	t_tetrim	*aa;
	t_list		*list;

	list = *head;
	if (!list)
		return (1);
	aa = (t_tetrim*)(list->content);
	while (isintab(tab, aa) && list)
	{
		list = list->next;
		if (list)
			aa = (t_tetrim*)(list->content);
		else
			return (1);
	}

		printf("TEST\n");
	while (!isintab(tab, aa) && aa->x <= size - get_height(aa))
	{
		printf("TEST\n");
		usleep(100000);
		printf("pour %c = hauteur:%d longeur:%d \n",aa->letter, get_height(aa), get_width(aa));
		print_tab(tab);
		if (chek(aa, tab, size))
		{
			add_tetrim(aa, tab, size);	
			if (isValid(tab, size, head) == 1)
				return (1);
			else
			{
				remove_tetrim(tab, size, aa);
				list = list->next;
				if (list)
					aa = (t_tetrim*)(list->content);
				else
					return (0);	
			}
		}
		else {
		printf("TEST2\n");
			aa->y++;
			if (aa->y > size - get_width(aa))
			{
				aa->y = 0;
				aa->x++;
			}
		}
	}
	remove_tetrim(tab, size, aa);
	return (0);
}

char	**put_content(t_list **list, int size)
{
	t_tetrim	*aa;
	char		**tab;
	int			good;
	t_list		*head;

	head = *list;
	tab = create_tab(size);
	if (isValid(tab, size, &head))
		return (tab);
	else
	{
		//print_tab(tab);
		free_tab(tab);
		reset(list);
		return (put_content(list, size + 1)); //on rappel la meme fonction en incrementant de 1
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	char	*content;
	char	**tab;
	int size;

	size = 4;	
	fd = open(argv[1], O_RDONLY);
	if (fd > -1)
	{
		content = get_file_content(fd);
		if (check_content(content))
		{
			list = split_by_jumpline(content);
			tab = put_content(&list, size);
			print_tab(tab);
			//free(tab);	
			free(content);
			close(fd);
		}
		else
			printf("error\n");
	}
}

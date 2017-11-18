/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:47:16 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/17 12:57:28 by mdaunois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	int	c;
	
	a = aa->x;
	x = 0;
	c = 0;
	while (a <= size)
	{
		y = 0;
		b = aa->y;
		while (b <= size)
		{
			if (x < 4 && y < 4 && aa->content[x][y] != '.' && tab[a][b] == '.')
			{
				printf("tab[a][b]: x: %d, y: %d, a: %d, b: %d\n", x, y, a, b);
				tab[a][b] = aa->content[x][y];
				c++;
			}
			if (c == 4)
				return ;
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
			printf("%c: x%d y%d a%d b%d\n", aa->letter, x,y,a,b);
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

char	**create_tab(int size)
{
	char	**tab;
	int		x;
	int		j;

	x = 0;
	if (!(tab = (char**)malloc(sizeof(**tab) * (size + 1))))
		return (0);
	while (x < size)
	{
		j = 0;
		if (!(tab[x] = (char*)malloc(sizeof(*tab) * (size + 1))))
			return (0);
		while (j < size)
		{
			tab[x][j] = '.';
			j++;
		}
		tab[x][j] = '\0';
		x++;
	}
	tab[x] = NULL;
	return (tab);
}

char	**put_content(t_list **list, int size)
{
	t_tetrim	*aa;
	char		**tab;
	int			good;
	t_list		*head;
	int			i;

	head = *list;
	tab = create_tab(size);
	while (head)
	{
		aa = (t_tetrim*)(head->content);
		printf("Trying: %c %d %d\n", aa->letter, aa->x, aa->y);
		print_tab(tab);
		while ((!(good = chek(aa, tab, size))) && aa->x < size - 1) // pour le deuxieme argument, il faut mettre la hauteur de la 
																	// piece pour qu'il s'arret au bon moment
		{
			aa->y++;
			if (aa->y == size) // a mon avis c'est pareil ici = size - longeur de la piece
			{
				aa->x++;
				aa->y = 0;
			}	
		}
		if (good)
		{
			printf("sa pose %c, x: %d, y: %d\n", aa->letter, aa->x, aa->y);
			add_tetrim(aa, tab, size);
			head = head->next;
		}
		else
		{
			printf("pas possible: %c\n", aa->letter);
			//reset(list);
			i = 0;
			while (i < size)
				free(tab[i++]);
			tab = NULL;
			//return (tab);
			aa->y = 0;
			aa->x = 0;
			return (put_content(list, size + 1));
		}
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

	size = 5;	
	fd = open(argv[1], O_RDONLY);
	if (fd > -1)
	{
		content = get_file_content(fd);
		if (check_content(content))
		{
			list = split_by_jumpline(content);
			tab = put_content(&list, size);
			//print_tab(tab);
			//free(tab);	
			free(content);
			close(fd);
		}
		else
			printf("error\n");
	}
}

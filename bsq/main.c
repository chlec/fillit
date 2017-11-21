/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:33:32 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/20 14:46:58 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_pos_square	*get_list(char **tab, t_params *params)
{
	int				x;
	int				y;
	t_pos_square	*pos;

	pos = NULL;
	x = 1;
	while (x <= params->lines)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			if (tab[x][y] != params->block)
				ft_list_push_back(&pos, x, y, 0);
			y++;
		}
		x++;
	}
	return (pos);
}

int				check_bsq_data(char **tab)
{
	t_params		*params;
	t_pos_square	*pos;
	t_pos_square	*big;

	big = NULL;
	pos = NULL;
	params = set_params(tab);
	if (params->lines == 0)
		return (0);
	if (!tab_is_val(tab, params))
		return (0);
	pos = get_list(tab, params);
	big = parcour_verif(params, pos, tab);
	remplir_carre(tab, big, params);
	free(tab);
	return (1);
}

void			read_bsq(char *file)
{
	int				fd;
	char			**tab;
	char			*content;

	fd = open(file, O_RDONLY);
	if (fd > -1)
	{
		content = get_file_content(fd);
		if (content == 0)
		{
			ft_putstr(2, "map error\n");
			return ;
		}
		tab = split_by_jumpline(content);
		if (!check_bsq_data(tab))
			ft_putstr(2, "map error\n");
		close(fd);
	}
	else
		ft_putstr(2, "map error\n");
}

void			read_stdin(void)
{
	char			**tab;
	char			*content;

	content = get_file_content(0);
	if (content == 0)
	{
		ft_putstr(2, "map error\n");
		return ;
	}
	tab = split_by_jumpline(content);
	if (!check_bsq_data(tab))
		ft_putstr(2, "map error\n");
	close(0);
}

int				main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		read_stdin();
	else
	{
		i = 1;
		while (argv[i])
		{
			read_bsq(argv[i]);
			if (argv[i + 1])
				ft_putchar(1, '\n');
			i++;
		}
	}
	return (0);
}

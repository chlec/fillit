/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 09:47:50 by clecalie          #+#    #+#             */
/*   Updated: 2017/09/20 11:29:30 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void			ft_putchar(int fd, char c);

void			ft_putstr(int fd, char *str);

char			**split_by_jumpline(char *str);

int				nb_words(char *str);

char			*get_word(char *str, int start, int end);

int				ft_strlen(char *str);

int				ft_atoi(char *str);

typedef	struct	s_pos_square
{
	int					x;
	int					y;
	int					size;
	struct s_pos_square	*next;
}				t_pos_square;

typedef struct	s_params
{
	int		lines;
	int		width;
	char	empty;
	char	block;
	char	filled;
}				t_params;

int				verif_carre(char **tab, t_pos_square *pos,
							int tail, t_params *params);

t_pos_square	*parcour_verif(t_params *params,
								t_pos_square *pos, char **tab);

t_pos_square	*ft_create_elem(int x, int y, int size);

void			ft_list_push_back(t_pos_square **begin_list,
								int x, int y, int size);

void			remplir_carre(char **tab, t_pos_square *big, t_params *params);

int				tab_is_val(char **tab, t_params *params);

t_params		*set_params(char **tab);

char			*ft_strndup(char *src, unsigned int i);

char			*ft_strcpy(char *dest, char *src);

char			*ft_strcat(char *dest, char *src);

char			*get_file_content(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:53:29 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/22 13:50:22 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# define BUF_SIZE 1

char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
typedef struct	s_tetrim
{
	char	**content;
	int		x;
	int		y;
	char	letter;
}				t_tetrim;
t_tetrim *ft_create_elem(char **content, int x, int y, char letter);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
t_list	*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
t_list	*split_by_jumpline(char *str);
char			*ft_strdup(const char *s1);
void	ft_list_push_back(t_list **begin_list, void *data);
int		check_content(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
int		get_height(t_tetrim *aa);
int		get_width(t_tetrim *aa);
int     get_lowersize(t_list *list);
void	ft_strdel(char **as);
char	**create_tab(int size);
void	print_tab(char **tab);
void	free_tab(char **tab);
void	add_tetrim(t_tetrim *aa, char **tab, int size);
int		chek(t_tetrim *aa, char **tab, int size);
void	remove_tetrim(char **tab, int size, t_tetrim *aa);
int		isintab(char **tab, t_tetrim *aa);
int		isValid(char **tab, int size, t_list *list);
char	**put_content(t_list *list, int size);

#endif

#include "fillit.h"

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
            if (x < 4  && y < 4 && aa->content[x][y] != '.' && tab[a][b] != '.')
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

int		isValid(char **tab, int size, t_list *list)
{
    t_tetrim	*aa;
    
    if (!list)
        return (1);
    aa = (t_tetrim*)(list->content);
    aa->x = 0;
    aa->y = 0;
    while (aa->x <= size - get_height(aa))
    {
        if (chek(aa, tab, size))
        {
            add_tetrim(aa, tab, size);
            if (isValid(tab, size, list->next) == 1)
                return (1);
            else
                remove_tetrim(tab, size, aa);
        }
        aa->y++;
        if (aa->y > size - get_width(aa))
        {
            aa->y = 0;
            aa->x++;
        }
    }
    return (0);
}

char	**put_content(t_list *list, int size)
{
    t_tetrim	*aa;
    char		**tab;
    int			good;
    
    tab = create_tab(size);
    if (isValid(tab, size, list))
        return (tab);
    else
    {
        free_tab(tab);
        return (put_content(list, size + 1));
    }
    return (tab);
}

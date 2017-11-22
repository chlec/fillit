//
//  main.c
//  sudoku
//
//  Created by mathieu daunois on 09/09/2017.
//  Copyright © 2017 mathieu daunois. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int verif_bloc(char **tab, char nb, int i, int j)
{
    int verif;
    int i2;
    int j2;

    verif = 0;
	i2 = i - (i % 3);
    j2 = j - (j % 3);
	i = i2;
    while (i < i2 + 3)
    {
		j = j2;
        while (j < j2 + 3)
        {
            if (tab[i][j] == nb)
                verif = 1;
            j++;
        }
        i++;
    }
    return (verif);
}

int verif_l_c(char **tab, char nb, int ligne, int colone)
{
    int i;
    int verif;
    
    verif = 0;
    i = 0;
    while (i < 9)
    {
        if (tab[ligne][i] == nb)
            verif = 1 ;
        i++;
    }
    i = 0;
    while (i < 9)
    {
        if (tab[i][colone] == nb)
            verif = 1;
        i++;
    }
    return (verif);
}

void affiche_tab(char **tab)
{
    
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < 9)
    {
        while (tab[i][j] != '\0')
        {
            printf("%c ",tab[i][j]);
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
    printf("\n");
}

void free_tab(char **tab)
{
    int i;
    
    i = 0;
    while (i < 9)
    {
     	free(tab[i]);
        i++;
    }
    free(tab);
}


int estvalide (char **tab, int position)
{
    int ligne;
    int  colone;
    char k;
    ligne = position/9;
    colone= position%9;
	if (position == 81)
		return (1);
    if (tab[ligne][colone] != '.')
		return (estvalide(tab, position +1));
	k ='1';
    while (k <= '9')
    {
		if (!(verif_l_c(tab, k, ligne, colone) == 1) && !(verif_bloc(tab, k, ligne, colone) == 1))
        {
			tab[ligne][colone] = k;
			if (estvalide(tab, position + 1) == 1)
				return (1);
		}
		k++;
	}
	tab[ligne][colone] = '.';
	return (0);
}

int main(int argc, char * argv[])
{
    char **tab = NULL;
    int i;
    
    i = 1;
    tab = (char**)malloc(sizeof(**tab) * 9 );
    while (i < argc + 1)
    {
        tab[i] = (char*)malloc(sizeof(*tab) * 9);
        tab[i-1] = argv[i];
        i++;
    }
    affiche_tab(tab);
    estvalide(tab,0);
    affiche_tab(tab);
	//free_tab(tab);
    
    return 0;
}

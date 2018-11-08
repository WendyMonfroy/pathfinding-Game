#include "map.h"
/****************************************************
 * Nom de fichier : map.c
 * Role : Le fichier definie le corps des fonctions de gestion de matrices
 * Les fonctions suivantes sont définie dans se fichier :
 *      -> init_mat : initialise dynamiquement une matrice avec une valeur
 *		-> fillmap : remplit la matrice de terrain
 * 		-> fillvisit : remplit la matrice des point visités avec les noeuds inaccessibles
 * 		-> filldistance : remplit la matrice de distance estimée pour A*
 *      -> visit : passe le point considéré à 1 (visité) dans la matrice des noeuds visités
 *		-> negativpts : compte le nombre de noeuds inaccessibles
 *      -> matrixdisplay : affiche une matrice
 *      -> free_mat : libère l'espace mémoire alloué à une matrice
 *
 * Auteurs : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/

/* Description générale: permet dinitialiser une matrice
 *
 * 	Entrée :
 *      value   : valeur à mettre dans la matrice
 *
 *  Sortie : pointeur sur la matrice créée
*/
int ** init_mat(int value){
    int i,j;
    int **mat = (int **)malloc(NBLIN * sizeof(int *));
    for (i=0; i<NBLIN; i++)
    {
         mat[i] = (int *)malloc(NBCOL * sizeof(int));
    }
    for(i=0; i<NBLIN; i++)
    {
        for(j=0; j<NBCOL;j++)
        {
            mat[i][j] = value;
        }
    }
    return mat;
}

/* Description générale: permet de remplir la matrice de terrain à partir d'un fichier texte
 *
 * 	Entrée :
 *      filename    : nom du fichier à exploiter
 *      mat         : pointeur sur la matrice à remplir
*/
void fillmap(char* filename, int** mat)
{
    int val, i, j;
    FILE * f = fopen(filename, "r");
    if (f != NULL)
    {
        i = 0;
        fscanf(f,"%d%*c", &val);
        while (!feof(f))
        {
            j = 0;
            while(j<NBCOL)
            {
                mat[i][j] = val;
                fscanf(f,"%d%*c", &val);
                j++;
            }
            i++;
        }
    }
    fclose(f);
}

/* Description générale: permet de remplir la matrice des noeuds visités à partir de la matrice de terrain
 *
 * 	Entrée :
 *      vis     : pointeur sur la matrice des noeuds visités
 *      mat     : pointeur sur la matrice de terrain
*/
void fillvisit(int** vis, int** mat)
{
    int i, j;
    for (i=0; i<NBLIN; i++)
    {
        for (j=0; j<NBCOL; j++)
        {
            if (mat[i][j]<0)
            {
                visit(vis, i,j);
            }
        }
    }
}

/* Description générale: permet de calculer la distance estimée au point d'arrivée
 *
 * 	Entrée :
 *      estdist     : pointeur sur la matrice de distance estimée
 *      goal        : entier correspondant au noeud d'arrivée
*/
void filldistance(int** estdist, int goal)
{
    int i,j;
    int x = goal/NBCOL;
    int y = goal%NBCOL-1;

    for (i=-NBLIN+1; i<NBLIN; i++)
    {
        for (j=-NBCOL+1; j<NBCOL; j++)
        {
            if (x+i>-1 && x+i<NBLIN && y+j>-1 && y+j<NBCOL)
            {
                estdist[x+i][y+j] = fabs(i)+fabs(j);
            }
        }
    }
}

/* Description générale: passe le noeud à visité
 *
 * 	Entrée :
 *      vis     : pointeur sur la matrice des noeuds visités
 *      i et j  : coordonnées du point considéré
*/
void visit(int** vis, int i, int j)
{
    vis[i][j] = 1;
}

/* Description générale: compte le nmbre de points inaccessibles de la matrice de terrain
 *
 * 	Entrée :
 *      tab     : pointeur sur la matrice de terrain
 *
 *  Sortie : nombre de points négatifs (inaccessibles) trouvés
*/
int negativpts(int** tab)
{
    int i, j;
    int total = 0;
    for (i=0;i<NBLIN;i++)
    {
        for (j=0;j<NBCOL;j++)
        {
            if (tab[i][j] < 0)
            {
                total++;
            }
        }
    }
    return total;
}

/* Description générale: permet d'afficher une matrice
 *
 * 	Entrée :
 *      mat     : pointeur sur la matrice à afficher
*/
void matrixdisplay(int** mat)
{
    int i,j;
    for (i=0;i<NBLIN;i++)
    {
        for (j=0;j<NBCOL;j++)
        {
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
}

/* Description générale: permet de libérer l'espace mémoire alloué à une matrice
 *
 * 	Entrée :
 *      mat     : pointeur sur la matrice à libérer
*/
void free_mat(int** mat)
{
    int i;

    for(i=0; i<NBLIN; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

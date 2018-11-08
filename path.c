#include <unistd.h>
#include "path.h"
/****************************************************
 * Nom de fichier : path.c
 Role : Le fichier definie le corps des fonctions de recherche du pus court chemin
 * Les fonctions suivantes sont définie dans se fichier :
 * 		-> dijkstra : algorithme de dijkstra
 * 		-> chose_next : pemet de séléctionner le prochain point étudié dans dijkstra
 *      -> Astar : algorithme A*
 *      -> chose_astar : pemet de séléctionner le prochain point étudié dans A*
 *		-> pathfind : crée la pile correspondant au chemin trouvé
 *
 * Auteur : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/

/* Description générale: applique l'algorithme de dijkstra
 *
 *  Entrée :
 *      tab         : Matrice de terrain
 *      minilengh   : Matrice des distances minimales
 *      precursor   : Matrice des précurseurs
 *      visited     : Matrice des points visités
*/
void dijkstra(int** tab, int** minilengh, int** precursor, int** visited,  int arr)
{
    int nbit = 0;
    int nbpts = NBCOL*NBLIN - negativpts(tab);
    int pt, x, y, i, j;

    while (nbit<nbpts)
    {
        pt = chose_next(visited, minilengh);
        x = pt/NBCOL;
        y = pt%NBCOL - 1;
        if(y<0){
            x--;
            y = NBCOL - 1;
        }

        for(i=-1;i<2;i++)
        {
            for(j=-1;j<2;j++)
            {
                if ((i!=0 || j!=0) && x+i>-1 && x+i<NBLIN && y+j>-1 && y+j<NBCOL)
                {
                    /* correspond aux cases accessibles */
                    if (visited[x+i][y+j]==0 && (minilengh[x][y]+(tab[x][y]+tab[x+i][y+j])/2 < minilengh[x+i][y+j] || minilengh[x+i][y+j]==100 ))
                    {
                        minilengh[x+i][y+j] = minilengh[x][y] + (tab[x][y]+tab[x+i][y+j])/2;
                        precursor[x+i][y+j] = x*NBCOL+y+1;
                    }
                }
            }
        }
        visit(visited, x, y);
        nbit++;
    }
}

/* Description générale: choisit le noeud dont minlengh est minimale parmis les points non visités
 *
 * Variables utilisées : coordonnées du nouveau point à traiter
 *  Entrée :
 *      vis         : Matrice des points visités
 *      minilengh   : Matrice des distances minimal
 *
 *  Sortie : nouveau point
*/
int chose_next(int** vis, int** minlengh)
{
    int i, j, resx = 0, resy=0;
    int min = 100;
    for(i=0;i<NBLIN;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            if (vis[i][j] == 0 && minlengh[i][j]<min)
            {
                min = minlengh[i][j];
                resx = i;
                resy = j;
            }
        }
    }
    return (resx*NBCOL + resy + 1);
}

/* Description générale: applique l'algorithme A*
 *
 *  Entrée :
 *      tab         : Matrice du terrain ou executer l'algorithme
 *      minilengh   : Matrice des distances minimal
 *      precursor   : Matrice des précurseurs
 *      visited     : Matrice des points visités
 *      estdist     : Matrice des JE SAIS PAS!!!
 *      goal        : Int representant le point d'arrive
*/
void Astar(int** tab, int** minilengh, int** precursor, int** visited, int**estdist, int goal)
{
    int nbit = 0;
    int nbpts = NBCOL*NBLIN - negativpts(tab);
    int pt, x, y, i, j;

    while (nbit<nbpts)
    {
        pt = chose_astar(visited, minilengh,estdist);
        x = pt/NBCOL;
        y = pt%NBCOL - 1;
        if(y<0){
            x--;
            y = NBCOL - 1;
        }

        for(i=-1;i<2;i++)
        {
            for(j=-1;j<2;j++)
            {
                if ((i!=0 || j!=0) && x+i>-1 && x+i<NBLIN && y+j>-1 && y+j<NBCOL)
                {
                    /* correspond aux cases accessibles */
                    if (minilengh[x][y]+(tab[x][y]+tab[x+i][y+j])/2 < minilengh[x+i][y+j] || minilengh[x+i][y+j]==100 )
                    {
                        minilengh[x+i][y+j] = minilengh[x][y] + (tab[x][y]+tab[x+i][y+j])/2;
                        precursor[x+i][y+j] = x*NBCOL+y+1;
                    }
                }
            }
        }
        visit(visited, x, y);
        nbit++;
    }
}

/* Description générale: permet de choisir le prochain points (minimal) pour A star en se basant
sur la matrice minlengh et en verifiant que le point n'est pas encore été visité
 *
 *  Entrée :
 *      vis         : Matrice des points visités
 *      minilengh   : Matrice des distances minimal
 *      estdist     : Matrice des JE SAIS PAS!!!
 *
 *  Sortie : Coordonée en int du prochain point à traité
*/
int chose_astar(int** vis, int** minlengh, int** estdist)
{
    int i, j, resx = 0, resy=0;
    int min = 100;
    for(i=0;i<NBLIN;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            if (vis[i][j] == 0 && minlengh[i][j]+estdist[i][j]<min)
            {
                min = minlengh[i][j];
                resx = i;
                resy = j;
            }
        }
    }
    return (resx*NBCOL + resy + 1);
}

/* Description générale: permet de créer une pile qui contindra le chemin le plus optimal
 *
 *  Entrée :
 *      precursor   : Matrice des précurseurs
 *      start       : Int contenant les coordonnéees du point de départ
 *      goal        : Int contenant les coordonnéees du point d'arrivée
 *
 *  Sortie : pile contenant le chemin trouvé
*/
pile_t* pathfind(int** precursor, int start, int goal)
{
    pile_t* path = createpile();
    list_t* new;
    int pt = goal;

    while (pt != start)
    {
        new = (list_t*)malloc(sizeof(list_t));
        new->elt = pt;
        pileUP(path, new);
        pt = precursor[pt/NBCOL][pt%NBCOL-1];
    }
    new = (list_t*)malloc(sizeof(list_t));
    new->elt = pt;
    pileUP(path, new);
    return path;
}

/* Description générale: transcrit le contenu de la pile dans une matrice
 *
 *  Entrée :
 *      path   : Pile contenant le chemin optimal
 *      mat    : Matrice ou l'on va ecrire le chemin optimal
*/
void draw_path(pile_t* path, int** mat)
{
    int pt;
    while (!empty(path)){
        pt = pileDOWN(path);
        mat[pt/NBCOL][pt%NBCOL-1] = 1;
    }
    freepile(path);
}

#ifndef __PATH__
#define __PATH__
/****************************************************
 * Nom de fichier : path.h
 * Role : définit les fonctions de recherche du plus court chemin
 * 		-> dijkstra : algorithme de dijkstra
 * 		-> chose_next : pemet de séléctionner le prochain point étudié dans dijkstra
 *      -> Astar : algorithme A*
 *      -> chose_astar : pemet de séléctionner le prochain point étudié dans A*
 *		-> pathfind : crée la pile correspondant au chemin trouvé
 *
 * Pour une description detaillée des fonctions reportez-vous au fichier "path.c"
 *
 * Auteur : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "pile.h"

void dijkstra(int** tab, int** minilengh, int** precursor, int** visited, int arr);
int chose_next(int** vis, int** minlengh);
pile_t* pathfind(int** precursor, int start, int goal);
void draw_path(pile_t* path, int** mat);

#endif

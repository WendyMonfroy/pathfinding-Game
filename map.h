#ifndef __MAP__
#define __MAP__
/****************************************************
 * Nom de fichier : map.h
 * Role : définit les fonctions dde gestion de matrice
 * 		-> init_mat : initialise une matrice avec une valeur
 * 		-> fillmap : remplit une matrice à partir d'un fichier
 *      -> fillvisit : considère les points innaccessibles commes visités
 * 		-> filldistance : remplit la matrice de distance estimée pour A*
 *      -> visit : passe le point considéré en visité
 *		-> negativpts : compte le nombre de points innacessibles de la map
 *      -> matrixdisplay : affiche une matrice
 *      -> free_mat : libère l'espace alloué à la matrice
 *
 * Pour une description detaillée des fonctions reportez-vous au fichier "map.c"
 *
 * Auteur : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NBCOL 10
#define NBLIN 10

int ** init_mat(int Value);
void fillmap(char* filename, int** mat);
void fillvisit(int** vis, int** mat);
void visit(int** vis, int i, int j);
int negativpts(int** tab);
void matrixdisplay(int** mat);
void free_mat(int** mat);

#endif

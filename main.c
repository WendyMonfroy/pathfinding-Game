#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "pile.h"
#include "path.h"

int main()
{
	int start;
	int goal;
	int** mat = init_mat(0);

	/* initialisation des matrices et de la pile utilisées par l'algorithme de Dijkstra */
	int** minlenghD = init_mat(1000);
	int** precurD = init_mat(-1);
	int** visitedD = init_mat(0);
	int** resultD = init_mat(0);
	pile_t* pathD;

	/* initialisation des matrices et de la pile utilisées par l'algorithme A* */
	int** estdist = init_mat(0);
	int** minlenghA = init_mat(1000);
	int** precurA = init_mat(-1);
	int** visitedA = init_mat(0);
	int** resultA = init_mat(0);
	pile_t* pathA;

	printf("Veuillez entrer un point de départ entre 1 et %d :", NBLIN*NBCOL-1);
	scanf("%d%*c", &start);
	printf("Veuillez entrer un point d'arrivée entre 1 et %d :", NBLIN*NBCOL-1);
	scanf("%d%*c", &goal);

	/* préparation de l'environement de travail */
	fillmap("matrix.txt", mat);
	minlenghD[start/NBCOL][start%NBCOL-1] = 0;
	minlenghA[start/NBCOL][start%NBCOL-1] = 0;
	filldistance(estdist, goal);
	fillvisit(visitedD, mat);
	fillvisit(visitedA, mat);

	/* application des algorithmes de Dijkstra et A* et détermination des chemins */
	dijkstra(mat, minlenghD, precurD, visitedD,  goal);
	Astar(mat, minlenghA, precurA, visitedA, estdist, goal);
	pathD = pathfind(precurD, start, goal);
	draw_path(pathD, resultD);
	pathA = pathfind(precurA, start, goal);
	draw_path(pathA, resultA);

	printf("Affichage de la matrice de terrain :\n");
	matrixdisplay(mat);

	/* affichage des résultats de l'algorithme de Dijkstra */
	printf("matrice des points visités : \n");
	matrixdisplay(visitedD);
	printf("\n");
	printf("matrice des longueurs min : \n");
	matrixdisplay(minlenghD);
	printf("\n");
	printf("matrice des précurseurs : \n");
	matrixdisplay(precurD);
	printf("\n");
	printf("chemin final : \n");
	matrixdisplay(resultD);

	printf("\n \n");
	/* affichage des résultats de l'algorithme A* */
	printf("matrice des points visités : \n");
	matrixdisplay(visitedA);
	printf("\n");
	printf("matrice des distances au point d'arrivée \n");
	matrixdisplay(estdist);
	printf("\n");
	printf("matrice des longueurs min : \n");
	matrixdisplay(minlenghA);
	printf("\n");
	printf("matrice des précurseurs : \n");
	matrixdisplay(precurA);
	printf("\n");
	printf("chemin final : \n");
	matrixdisplay(resultA);

	/* libération de l'espace mémoire alloué */
	free_mat(mat);
	free_mat(minlenghD);
	free_mat(precurD);
	free_mat(visitedD);
	free_mat(resultD);
	free_mat(minlenghA);
	free_mat(precurA);
	free_mat(visitedA);
	free_mat(resultA);
	free_mat(estdist);


	return 0;
}

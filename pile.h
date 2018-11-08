#ifndef PILE_H
#define PILE_H
/****************************************************
 * Nom de fichier : pile.h
 * Role : définit les fonctions de gestion de pile
 * 		-> pileUP : empile l'élément
 * 		-> pileDOWN : dépile le dernier élément
 *      -> pileLAST : renvoie le dernier élément sans le dépiler
 *      -> createpile : initialise la pile
 *		-> empty : vérifie si la pie est vide
 *      -> full : vérifie si la pile est pleine
 *      -> freepile : libère l'espace alloué à la pile
 *
 * Pour une description detaillée des fonctions reportez-vous au fichier "pile.c"
 *
 * Auteur : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/
#include <stdlib.h>
#include <stdio.h>

/* liste chainée d'éléments de la pile */
typedef struct list
{
    int elt;
    struct list_t * next;
}list_t;

/* structure de la pile utilisant la liste chainée */
typedef struct pile
{
    int psize;
    list_t * list;
}pile_t;

pile_t* createpile();
int empty(pile_t* p);
void pileUP(pile_t* p, list_t* new);
int pileDOWN(pile_t* p);
int pileLAST(pile_t* p);
void piledisplay(pile_t* p);
void freepile(pile_t * p);

#endif

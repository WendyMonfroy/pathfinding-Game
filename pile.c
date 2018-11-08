/****************************************************
 * Nom de fichier : pile.c
 * Role : Le fichier definie le corps des fonctions pour la structure de pile (pile_t)
 * Les fonctions suivantes sont définie dans se fichier :
 *      -> createpile : initialise la pile
 *		-> empty : vérifie si la pie est vide
 * 		-> pileUP : empile l'élément
 * 		-> pileDOWN : dépile le dernier élément
 *      -> pileLAST : renvoie le dernier élément sans le dépiler
 *		-> piledisplay : affiche la pile
 *      -> freepile : libère l'espace alloué à la pile
 *
 * Auteurs : Monfroy Wendy
 * Date : 2018
 * Copyright : CC BY-NC-ND 3.0 FR
*****************************************************/
#include "pile.h"

/* Description générale: crée la pile et l'initialise à vide
 *
 *  Sortie : pointeur sur la tête de la pile
*/
pile_t* createpile()
{
    pile_t* p = (pile_t*)malloc(sizeof(pile_t));
    p->psize = 0;
    p->list = NULL;

    return p;
}

/* Description générale: permet de savoir si la pile est vide ou non
 *      Note : pas besoin de fonction full car la structure en liste chainée n'a pas de limite
 *
 * Variables utilisées : booléen
 * 	Entrée : pointeur sur la tête de la pile
 *
 *  Sortie : booléen
*/
int empty(pile_t* p)
{
    int res=0;
    if (p->psize == 0)
    {
        res = 1;
    }
    return res;
}

/* Description générale: permet d'empiler un élément dans la pile
 *      Note: un nouvel élément est placé en tête de pile
 *
 * 	Entrée :
 *      p   : pointeur sur la tête de la pile
 *      new : pointeur sur l'élément à empiler
*/
void pileUP(pile_t* p, list_t* new)
{
    if (empty(p)==1)
    {
        p->list = new;
        p->psize = 1;
    }
    else
    {
        new->next = p->list;
        p->list = new;
        p->psize ++;
    }
}

/* Description générale: dépile le dernier élément de la pile
 *      Note : l'élément à dépiler est en tête
 *
 * Variables utilisées : résultat et pointeur courant et temporaire dans la liste chainée
 * 	Entrée : pointeur sur la tête de la pile
 *
 *  Sortie : élément supprimé
*/
int pileDOWN(pile_t* p)
{
    int res = 0;
    list_t* l;
    list_t* temp;
    if (empty(p)==0)
    {
        l = p->list;
        res = l->elt;
        temp = l;
        l = l->next;
        p->list = l;
        free(temp);
        p->psize --;
    }else{
        printf("err pile vide\n");
    }
    return res;
}

/* Description générale: permet d'acceder au dernier élément de la pile
 *
 * Variables utilisées : résultat
 * 	Entrée : pointeur sur la tête de la pile
 *
 *  Sortie : élément en fin de pile
*/
int pileLAST(pile_t* p)
{
    int res = 0;
    if (empty(p)==0)
    {
        res = p->list->elt;
    }
    return res;
}

/* Description générale: permet d'afficher la pile
 *
 * Variables utilisées : pointeur i dns la liste chainée
 * 	Entrée : pointeur sur la tête de la pile
*/
void piledisplay(pile_t* p)
{
    list_t * i = p->list;
    while (i != NULL)
    {
        printf("%d \n", i->elt);
        i = i->next;
    }
}

/* Description générale: permet de libérer la pile
 *
 * Variables utilisées : pointeur courant et suivant
 * 	Entrée : pointeur sur la tête de la pile
*/
void freepile(pile_t* p)
{
    list_t* cour = p->list;
    list_t* suiv;
    while (cour != NULL)
    {
        suiv = cour->next;
        free(cour);
        cour = suiv;
    }
    free(p);
}

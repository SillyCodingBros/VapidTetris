#ifndef HEAD_H
#define HEAD_H

/* -------------- Include ---------- */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* -------------- Define ----------- */
#define WIDTH 25
#define HEIGHT 20

typedef struct {
    char* data;
    int size;
    int len;
}container;

/* fonction de update.c */
///Renvoie un tableau contenant tout les index de lignes pleines
int* detectRow(container* grid);
///detecte si une ligne est pleine
char fullRow(container* grid, int index);
///Supprime les lignes contenue dans le tableau indexList
void deleteRow(container* grid, int* indexList);
///Renvoie un tableau contenant tout les index de colonnes pleines
int* detectCol(container* grid);
///detecte si une colonne est pleine
char fullCol(container* grid, int index);
///Supprime les colonnes contenue dans le tableau indexList
void deleteCol(container* grid, int* indexList);
///S'occupe de replacer toute les cases de la grille selon les index qui ont été supprimé
void gravity(container* grid, int* index_list_line, int* index_list_col);

///Fonction qui s'occupe de tout les appelles de detection, de suppression et de replacer les grilles
void update(container* grid);

/* fonction de container.c */

/** initialise la structure container à la taille spécifiée par width et height.
  * Appellée par les créateurs de pièce et reserve l'espace mémoire pour la
  * case. Lors de l'initialisation, data est rempli de 0 (cases vide) */
void initContainer(int width, int height, container* item);

/** Génère un entier aléatoire. Celon le résultat obtenu, lance la fonction
  * créant la pièce correspondante puis la retourne */
container randomPiece();

/** Génère la pièce demandée en créant une pièce à la taille nécessaire puis
  * remplis les cases avec des 1 (case pleine) pour donner forme a la pièce.
  * Une fois formée, cette pièce est renvoyée à randomPiece. */

container createPiece(int num_piece);

/* free le data de la pièce passée en argument */
void deleteContainer(container* item);
int checkCollision(container * grid, container * piece, int x, int y);
void place(container * grid, container * piece, int x, int y);

/* fonction de user.c */
void display(container* grid);
void rotate_90(container *piece);
void info();

void miroir(container*piece);
#endif

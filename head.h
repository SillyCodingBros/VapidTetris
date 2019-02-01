#ifndef HEAD_H
#define HEAD_H

/* -------------- Include ---------- */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* -------------- Define ----------- */
#define WIDTH 20
#define HEIGHT 25

typedef struct {
    char* data;
    int size;
    int len;
}container;

/* fonction de update.c */
int* detectRow(container* grid);
char fullRow(container* grid, int index);
void deleteRow(container* grid, int* indexList);
int* detectCol(container* grid);
char fullCol(container* grid, int index);
void deleteCol(container* grid, int* indexList);
void gravity(container* grid, int* index_list_line, int* index_list_col);
void update(container* grid);

/* fonction de container.c */

/* initialise la structure container à la taille spécifiée par width et height. Appellée par les créateurs de pièce et reserve l'espace mémoire
pour la case. Lors de l'initialisation, data est rempli de 0 (cases vide) */
void initContainer(int width, int height, container* item);

/* Génère un entier aléatoire. Celon le résultat obtenu, lance la fonction créant la pièce correspondante puis la retourne */
container randomPiece();
<<<<<<< HEAD

/* Génère la pièce demandée en créant une pièce à la taille nécessaire puis remplis les cases avec des 1 (case pleine) pour donner forme a la pièce
 * Une fois formée, cette pièce est renvoyée à randomPiece. */
=======
/* Génère la pièce demandée en créant une pièce à la taille nécessaire puis remplis les cases avec des 1 (case pleine) pour donner forme a la pièce.
Une fois formée, cette pièce est renvoyée à randomPiece. */
>>>>>>> 990beb1aef323be079498a33a837adf089dcaf8b
container createU();
container createL1();
container createL2();
container createCross();
container createDot();
container createLine();

/* free le data de la pièce passée en argument */
void deleteContainer(container* item);
<<<<<<< HEAD

=======
int checkCollision(container * grid, container * piece, int x, int y);
void place(container * grid, container * piece, int x, int y);
>>>>>>> 990beb1aef323be079498a33a837adf089dcaf8b

/* fonction de utilisateur.c */
void display(container* grid);
void seize(container *grid, container *piece);
void rotate(container* item);

#endif

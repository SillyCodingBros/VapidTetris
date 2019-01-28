/* truc du head.h */
/* -------------- Include ---------- */
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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
pour la case. */ 
void initContainer(int width, int height, container* item);
/* Génère un entier aléatoire. Celon le résultat obtenu, */
container randomPiece();
container createU();
container createL1();
container createL2();
container createCross();
container createDot();
container createLine();

void deleteContainer(container* item);
//a completer avec les fonctions de generation pour chaque piece

/* fonction de utilisateur.c */
void affichage(container* grid);
void rotate(container* item);
//a completer avec les fonctions de placement et de collision

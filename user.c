#include "head.h"

void display(container* grid){
    char *toShow = "36m";
    int i;

    for (i = 0; i < grid->len+2; i++) {
        printf("-");
    }
    printf("\n|");

    for (i = 0; i < grid->size; i++) {
        if (i % grid->len == 0 && i != 0) {
            printf("|%d\n|", (i/grid->len)-1);  // Erreur ! Affichage de 23 puis 25 dans les deux dernières lignes de la zone de jeu, et même phénomène pour la preview pièce
        }

        switch (grid->data[i]) {
            case 2:
                toShow = "31m";
                break;
            default:
                break;
        }

        if (grid->data[i] > 0){
            printf("\033[%sX", toShow);
        }else{
            printf(" ");
        }
    }
    printf("|%d\n",i/grid->len-1);
    for (i = 0; i < grid->len+2; i++) {
        printf("-");
    }
    printf("\n");
}

void rotate_180(container *piece)
{
    int i,j,width,height;
    width=piece->size/piece->len;
    height=piece->len;
    char * tmp=malloc(sizeof(char)*width*height);
    for(i=0;i<width;i++)
        for(j=0;j<height;j++)
            tmp[i*width+j]=piece->data[i+width*j];

    for(i=0;i<width;i++)
        for(j=0;j<height;j++)
            piece->data[i*width+j]=tmp[i*width+j];
    free(tmp);
}

void rotate_90(container *piece)
{
    int i,j,width,height;
    width=piece->size/piece->len;
    height=piece->len;
    char * tmp=malloc(sizeof(char)*width*height);
    for(i=0;i<width;i++)
        for(j=0;j<height;j++)
          if(j== 0)
                tmp[i*width+j]=piece->data[width*(width-1)+i];

            else if (j>0  && j <width)
                tmp[i*width+j]=piece->data[width*j+i];
            else if(j == width)
                     tmp[i*width+j]=piece->data [width-i];

    for(i=0;i<width;i++)
        for(j=0;j<height;j++)
            piece->data[i*width+j]=tmp[i*width+j];
    free(tmp);
}

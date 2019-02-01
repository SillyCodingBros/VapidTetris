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
            printf("|\n|");
        }

        switch (grid->data[i]) {
            case 2:
                toShow = "31m";
                break;
        }

        if (grid->data[i] > 0){
            printf("\033[%sX", toShow);
        }else{
            printf(" ");
        }
    }
    printf("|\n");
    for (i = 0; i < grid->len+2; i++) {
        printf("-");
    }
    printf("\n");
}
void rotate_360(container *piece)
{   
    //fait tourné la piece a 360
    int i,j;
    char*tmp=malloc(sizeof(char)*piece->width*piece->height);
    for(i=0;i<piece->width;i++)
        for(j=0;j<piece->height;j++)
            tmp[i*piece->width+j]=piece->data[i+piece->width*j];

    for(i=0;i<piece->width;i++)
        for(j=0;j<piece->height;j++)
            piece->data[i*piece->width+j]=tmp[i*piece->width+j];
        
    free(tmp);  
}

void rotate_180(container *piece)
{   
    int i,j;
    char * tmp=malloc(sizeof(char)*piece->width*piece->height);
    for(i=0;i<piece->width;i++)
        for(j=0;j<piece->height;j++)
            tmp[i*piece->width+j]=piece->data[i+piece->width*j];
    
    for(i=0;i<piece->width;i++)
        for(j=0;j<piece->height;j++)
            piece->data[i*piece->width+j]=tmp[i*piece->width+j];
    free(tmp);  
}
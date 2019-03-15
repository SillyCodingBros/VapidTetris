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
            printf("|%d\n|", (i/grid->len)-1);
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
    printf("|%d\n",i/grid->len);
    for (i = 0; i < grid->len+2; i++) {
        printf("-");
    }
    printf("\n");
}

void rotate_90(container *piece)
{   
    int i,j,height;
    
    height=piece->len;
    char * tmp=malloc(sizeof(char)*height*height);
     for(i=0;i<piece->size;i++)
        tmp[i]=0;
    miroir(piece);
    for(i=0;i<height;i++)
        for(j=0;j<height;j++)   
            tmp[i*height+j]=piece->data[i+height*j];

    for(i=0;i<piece->size;i++)
            piece->data[i]=tmp[i];
    j=0;
    for(i=0;i<height;i++)    
        if(piece->data[i]==0)
            j++;
    if(j==height){
          for(i=height;i<piece->size;i++)
            piece->data[i-height]=tmp[i];
           for(i=height*height-height;i<piece->size;i++)
            piece->data[i]=0;
        }
    free(tmp);  
}

void miroir(container*piece)
{
    int i,j,height;
    height=piece->len;
    char * tmp=malloc(sizeof(char)*height*height);
    for(i=0;i<piece->size;i++)
        tmp[i]=0;   
        
    for(i=0;i<height;i++)
        for(j=0;j<height;j++)   
            tmp[i*height+j]=piece->data[i*height+height-1-j];
    for(i=0;i<piece->size;i++)
            piece->data[i]=tmp[i];

    free(tmp);  

}


void info()
{
    printf("pour se deplacer a droite a 'd'\npour se deplacer a gauche a 'q'\npour se deplacer en haut a 'z'\npour se deplcaer en bas appuyer sur 's' \npour faire une rotation a 90 appuyer sur 'r' \npour faire un miroir appuyer sur 'm' \npour placer une piece appuer sur 'p ' \n");
}


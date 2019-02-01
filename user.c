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

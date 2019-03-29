#include <SDL2/SDL.h>
#include "head.h"
#include <unistd.h>
typedef struct{
    SDL_Rect border;
    SDL_Rect cases;
    SDL_Color color;
    Uint8 r,g,b;
}cell;

cell* initDisplay(container* grid, int cellSize);
void sdlDisplay(SDL_Renderer* renderer, cell* SDL_grid, container* grid, container* piece, SDL_Color color, int px, int py);
void sdlUpdateDisplay(cell* SDL_grid,container* piece, container* grid, SDL_Color color, int px, int py);

int main(int argc, char const *argv[]){

	int mode;

	if(argc > 1){
		mode = atoi(argv[1]);
	}
	else{
		mode = 0;
	}

    container play_grid, play_piece;
    int piece_x, piece_y;
    SDL_Color color;
    cell* SDL_grid;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init error: %s\n", SDL_GetError());
        exit(1);
    }

    initContainer(WIDTH, HEIGHT, &play_grid);

    if(mode == 1){
    	fillGrid(&play_grid);
    }

    SDL_grid = initDisplay(&play_grid, 30);
    if(SDL_grid == NULL) {
        printf("initDisplay error\n");
        exit(1);
    }
    info();
    SDL_Window* window = NULL;
    window = SDL_CreateWindow( "VapidTetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH*32+20, HEIGHT*32+20, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer ( window, -1, SDL_RENDERER_ACCELERATED);

    if(mode == 1){
    	play_piece = createPiece(3);
    }
    else{
	    play_piece = randomPiece();
	    piece_x = 0;
	    piece_y = 0;
	    color.r = 0;
	    color.g = 0;
	    color.b = 0;
	}

    sdlDisplay(renderer, SDL_grid, &play_grid, &play_piece, color, piece_x, piece_y);

    int tmp = 1;
    while (tmp) {
        sleep(0.1);
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case 'q': piece_x-=1; break;
                    case 'd': piece_x+=1; break;
                    case 'z': piece_y-=1; break;
                    case 's': piece_y+=1; break;
                    case 'p':
                        if (checkCollision(&play_grid, &play_piece, piece_x, piece_y)) {
                            printf("Can't fit here!\n");
                        }
                        else{
                            place(&play_grid, &play_piece, piece_x, piece_y);
                            sdlUpdateDisplay(SDL_grid,&play_piece,&play_grid, color, piece_x, piece_y);
                            play_piece = randomPiece();
                            update(&play_grid);
                        }
                        break;
                    case 'm':
                        miroir(&play_piece);

                        break;
                    case 'r':
                    rotate_90(&play_piece);
                    break ;                       }
                if (piece_x<0) {
                    piece_x = 0;
                }
                if (piece_y<0) {
                    piece_y = 0;
                }
                if (piece_x>play_grid.len-play_piece.len) {
                    piece_x = play_grid.len-play_piece.len;
                }
                if (piece_y>(play_grid.size/play_grid.len)-(play_piece.size/play_piece.len)) {
                    piece_y = (play_grid.size/play_grid.len)-(play_piece.size/play_piece.len);
                }
                sdlDisplay(renderer, SDL_grid, &play_grid, &play_piece, color, piece_x, piece_y);
                break;
            case SDL_QUIT:
                tmp = 0;
                break;
            default :
                break;
        }
    }

    return 0;
}

cell* initDisplay(container* grid, int cellSize){
    cell* SDL_grid = malloc(sizeof(cell)*grid->size);
    for (int y = 0; y < grid->size/grid->len; y++) {
        for (int x = 0; x < grid->len; x++) {
            SDL_grid[(y*grid->len)+x].border.x = 10+((cellSize+2)*x);
            SDL_grid[(y*grid->len)+x].border.y = 10+((cellSize+2)*y);
            SDL_grid[(y*grid->len)+x].border.h = cellSize+2;
            SDL_grid[(y*grid->len)+x].border.w = cellSize+2;

            SDL_grid[(y*grid->len)+x].cases.x = 10+((cellSize+2)*x)+1;
            SDL_grid[(y*grid->len)+x].cases.y = 10+((cellSize+2)*y)+1;
            SDL_grid[(y*grid->len)+x].cases.w = cellSize;
            SDL_grid[(y*grid->len)+x].cases.h = cellSize;

            SDL_grid[(y*grid->len)+x].r = 0;
            SDL_grid[(y*grid->len)+x].g = 0;
            SDL_grid[(y*grid->len)+x].b = 255;
        }
    }
    return SDL_grid;
}

void sdlUpdateDisplay(cell* SDL_grid,container* piece, container* grid, SDL_Color color, int px, int py){
    int y, x;
    for (y = 0; y < grid->size/grid->len; y++) {
        for (x = 0; x < grid->len; x++) {
            if (x>=px && x<(px+piece->len) && y>=py && y<(py+(piece->size/piece->len)) && piece->data[((y-py)*piece->len)+x-px]) {
                SDL_grid[(y*grid->len)+x].r = color.r;
                SDL_grid[(y*grid->len)+x].g = color.g;
                SDL_grid[(y*grid->len)+x].b = color.b;
            }
        }
    }
}

void sdlDisplay(SDL_Renderer* renderer, cell* SDL_grid, container* grid, container* piece, SDL_Color color, int px, int py) {

    for (int y = 0; y < (grid->size/grid->len); y++) {
        for (int x = 0; x < grid->len; x++) {

            if (x>=px && x<(px+piece->len) && y>=py && y<(py+(piece->size/piece->len)) && piece->data[((y-py)*piece->len)+x-px]) {
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
            }else{
                SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
            }
            SDL_RenderFillRect( renderer, &(SDL_grid[(y*grid->len)+x].border));

            if(grid->data[(y*grid->len)+x] == 1){
                SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
            }
            else if(grid->data[(y*grid->len)+x] == 2){
                SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
            }
            else if(grid->data[(y*grid->len)+x] == 3){
                SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
            }
            else if(grid->data[(y*grid->len)+x] == 4){
                SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
            }
            else if(grid->data[(y*grid->len)+x] == 5){
                SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
            }
            else if(grid->data[(y*grid->len)+x] == 6){
                SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
            }
            else{
                SDL_SetRenderDrawColor( renderer, 123, 123, 123, 255 );
            }
            if (x>=px && x<(px+piece->len) && y>=py && y<(py+(piece->size/piece->len)) && piece->data[((y-py)*piece->len)+x-px]) {
                SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, 255);
            }
            SDL_RenderFillRect( renderer, &(SDL_grid[(y*grid->len)+x].cases));
        }
    }
    SDL_RenderPresent(renderer);
}

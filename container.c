#include "head.h"

void initContainer(int width, int height, container* item){
	item->len = width;
	item->size =width * height;
	item->data = malloc(item->size * sizeof(char));
	for (int i = 0; i < item->size; ++i)
	{
		item->data[i] = 0;
	}
}

container createPiece(int num_piece){
	container piece;
	char color = rand()%6+1;

	if (num_piece == 0){ // U
		initContainer(3, 3, &piece);
		piece.data[0] = color;
		piece.data[2] = color;
		piece.data[3] = color;
		piece.data[5] = color;
		piece.data[6] = color;
		piece.data[7] = color;
		piece.data[8] = color;
	}
	else if (num_piece == 1){ // L gauche
		initContainer(3, 2, &piece);
		piece.data[0] = color;
		piece.data[3] = color;
		piece.data[4] = color;
		piece.data[5] = color;
	}
	else if (num_piece == 2){ // L droit
		initContainer(3, 2, &piece);
		piece.data[2] = color;
		piece.data[3] = color;
		piece.data[4] = color;
		piece.data[5] = color;
	}
	else if (num_piece == 3){ // Croix
		initContainer(5, 5, &piece);
		piece.data[2] = color;
		piece.data[7] = color;
		piece.data[10] = color;
		piece.data[11] = color;
		piece.data[12] = color;
		piece.data[13] = color;
		piece.data[14] = color;
		piece.data[17] = color;
		piece.data[22] = color;
		piece.data[24] = 0;
	}
	else if (num_piece == 4){ // point
		initContainer(1, 1, &piece);
		piece.data[0] = color;
		return piece;
	}
	else if (num_piece == 5){ // I
		initContainer(2, 1, &piece);
		piece.data[0] = color;
		piece.data[1] = color;
	}
	else if (num_piece == 6){ // X
		initContainer(5, 5, &piece);
		piece.data[0] = color;
		piece.data[4] = color;
		piece.data[6] = color;
		piece.data[8] = color;
		piece.data[12] = color;
		piece.data[16] = color;
		piece.data[18] = color;
		piece.data[20] = color;
		piece.data[24] = color;
	}
	else if (num_piece == 7){ // x
		initContainer(3, 3, &piece);
		piece.data[0] = color;
		piece.data[2] = color;
		piece.data[4] = color;
		piece.data[6] = color;
		piece.data[8] = color;
	}
	return piece;
}

container randomPiece(){
	srand(time(NULL));
	int random = 8 * (rand() / (RAND_MAX + 1.0));
	return createPiece(random);
}

void deleteContainer(container * item){
	free(item->data);
}

int checkCollision(container * grid, container * piece, int x, int y){
	for (int i = 0; i < piece->size/piece->len; i++) {
		for (int j = 0; j < piece->len; j++) {
			if (i+y < 0 || i+y >= (grid->size/grid->len) || j+x < 0 || j+x >= grid->len) {
				return 1;
			}
			if (grid->data[((i+y)*grid->len)+j+x] && piece->data[(i*piece->len)+j]) {
				return 1;
			}
		}
	}
	return 0;
}

void test_checkCollision(int fill) {
	container grid;
	container piece;
	initContainer(10,10,&grid);
	if (fill) {
		for (int i = 0; i < grid.size; i++) {
			grid.data[i] = 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int p = 0; p < 6; p++) {
				piece = createPiece(p);
				if (piece.len > 10-j || piece.size/piece.len > 10-i) {
					break;
				}
				if (fill) {
					assert(checkCollision(&grid, &piece, j, i) == 1);
				}else{
					assert(checkCollision(&grid, &piece, j, i) == 0);
				}
			}
		}
	}
}

void test_Placement(void){
	container grid, piece;
	int nb_test, i, j;
	for(nb_test = 0; nb_test< 100; nb_test++){
		piece = randomPiece();
		//piece = createPiece(2); // POUR DEMO
		initContainer(piece.len, (piece.size / piece.len), &grid);
		place(&grid, &piece, 0, 0);
		//grid.data[0] = 5; // POUR DEMO
		for(i = 0; i < piece.size; i ++){
			if(grid.data[i] != piece.data[i]){
				printf("WRONG placement detected at test number %d, position %d, %d \n", nb_test, i, j);
			}
		}
	}
}

void place(container * grid, container * piece, int x, int y) {
	for (int i = 0; i < piece->size/piece->len; i++) {
		for (int j = 0; j < piece->len; j++) {
			if (piece->data[(i*piece->len)+j] != 0) {
				grid->data[((i+y)*grid->len)+j+x] = piece->data[(i*piece->len)+j];
			}
		}
	}
}

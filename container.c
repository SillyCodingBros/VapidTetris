#include "head.h"

void initContainer(int width, int height, container* item){
	item->len = width;
	item->size = width * height;
	item->data = malloc(item->size * sizeof(char));
	for (int i = 0; i < item->size; ++i)
	{
		item->data[i] = 0;
	}
}

container createPiece(int num_piece){
	container piece;
	char color = rand()%6+1;	

	if (num_piece == 0){
		initContainer(3, 3, &piece);
		piece.data[0] = color;
		piece.data[2] = color;
		piece.data[3] = color;
		piece.data[5] = color;
		piece.data[6] = color;
		piece.data[7] = color;
		piece.data[8] = color;
	}
	else if (num_piece == 1){
		initContainer(3, 2, &piece);
		piece.data[0] = color;
		piece.data[3] = color;
		piece.data[4] = color;
		piece.data[5] = color;
	}
	else if (num_piece == 2){
		initContainer(3, 2, &piece);
		piece.data[2] = color;
		piece.data[3] = color;
		piece.data[4] = color;
		piece.data[5] = color;
	}
	else if (num_piece == 3){
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
	else if (num_piece == 4){
		initContainer(1, 1, &piece);
		piece.data[0] = color;
		return piece;
	}
	else if (num_piece == 5){
		initContainer(1, 2, &piece);
		piece.data[0] = color;
		piece.data[1] = color;
	}
	return piece;
}

container randomPiece(){
	srand(time(NULL));
	int random = 6 * (rand() / (RAND_MAX + 1.0));
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

void place(container * grid, container * piece, int x, int y) {
	for (int i = 0; i < piece->size/piece->len; i++) {
		for (int j = 0; j < piece->len; j++) {
			if (piece->data[(i*piece->len)+j] != 0) {
				grid->data[((i+y)*grid->len)+j+x] = piece->data[(i*piece->len)+j];
			}
		}
	}
}

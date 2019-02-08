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

container randomPiece(){
	container piece;
	srand(time(NULL));
	int random = 6 * (rand() / (RAND_MAX + 1.0));
	switch (random){
		case 0 :
			piece = createU();
			return piece;
		case 1 :
			piece = createL1();
			return piece;
		case 2 :
			piece = createL2();
			return piece;
		case 3 :
			piece = createCross();
			return piece;
		case 4:
			piece = createDot();
			return piece;
		case 5 :
			piece = createLine();
			return piece;
		default :
			printf("Error : could not generate cooresponding piece for int : %d \n", random);
			exit(0);
	}
}

container createU(){
	char color;
	container piece;

	color = rand()%6+1;
	initContainer(3, 3, &piece);
	piece.data[0] = color;
	piece.data[2] = color;
	piece.data[3] = color;
	piece.data[5] = color;
	piece.data[6] = color;
	piece.data[7] = color;
	piece.data[8] = color;
	return piece;
}

container createL1(){
	container piece;

	char color = rand()%6+1;
	initContainer(3, 2, &piece);
	piece.data[0] = color;
	piece.data[3] = color;
	piece.data[4] = color;
	piece.data[5] = color;
	return piece;
}

container createL2(){
	container piece;

	char color = rand()%6+1;
	initContainer(3, 2, &piece);
	piece.data[2] = color;
	piece.data[3] = color;
	piece.data[4] = color;
	piece.data[5] = color;
	return piece;
}

container createCross(){
	container piece;

	char color = rand()%6+1;
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
	return piece;
}

container createDot(){
	container piece;

	char color = rand()%6+1;
	initContainer(1, 1, &piece);
	piece.data[0] = color;
	return piece;
}

container createLine(){
	container piece;

	char color = rand()%6+1;
	initContainer(1, 2, &piece);
	piece.data[0] = color;
	piece.data[1] = color;
	return piece;
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

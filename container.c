#include "head.h"

void initContainer(int width, int height, container* item){
	item.len = width;
	item.size = width * height;
	int data = malloc(item.size * sizeof(int));
}

container randomPiece(){
	container piece;
	srand(time(NULL));
	int random = rand() % 5;
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
	}
}

container createU(){
	container piece;
	initContainer(3, 3, piece);
	int data = {1, 0, 1,
			    1, 0, 1,
			    1, 1, 1 };
	piece.data = data
	return piece;
}

container createL1(){
	container piece;
	initContainer(3, 2, piece);
	int data = {1, 0, 0,
				1, 1, 1 };
	piece.data = data;
	return piece;
}

container createL2(){
	container piece;
	initContainer(3, 2, piece);
	int data = {0, 0, 1,
			    1, 1, 1 };
	piece.data = data;
	return piece;
}

container createCross(){
	container piece;
	initContainer(5, 5, piece);
	int data = {0, 0, 1, 0, 0,
				0, 0, 1, 0, 0,
				1, 1, 1, 1, 1, 
				0, 0, 1, 0, 0,
				0, 0, 1, 0, 0 }
	piece.data = data;
	return piece;
}

container createDot(){
	container piece;
	initContainer(1, 1, piece);
	int data = {1};
	piece.data = data
	return piece;
}

container createLine(){
	container piece;
	initContainer(1, 2, piece);
	int data = {1, 1};
	piece.data = data;
	return piece;
}

void deleteContainer(container * item){
	free(item.data);
}
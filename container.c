#include "head.h"

void initContainer(int width, int height, container* item){
	item.len = width;
	item.size = width * height;
}

void randomPiece(){
	srand(time(NULL));
	int random = rand() % 5;
	switch (random){
		case 0 :
			createU();
		case 1 :
			createL1();
		case 2 :
			createL2();
		case 3 :
			createCross();
		case 4:
			createDot();
		case 5 :
			createLine();
	}
}

void createU(){
	container piece;
	initContainer(3, 3, piece);
	int data = {1, 0, 1,
			    1, 0, 1,
			    1, 1, 1 };
	piece.data = data
}

void createL1(){
	container piece;
	initContainer(3, 2, piece);
	int data = {1, 0, 0,
				1, 1, 1 };
	piece.data = data;
}

void createL2(){
	container piece;
	initContainer(3, 2, piece);
	int data = {0, 0, 1,
			    1, 1, 1 };
	piece.data = data;
}

void createCross(){
	container piece;
	initContainer(5, 5, piece);
	int data = {0, 0, 1, 0, 0,
				0, 0, 1, 0, 0,
				1, 1, 1, 1, 1, 
				0, 0, 1, 0, 0,
				0, 0, 1, 0, 0 }
	piece.data = data;
}

void createDot(){
	container piece;
	initContainer(1, 1, piece);
	int data = {1};
	piece.data = data;
}

void createLine(){
	container piece;
	initContainer(1, 2, piece);
	int data = {1, 1};
	piece.data = data;
}

void deleteContainer(container * item){
	free(item);
}
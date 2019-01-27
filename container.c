#include "head.h"

void initContainer(int width, int height, container* item){
	container.len = width;
	container.size = width * height;
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
}
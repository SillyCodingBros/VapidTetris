#include "head.h"

int main(int argc, char const *argv[])
{
	container playGrid, piece;
	initContainer(WIDTH,HEIGHT,&playGrid);
	piece = randomPiece();
	while(1){
		display(&playGrid);
		display(&piece);
	}
	return 0;
}

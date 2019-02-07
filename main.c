#include "head.h"

int main(int argc, char const *argv[]){

	container playGrid, playPiece;
	int pieceX, pieceY;

	initContainer(WIDTH, HEIGHT, &playGrid);

	playPiece = randomPiece();

	int tmp = 1;

	while(tmp){

		display(&playPiece);
		display(&playGrid);

		printf("Enter 'x y' of top left corner: ");
		scanf("%d %d", &pieceX, &pieceY);
		if (checkCollision(&playGrid, &playPiece, pieceX, pieceY)) {
			printf("Can't fit here!\n");
		}else{
			place(&playGrid, &playPiece, pieceX, pieceY);
			playPiece = randomPiece();
		}
		update(&playGrid);
	}
	return 0;
}

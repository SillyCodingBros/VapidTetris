#include "head.h"

int main(int argc, char const *argv[]){

	container playGrid, playPiece;
	int pieceX, pieceY;

	initContainer(WIDTH,HEIGHT,&playGrid);

	playPiece = randomPiece();

	int tmp=1;

	while(tmp){

		display(&playPiece);
		display(&playGrid);

		printf("Enter x, y of top left corner ");
		scanf("%d %d", &pieceX,&pieceY);
		if (checkCollision(&playGrid,&playPiece,pieceX,pieceY)) {
			printf("invalid place !\n");
		}else{
			place(&playGrid,&playPiece,pieceX,pieceY);
			playPiece = randomPiece();
		}
		update(&playGrid);
		//printf("X and Y : %d %d\n", pieceX, pieceY);
		//tmp = 0;
	}
	return 0;
}

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
		place(&playGrid,&playPiece,pieceX,pieceY);
		update(&playGrid);
		playPiece = randomPiece();
		//printf("X and Y : %d %d\n", pieceX, pieceY);
		//tmp = 0;
	}
	return 0;
}

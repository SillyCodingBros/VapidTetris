#include "head.h"

int main(int argc, char const *argv[])
{
	container playGrid;
	initContainer(WIDTH,HEIGHT,&playGrid);
	while(1){
		display(&playGrid);
	}
	return 0;
}

#include "head.h"

int main(int argc, char const *argv[])
{
	container playGrid;
	initContainer(20,24,&playGrid);
	while(1){
		display(&playGrid);
	}
	return 0;
}

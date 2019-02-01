#ifndef HEAD_H
#include "head.h"
#endif
void rotate_360(container *piece)
{	
	//fait tourné la piece a 360
	int i,j;
	char*tmp=malloc(sizeof(char)*piece->width*piece->height);
	for(i=0;i<piece->width;i++)
		for(j=0;j<piece->height;j++)
			tmp[i*piece->width+j]=piece->data[i+piece->width*j];

	for(i=0;i<piece->width;i++)
		for(j=0;j<piece->height;j++)
			piece->data[i*piece->width+j]=tmp[i*piece->width+j];
		
	free(tmp);	
}

void rotate_180(container *piece)
{	
	int i,j;
	char * tmp=malloc(sizeof(char)*piece->width*piece->height);
	for(i=0;i<piece->width;i++)
		for(j=0;j<piece->height;j++)
			tmp[i*piece->width+j]=piece->data[i+piece->width*j];
	
	for(i=0;i<piece->width;i++)
		for(j=0;j<piece->height;j++)
			piece->data[i*piece->width+j]=tmp[i*piece->width+j];
	free(tmp);	
}

/*
container rotate(container piece,int L){
	switch(piece.type){
		case 1:
			
			break;
		case 2:
				deleteContainer(&piece);
				piece=createDiago();
				return piece;
		case 3:
				deleteContainer(&piece);
				piece=createLine();
				return piece;
		case 4:
				deleteContainer(&piece);
				piece=createL2();
				return piece	
		case 5:
				deleteContainer(&piece);
				piece=createL1();
				return piece;
		case 8:
				deleteContainer(&piece);
				piece=createU2();
				return piece;	
		case 9:
				deleteContainer(&piece);
				piece=createU3();
				return piece;
		case 10:
				deleteContainer(&piece);
				piece=createU4();
				return piece;
		case 11:
				deleteContainer(&piece);
				piece=createU();
				return piece;
	}
	}
*/


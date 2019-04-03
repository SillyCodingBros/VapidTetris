#include "head.h"

/**	
*	Paramètres : La grille de jeu
*	Fonction de test pour update pour verifier le bon fonctionnement de la gravité
*	Retour : Aucun
**/
void fillGrid(container* play_grid){

	int max_size = play_grid->size;
	int max_len = play_grid->len;
	int max_height = max_size/max_len;

	int holeX = max_len/2;
	int holeY = max_height/2;

	for(int k = 0; k < 10; ++k){

		printf("Adding block, %d time...\n", k);
		for(int j = -2; j < 3; ++j){
			for(int i = 0; i < max_len; ++i){
				play_grid->data[max_len*(holeY+j) + i] = 1;
			}
		}

		for(int j = -2; j < 3; ++j){
			for(int i = 0; i < max_height; ++i){
				play_grid->data[max_len*i + (holeX+j)] = 1;
			}
		}

		printf("Starting update...\n");
		update(play_grid);
	}

}

/**
*	Fonction qui s'occupe de detecter toutes les colonnes ou lignes pleines.
*	Retour : Pointeur sur le tableau contenant les index des lignes ou colonnes à supprimer.
**/

int* detect(container* grid, int step, int size){

	int *index, actual, i;

	//Index
	actual = 1;
	index = malloc((size/step + 1)*sizeof(int));

	for(i=0; i<size; i += step){
		if(step == 1){
			if(fullCol(grid, i)){
				index[actual] = i;
				++actual;
			}
		}
		else{
			if(fullRow(grid, i)){
				index[actual] = i;
				++actual;
			}
		}
	}
	index[0] = actual;

	return realloc(index, actual);
}

/**
*	Fonction remplacé par detect
**/

int* detectRow(container* grid){

	int *index, actual, max_len, max_size, i;

	//Sauvegarde
	max_len = grid->len;
	max_size = grid->size;

	//Index
	actual = 1;
	index = malloc((max_size/max_len + 1)*sizeof(int));

	for(i=0; i<max_size; i += max_len){
		if(fullRow(grid, i)){
			index[actual] = i;
			++actual;
		}
	}
	index[0] = actual;

	return realloc(index, actual);
}


/**
*	Fonction prenant l'index d'une ligne et qui verifie si elle est pleine.
*	Retour : 1 si ligne pleine, 0 si non.
**/

char fullRow(container* grid, int index){

	int max_len, j;
	char* save_data;

	save_data = grid->data;
	max_len = grid->len;

	for(j=index; j< index + max_len; ++j){
		if(save_data[j] == 0) break;
	}
	if(j == index + max_len){
		return 1;
	}
	return 0;
}


/**
*	fonction remplacé par delete
**/

void deleteRow(container* grid, int* index_list){

	int actual, max_len, max_size, i, j;
	char *save_data;

	//Sauvegarde
	save_data = grid->data;
	max_len = grid->len;

	max_size = index_list[0];
	for(i=1; i<max_size; ++i){
		actual = index_list[i];
		for(j=actual; j< actual + max_len; ++j){
			save_data[j] = 0;
		}
	}

}


/**
*	Fonction s'occupant d'effacer tout les elements contenue dans la liste d'index.
*	Retour : Aucun
**/

void delete(container* grid, int* index_list, int step, int lineSize){
	int actual, max_size, i, j, k;
	char *save_data;

	//Sauvegarde
	save_data = grid->data;

	max_size = index_list[0];
	for(i=1; i<max_size; ++i){
		actual = index_list[i];
		for(j=actual, k=0; k < lineSize; j += step, ++k){
			save_data[j] = 0;
		}
	}
}


/**
*	Fonction remplacé par detect
**/

int* detectCol(container* grid){

	int *index, actual, max_len, i;

	//save
	max_len = grid->len;

	//Index
	actual = 1;
	index = malloc((max_len+1)*sizeof(int));

	for(i=0; i<max_len; ++i){
		if(fullCol(grid, i)){
			index[actual] = i;
			++actual;
		}
	}

	index[0] = actual;

	return realloc(index, actual);
}


/**
*	Fonction prenant l'index d'une colonne et qui verifie si elle est pleine.
*	Retour : 1 si colonne pleine, 0 si non.
**/

char fullCol(container* grid, int index){

	int max_size, max_len, j;
	char* save_data;

	//save
	save_data = grid->data;
	max_size = grid->size;
	max_len = grid->len;

	for(j=index; j<max_size; j+=max_len){
		if(save_data[j] == 0) break;
	}
	if(j >= max_size){
		return 1;
	}
	return 0;
}


/**
*	Fonction remplacé par delete.
**/

void deleteCol(container* grid, int* index_list){

	int actual, max_len, max_size, max_size1, i, j;
	char *save_data;

	//Sauvegarde
	save_data = grid->data;
	max_len = grid->len;
	max_size1 = grid->size;

	max_size = index_list[0];

	for(i=1; i<max_size; ++i){
		actual = index_list[i];
		for(j=actual; j< max_size1; j += max_len){
			save_data[j] = 0;
		}
	}

}


/**
*	Fonction qui s'occupe de faire descendre les ligne et colonnes maintenant vide.
	Retour : Aucun.
**/

void gravity(container* grid, int* index_list_row, int* index_list_col){

	int max_len, max_size, save_size, save_index, i, j, k;
	char *save_data;

	//Save
	save_data = grid->data;
	max_size = grid->size;
	max_len = grid->len;

	//Update row
	save_size = index_list_row[0];
	for(i=1; i<save_size; ++i){
		for(j=index_list_row[i]-1; j>=0; --j){
			save_data[j+max_len] = save_data[j];
			save_data[j] = 0;
		}
	}

	//Update Col
	save_size = index_list_col[0];
	for(i=save_size-1; i>=1; --i){
		save_index = index_list_col[i];
		for(j=0; j<max_size; j += max_len){
			for(k=save_index + j + 1; k < max_len + j; ++k){
				save_data[k-1] = save_data[k];
				save_data[k] = 0;
			}
		}
	}

}


/** 
*	Fonction core de Upadate, prend en paramètres la grille de jeu et fait tout les appels concernant
*	la gravité dessus.
*	Retour : Aucun.
**/

void update(container *grid){
	int *index_list_row, *index_list_col;					//Les anciennes methodes ci-dessous :
	index_list_row = detect(grid, grid->len, grid->size);	//detectRow(grid);
	index_list_col = detect(grid, 1, grid->len);			//detectCol(grid);

	//Ancienne méthode
	/*deleteRow(grid, index_list_row);
	deleteCol(grid, index_list_col);*/
	delete(grid, index_list_row, 1, grid->len);
	delete(grid, index_list_col, grid->len, grid->size/grid->len);

	gravity(grid, index_list_row, index_list_col);

	free(index_list_row);
	free(index_list_col);
}

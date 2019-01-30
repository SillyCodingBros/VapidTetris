#include "head.h"

//Fonction row
int* detectRow(container* grid){

	int *index, actual, max_len, max_size, i;

	//Sauvegarde
	max_len = grid->len;
	max_size = grid->size;

	//Index
	actual = 1;
	index = malloc((max_size/max_len + 1)*sizeof(int));

	for(i=0; i<max_size; i += max_len){
		if(fullrow(grid, i)){
			index[actual] = i;
			++actual;
		}
	}
	index[0] = actual;

	return realloc(index, actual);
}

char fullRow(container* grid, int index){

	int max_len, j;
	char* save_data;

	save_data = grid->data;
	max_len = grid->len;

	for(j=index; j< index + max_len; ++j){
		if(save_data[j] != 1) break;
	}
	if(j == index + max_len){
		return 1;
	}
	return 0;
}

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



//Fonction Col
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

char fullCol(container* grid, int index){

	int max_size, max_len, j;
	char* save_data;

	//save
	save_data = grid->data;
	max_size = grid->size;
	max_len = grid->len;

	for(j=index; j<max_size; j+=max_len){
		if(save_data[j] != 1) break;
	}
	if(j >= max_size){
		return 1;
	}
	return 0;
}

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


void gravity(container* grid, int* index_list_row, int* index_list_col){

	int actual, max_len, max_size, save_size, save_index, i, j, k;
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


void update(container *grid){
	int *index_list_row, *index_list_col;
	index_list_row = detectRow(grid);
	index_list_col = detectCol(grid);

	deleteRow(grid, index_list_row);
	deleteCol(grid, index_list_col);

	gravity(grid, index_list_row, index_list_col);

	free(index_list_row);
	free(index_list_col);
}

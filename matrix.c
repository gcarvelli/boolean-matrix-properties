/*
Matrix Multiplication
*/
#include <stdio.h>
#include "matrix.h"

/*
Multiplies 2 square boolean matricies of the same size.
*/
int* multiply(int *matrix1, int *matrix2, int *product, int size){
	//iterate through each row
	int i;
	for(i=0; i<size; i++){
		//get matrix1's row
		int matrix1_row = matrix1[i];
		//iterate through each column
		int j;
		for(j=0; j<size; j++){
			//(i,j) is the (row,column) of the current value
			//must bitwise and each individual value in matrix1's row
			//	and matrix2's column

			//get matrix2's column
			int matrix2_column = 0;
			int k;
			for(int k=0; k<size; k++){
				int result = 0;
				if(matrix2[k] & (1<<(size-1-j))){
					result = 1;
				}
				matrix2_column = matrix2_column | (result << (size-1-k));
			}
			//printf("row %d: %d\n",i, matrix1_row);
			//printf("column %d: %d\n",j, matrix2_column);

			if(matrix1_row & matrix2_column){
				//the row crossed with the column isn't 0
				product[i] = product[i] | (1 << (size-1-j));
				//printf("current value for row %d: %d\n",i,product[i]);
				//printf("value for %d,%d: %d\n\n",i,j,1);
			}
			else{
				//printf("value for %d,%d: %d\n\n",i,j,0);
			}
		}
	}
}
/*
Prints out a square boolean matrix.
*/
void print_matrix(int *matrix, int size){
	//iterate through each row
	int i;
	for(i=0; i<size; i++){
		//iterate through each column
		int j;
		for(j=0; j<size; j++){
			if(matrix[i] & (1 << ((size-1)-j))){
				printf("%d ",1);
			}
			else{
				printf("%d ",0);
			}
		}
		printf("\n");
	}
}
/*
Takes two matricies of the same size and returns 1 if they are equivalent.
*/
int matrix_equal(int *matrix1, int *matrix2, int size){
	//iterate through each row
	int row;
	for(row=0; row<size; row++){
		//make sure each row is equal
		if(matrix1[row] != matrix2[row]){
			return 0;
		}
	}
	return 1;
}
/*
Returns 1 if the matrix is transitive. Uses the 
*/
int is_transitive(int *matrix, int size){
	//create the product matrix
	int product[size];
	//wipe whatever garbage is in there
	int i=0;
	for(i=0; i<size; i++){
		product[i] = 0;
	}
	//square the matrix and store it in the product matrix
	multiply(matrix, matrix, product, size);
	//make sure every 1 in the product is matched with a 1 in the matrix
	int test_matrix[size];
	for(i=0; i<size; i++){
		test_matrix[i] = matrix[i] | product[i];
	}
	//if the test matrix is the same as the original then it's transitive
	if(matrix_equal(matrix, test_matrix, size)){
		return 1;
	}
	return 0;
}

/*
Returns 1 if the provided matrix is reflexive.
*/
int is_reflexive(int *matrix, int size){
	//check the diagonal for all ones
	int row;
	for(row=0; row<size; row++){
		if(!(matrix[row] & (1 << (size-1-row)))){
			return 0;
		}
	}
	return 1;
}

/*
Returns 1 if the provided matrix is symmetric.
*/
int is_symmetric(int *matrix, int size){
	//iterate through each row
	int i;
	for(i=0; i<size; i++){
		//get the row
		int row = matrix[i];
		//iterate through each column
		int column = 0;
		int k;
		for(k=0; k<size; k++){
			int result = 0;
			if(matrix[k] & (1<<(size-1-i))){
				result = 1;
			}
			column = column | (result << (size-1-k));
		}
		if(!(row == column)){
			return 0;
		}
	}
	return 1;
}
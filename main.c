/*
main
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "matrix.h"

int main(){
	//SET THE SIZE OF THE MATRIX
	int size = 5; //change this variable
	printf("size: %d\n",size);

	//initialize some "global" variables to be used later on
	int possible_rows = pow(2, size);
	int possible_matricies = pow(2, pow(size,2));

	//for time measurement
	clock_t start, stop;
	double t = 0.0;
	start = clock();

	//initialize the first
	int matrix[size];
	int i;
	for(i=0; i<size; i++){
		matrix[i] = 0;
	}
	//initialize the counting variables
	int count = 0;
	int transitive = 0;
	int reflexive = 0;
	int symmetric = 0;

	//generate all possible matricies of the given size
	while(matrix[0] < possible_rows){
	//TRANSITIVITY
		transitive += is_transitive(matrix, size);

	//REFLEXIVITY
		reflexive += is_reflexive(matrix, size);

	//SYMMETRY
		symmetric += is_symmetric(matrix, size);

		count ++;

		//generate the next matrix
		matrix[size-1] += 1;
		//i>0 because the check should never happen on the last one
		//(the check on matrix[0] is handled by the while loop)
		for(i = size-1; i>0; i--){
			//if the number in the row has exceeded "size" bits,
			//set it to 0 and increment matrix[i-1];
			if(matrix[i] >= possible_rows){
				matrix[i] = 0;
				matrix[i-1] += 1;
			}
		}
		//print out a count once in a while for visual tracking
		if(!(count % 100000)){
			printf(".", count);
		}
	}
	//time calculation
	stop = clock();
	t = (double) (stop-start)/CLOCKS_PER_SEC;

	//print results
	printf("\nnumber of matricies: %d\n",count);
	printf("number of transitive relations: %d\n",transitive);
	printf("number of reflexive relations: %d\n",reflexive);
	printf("number of symmetric relations: %d\n",symmetric);
	printf("runtime: %f\n", t);

	return 0;
}
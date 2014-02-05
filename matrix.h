/*
matrix.h
*/


int is_transitive(int *matrix1, int size);
int is_reflexive(int *matrix1, int size);
int is_symmetric(int *matrix, int size);
int* multiply(int *matrix1, int *matrix2, int *product, int size);
void print_matrix(int *matrix, int size);
int matrix_equal(int *matrix1, int *matrix2, int size);

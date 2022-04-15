#include "miniRt.h"

void matrix_destroyer(t_matrices *matrix)
{
    int i;

    while(i < matrix->rows)
    {
        free(matrix->matrix[i]);
        i++;
    }
}

void free_matrix(t_matrices **matrix)
{//send in the address of the matrix pointer
    t_matrices *matrix_to_destroy;

    matrix_to_destroy = *matrix;
    matrix_destroyer(matrix_to_destroy);
    free(matrix_to_destroy);
}

void    null_matrix(t_matrices *matrix)
{
    int i;
    int j;

    i = 0;
    while(i < matrix->rows)
    {
        j = 0;
        while(j < matrix->cols)
        {
            matrix->matrix[i][j] = 0;
            j++;
        }
        i++;
    }
}

t_matrices *create_matrix(int rows, int cols)
{
    t_matrices *matrix;
    int i;
    
    matrix = malloc(sizeof(t_matrices));
    matrix->rows_num = rows;
    matrix->cols_num = cols;
    matrix->matrix = malloc(sizeof(float *) * rows)
    i = 0;
    while(i < rows)
        matrix->matrix[i] = malloc(sizeof(float) * cols);
    null_matrix(matrix);
    return matrix;
    //means matrix[rows][columns]
}

int fill_diagonal(t_matrices *matrix, float number)
{//only works on same dimension on row/collumns matrices
    int i;

    if(!matrix)
        return NULL;
    i = 0;
    while(i < matrix->rows)
        matrix->matrix[i][i] = number;
    return 1;    
}

t_matrices *identity_matrix(int dimension)
{
    t_matrices *matrix;

    matrix = create_matrix(dimension,dimension);
    fill_diagonal(matrix);
    return matrix;
}

t_matrices *multiply_matrices(t_matrices *matrix1, t_matrices *matrix2)
{
    t_matrices *final_matrix;
    int i;
    int j;

    final_matrix = create_matrix(matrix1->rows,matrix2->cols);
    //first matrix rows and second matrix cols are the dimension of the multiplied matrix
    i = 0;
    j = 0;
}

t_matrices *multiply_matrix_tuple(t_matrices *matrix, t_tuple tuple)
{

}

t_matrices *multiply_tuple_matrix(t_matrices *matrix, t_tuple tuple)
{
    
}

float   matrix_determinant()
{

}

t_matrices *transpose_matrix()
{

}

t_matrices *invert_matrix()
{

}

//matrix transformations


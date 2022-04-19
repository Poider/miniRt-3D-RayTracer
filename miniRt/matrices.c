#include "miniRt.h"

void matrix_destroyer(t_matrices *matrix)
{
    int i;

    while(i < matrix->rows_num)
    {
        free(matrix->matrix[i]);
        i++;
    }
}

void free_matrix(t_matrices *matrix)
{
    t_matrices *matrix_to_destroy;

    matrix_to_destroy = matrix;
    matrix_destroyer(matrix_to_destroy);
    free(matrix_to_destroy);
}

void    null_matrix(t_matrices *matrix)
{
    int i;
    int j;

    i = 0;
    while(i < matrix->rows_num)
    {
        j = 0;
        while(j < matrix->cols_num)
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
    while(i < matrix->rows_num)
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

static float element_multiplication(t_matrices *matrix1, t_matrices *matrix2, int row, int col)
{
    float sum;
    int i;

    sum = 0.0;
    i = 0;
    while (i < matrix2->rows)
    {
        sum += matrix1->matrix[row][i] * matrix2->matrix[i][col]
        i++;
    }
    return sum;
}

t_matrices *multiply_matrices(t_matrices *matrix1, t_matrices *matrix2)
{
    t_matrices *final_matrix;
    int current_row;
    int current_col;

    if(matrix1->rows != matrix2->cols)
        return NULL;
    final_matrix = create_matrix(matrix1->rows,matrix2->cols);
    //first matrix rows and second matrix cols are the dimension of the multiplied matrix
    current_row = 0;
    while(current_row < matrix1->rows)
    {
        current_col = matrix1->cols0;
        while(current_col < matrix2->cols)
        {
            final_matrix->matrix[current_row][current_col] = element_multiplication(matrix1,matrix2,current_row,current_col);
            current_col++;
        }
        current_row++;
    }
    //just while the rows you multiply first element from 1st row and 2nd col then again and add em to sum on each iteration
    return final_matrix;
}

t_tuple multiply_matrix_tuple(t_matrices *matrix, t_tuple tuple)
{//only works on 4x4 matrices as its supposed to be
    t_tuple multiplied_tuple;
    float **m;
    
    m = matrix->matrix;
    if(matrix->rows_num != 4)
        return NULL;
    multiplied_tuple.x = tuple.x * m[0][0] + tuple.y * m[0][1] + tuple.z * m[0][2] + tuple.w * m[0][3];
    multiplied_tuple.y = tuple.x * m[1][0] + tuple.y * m[1][1] + tuple.z * m[1][2] + tuple.w * m[1][3];
    multiplied_tuple.z = tuple.x * m[2][0] + tuple.y * m[2][1] + tuple.z * m[2][2] + tuple.w * m[2][3];
    multiplied_tuple.w = tuple.x * m[3][0] + tuple.y * m[3][1] + tuple.z * m[3][2] + tuple.w * m[3][3];
    return multiplied_tuple;
    //this multiplication wouldnt work the other way around
}

static float m2_determinant(t_matrices *matrix)
{
    float determinant;
    float **m;

    if(matrix->rows_num != 2)
        return 0;
    m = matrix->matrix;
    determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];//ad - bc
    free_matrix(matrix);
    return determinant;
}

t_matrices *get_submatrix(t_matrices *matrix, int current_row, int current_col)
{
    int subdimension;
    t_matrices *submatrix;
    int i;
    int j;

    i = 0;
    subdimension = matrix->rows - 1;
    if(subdimension <= 1)
        return matrix;
    submatrix = create_matrix(subdimension,subdimension)
    while(i < subdimension)
    {
        j = 0;
        while(j < subdimension)
        {
            submatrix->matrix[i][j] = matrix->matrix[i][j];
            j++;
            if(j == current_col)
                j++;
        }
        i++;
        if(i == current_row)
            i++;
    }
    return submatrix;
}

float get_minor(t_matrices *matrix)
{//determinant of submatrices
   //free submatrices before returning the determinant
    int dimension = matrix->rows_num;
    int i;
    float minor;
    float **m;

    m = matrix->matrix;
    if (matrix->rows_num == 2 && matrix->cols_num == 2)
        return m2_determinant(matrix);
    i = 0;
    while(i < matrix->cols_num)
    {
        minor+= m[0][i] * cofactor(get_minor(get_submatrix(matrix,0,i)),0,i);
        i++;
    }
    if(matrix->rows_num != 4)
        free_matrix(matrix);
    return minor;
}

float get_cofactor(float determinant, int current_row, int current_col)
{
    float cofactor;
    
    cofactor = determinant * pow(-1,current_col + current_row);
    return cofactor;
}


float determinant(t_matrices *matrix)
{
    // float det;
    // float **m;
    // int i;

    // i = 0;
    // det = 0;
    // m = matrix->matrix;
    // while(i < matrix->cols_num)
    // {
    //     det += m[0][i] * cofactor(get_minor(matrix, i, 0, i),0,i);
    //     i++;
    // }
    return(get_minor(matrix));
}



// float   matrix_determinant()
// {
//     if(matrix->rows_num == 2 && matrix->cols_num == 2)
//         return m2_determinant(matrix);
//     else if (matrix->rows_num = 3)
//     {

//     }
//     else if (matrix->rows_num = 4)
//     {

//     }
// }

t_matrices *transpose_matrix(t_matrices *matrix)
{
    t_matrices *transposed_matrix;
    int i;
    int j;

    i = 0;
    transposed_matrix = create_matrix(matrix->cols_num,matrix->rows_num);
    while(i < matrix->rows_num)
    {
        j = 0;
        while(j < matrix->cols_num)
        {
            transposed_matrix->matrix[j][i] = matrix->matrix[i][j];
            j++;
        }
        i++;
    }
    return transposed_matrix;
}

int is_invertible_matrix(t_matrices *matrix)
{
    float determinant;

    determinant = determinant(matrix);
    if(is_equal(determinant,0))
        return FALSE;
    return TRUE;
}


//change matrix to matrix->matrix!!!!!!!!!
t_matrices *cofactor_matrix(t_matrices *matrix)
{
    //determinant of sub matrix at that point * cofactor <- store it in the new matrix
    int i;
    int j;
    t_matrices final_matrix;

    final_matrix = create_matrix(matrix->rows_num,matrix->cols_num);
    i = 0;
    while(i < matrix->rows_num)
    {
        j = 0;
        while(j < matrix->cols_num)
        {
            final_matrix->matrix[i][j] = get_cofactor(determinant(get_submatrix(matrix,i,j)),i,j);
            j++;
        }
        i++;
    }
    return final_matrix;
}

void matrix_element_divide(t_matrices *matrix, float num)
{
    int i;
    int j;

    i = 0;
    while(i < matrix->rows_num)
    {
        j = 0;
        while(j < matrix->cols_num)
        {
            matrix->matrix[i][j] /= num;
            j++;
        }
        i++;
    }
}

t_matrices *invert_matrix(t_matrices *matrix)
{
    t_matrices *transposed;
    t_matrices *inverted;
    float determinant;

    if(!is_invertible_matrix(matrix))
        return NULL;
    determinant = determinant(matrix);
    inverted = cofactor_matrix(matrix);
    transposed = transposed_matrix(inverted);
    free_matrix(inverted);
    transposed = matrix_element_divide(matrix,determinant);
    return transposed;
}

//matrix transformations


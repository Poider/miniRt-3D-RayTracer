#include "./includes/miniRt.h"

void print_matrix(t_matrices matrix);
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
    matrix->matrix = malloc(sizeof(float *) * rows);
    i = 0;
    while(i < rows)
        matrix->matrix[i++] = malloc(sizeof(float) * cols);
    null_matrix(matrix);
    return matrix;
    //means matrix[rows][columns]
}

int fill_diagonal(t_matrices *matrix, float number)
{//only works on same dimension on row/collumns matrices
    int i;

    if(!matrix)
        return 0;
    i = 0;
    while(i < matrix->rows_num)
    {
        matrix->matrix[i][i] = number;
        i++;
    }
    return 1;    
}

t_matrices *identity_matrix(int dimension)
{
    t_matrices *matrix;

    matrix = create_matrix(dimension,dimension);
    fill_diagonal(matrix,1);
    return matrix;
}

static float element_multiplication(t_matrices *matrix1, t_matrices *matrix2, int row, int col)
{
    float sum;
    int i;

    sum = 0.0;
    i = 0;
    while (i < matrix2->rows_num)
    {
        sum += matrix1->matrix[row][i] * matrix2->matrix[i][col];
        i++;
    }
    return sum;
}

t_matrices *multiply_matrices(t_matrices *matrix1, t_matrices *matrix2)
{
    t_matrices *final_matrix;
    int current_row;
    int current_col;

    if(matrix1->rows_num != matrix2->cols_num)
        return NULL;
    final_matrix = create_matrix(matrix1->rows_num,matrix2->cols_num);
    //first matrix rows and second matrix cols are the dimension of the multiplied matrix
    current_row = 0;
    while(current_row < matrix1->rows_num)
    {
        current_col = 0;
        while(current_col < matrix2->cols_num)
        {
            final_matrix->matrix[current_row][current_col] = element_multiplication(matrix1,matrix2,current_row,current_col);
            current_col++;
        }
        current_row++;
    }
    //just while the rows you multiply first element from 1st row and 2nd col then again and add em to sum on each iteration
    return final_matrix;
}

t_tuple multiply_matrix_tuple(t_matrices matrix, t_tuple tuple)
{//only works on 4x4 matrices as its supposed to be
    t_tuple multiplied_tuple;
    float **m;

    m = matrix.matrix;
    if(matrix.rows_num != 4)
        return (multiplied_tuple);
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
{// you can split it by making a function that brings next element
    int subdimension;
    t_matrices *submatrix;
    int i;
    int j;
    int i1;
    int j1;

    i = 0;
    i1 = 0;
    subdimension = matrix->rows_num - 1;
    if(subdimension <= 1)
        return matrix;
    submatrix = create_matrix(subdimension,subdimension);
    while(i < subdimension)
    {
        j = 0;
        j1 = 0;
         if(i1 == current_row)
            {
                i1++;
                continue;
            }
        while(j < subdimension)
        {
            if(j1 == current_col)
                {
                    j1++;
                    continue;
                }
            submatrix->matrix[i][j] = matrix->matrix[i1][j1];
            j++;
            j1++;
            
        }
        i++;
        i1++;
       
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

    minor = 0;
    m = matrix->matrix;
    if (matrix->rows_num == 2 && matrix->cols_num == 2)
        return m2_determinant(matrix);
    i = 0;
    while(i < matrix->cols_num)
    {
        minor+= m[0][i] * get_cofactor(get_minor(get_submatrix(matrix,0,i)),0,i);
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
    float det;

    det = determinant(matrix);
    if(is_equal(det,0))
        return FALSE;
    return TRUE;
}


//change matrix to matrix->matrix!!!!!!!!!
t_matrices *cofactor_matrix(t_matrices *matrix)
{
    //determinant of sub matrix at that point * cofactor <- store it in the new matrix
    int i;
    int j;
    t_matrices *final_matrix;

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

t_matrices  *matrix_element_divide(t_matrices *matrix, float num)
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
    return (matrix);
}

t_matrices *invert_matrix(t_matrices *matrix)
{
    t_matrices *transposed;
    t_matrices *inverted;
    float det;

    // if(!is_invertible_matrix(matrix))
        // return NULL;
         
    det = determinant(matrix);
    if(is_equal(det,0))
        return NULL;
    inverted = cofactor_matrix(matrix);
    transposed = transpose_matrix(inverted);
    free_matrix(inverted);
    inverted = matrix_element_divide(transposed, det);
    return inverted;
}

// matrix transformations

// transformation*vector//transformation * identity
t_matrices *transform(void (*func)(void),t_matrices *sphere_matrix)
{//multiply tuples to transform them
    t_matrices *transformed;
    t_matrices *transformation;

    transformation = func();
        // multiply matrices here vv not matrix tuple
    transformed = multiply_matrices(transformation,sphere_matrix);// check the order of the multiplication
    free_matrix(sphere_matrix);
    free_matrix(transformation);
    return transformed;
}// works like : sphere.matrix = transform(transformation,sphere.matrix)

void print_matrix(t_matrices matrix)
{
    int i;
    int j;

    i = 0;
    while (i < matrix.rows_num)
    {
        j = 0;
        while (j < matrix.cols_num)
        {
            printf("%.3f  ",matrix.matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// int main()
// {
//     // t_tuple point = make_tuple(2,3,4,1);
//     // t_tuple vector = make_tuple(1,0,0,0);
//     // // t_tuple translated_tuple = make_tuple(2,3,4,1);
//     // t_ray ray = make_ray(point,vector);
//     // // t_matrices *m = scaling(translated_tuple);
//     // //t_ray r2 = transform_ray(ray,*m);
//     // t_tuple t1 = position(ray,2.5);
//     // printf("%.2f %.2f %.2f w = %.2f\n",t1.x,t1.y,t1.z,t1.w);

//     // printf("origin = %.2f %.2f %.2f w = %.2f\n",r2.origin.x,r2.origin.y,r2.origin.z,r2.origin.w);
//     // printf("direction = %.2f %.2f %.2f w = %.2f\n",r2.direction.x,r2.direction.y,r2.direction.z,r2.direction.w);
    
//     t_matrices *m;
//     m = create_matrix(4,4);
//     m ->matrix[0][0] = -5;m ->matrix[0][1] = 2;m ->matrix[0][2] = 6;m ->matrix[0][3] = -8;
//     m ->matrix[1][0] = 1;m ->matrix[1][1] = -5;m ->matrix[1][2] = 1;m ->matrix[1][3] = 8;
//     m ->matrix[2][0] = 7;m ->matrix[2][1] = 7;m ->matrix[2][2] = -6;m ->matrix[2][3] = -7;
//     m ->matrix[3][0] = 1;m ->matrix[3][1] = -3;m ->matrix[3][2] = 7;m ->matrix[3][3] = 4;

//     float matrix[4][4] = {
//         {-5,2,6,-8},
//         {1,-5,1,8},
//         {7,7,-6,-7},
//         {1,-3,7,4}
//     };
//     print_matrix(*m);
//     printf("\nafter : \n");
//     t_matrices *invers = invert_matrix(m);
//     t_matrices *ss = multiply_matrices(invers, m);
//     print_matrix(*ss);
//     return (0);
// }

int main()
{
    t_matrices *m;
    m = create_matrix(3,3);
    m ->matrix[0][0] = 1;m ->matrix[0][1] = 2;m ->matrix[0][2] = 3;
    m ->matrix[1][0] = 4;m ->matrix[1][1] = 5;m ->matrix[1][2] = 6;
    m ->matrix[2][0] = 7;m ->matrix[2][1] = 8;m ->matrix[2][2] = 10;
    print_matrix(*m);
    t_matrices *c = invert_matrix(m);
    // if(c == NULL) {printf("yes"); return 0;}
    printf("after:\n");
    print_matrix(*c);
    //its normal for it to segfault on matrices under 3, either cus det is null and its non invertible or cus its freed on calculating determinant then tried to get cofactor matrix with the freed on
    // printf("%d",c->cols_num);
    
}


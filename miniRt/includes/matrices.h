#include "miniRt.h"

# define DEFAULT_DIMENSION 4

typedef struct  s_matrices{

    int rows_num;
    int cols_num;
    float **matrix;
}               t_matrices;

t_matrices *identity_matrix(int dimension);
t_tuple multiply_matrix_tuple(t_matrices matrix, t_tuple tuple);
t_matrices *create_matrix(int rows, int cols);
t_matrices *translation(t_tuple tuple);
t_matrices *scaling(t_tuple tuple);
t_matrices *invert_matrix(t_matrices *matrix);
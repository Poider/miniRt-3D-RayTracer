#include "miniRt.h"

typedef struct  s_matrices{

    int rows_num;
    int cols_num;
    float **matrix;
}               t_matrices;

t_matrices *identity_matrix(int dimension);
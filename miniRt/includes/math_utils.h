#include "miniRt.h"

typedef struct  s_equations_vars{
    float a;
    float b;
    float c;

    float determinant;
    float sol1; //solutions
    float sol2;
}               t_equations_vars;

float abs(float x);
float is_equal(float a, float b);
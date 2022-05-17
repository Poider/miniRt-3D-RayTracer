#include "miniRt.h"

# define MAX_INT 2147483647
typedef struct  s_equations_vars{
    float a;
    float b;
    float c;

    float determinant;
    float sol1; //solutions
    float sol2;
}               t_equations_vars;

//float abs(float x);
int is_equal(float a, float b);
int is_pos(int a);
int is_greater(float a, float b);
int is_lesser(float a, float b);
float min(float a,float b);
float max(float a,float b);
float negate_val(float a);

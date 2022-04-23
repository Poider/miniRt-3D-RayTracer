#include "miniRt.h"

typedef struct  s_tuple{
    float x;
    float y;
    float z;
    float w;
}               t_tuple;

t_tuple make_tuple(float x,float y,float z,float w);
t_tuple add_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple substract_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple negate_tuple(t_tuple tuple1);//to find opposite vector
t_tuple tuple_scalar_multiplication(t_tuple tuple1, float scalar);//to make vector big by number of times
t_tuple tuple_scalar_division(t_tuple tuple1, float scalar);//to make vector big by number of times
float tuple_magnitude(t_tuple tuple);//to make vector big by number of times
int tuple_isequal(t_tuple tuple1, t_tuple tuple2);
t_tuple tuple_normalize(t_tuple tuple);
float dot_product(t_tuple tuple1,t_tuple tuple2);
t_tuple cross_product(t_tuple tuple1,t_tuple tuple2);

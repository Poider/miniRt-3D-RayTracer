#include "./includes/miniRt.h"

t_tuple make_tuple(float x,float y,float z,float w)
{
    t_tuple tuple;

    tuple.x = x;
    tuple.y = y;
    tuple.z = z;
    tuple.w = w;
    return tuple;
}

t_tuple add_tuple(t_tuple tuple1, t_tuple tuple2)
{//change to handle pointers if Im to work on them as ptrs
    t_tuple added_tuples;
    added_tuples.x = tuple1.x+tuple2.x;
    added_tuples.y = tuple1.y+tuple2.y;
    added_tuples.z = tuple1.z+tuple2.z;
    added_tuples.w = tuple1.w+tuple2.w;
    return added_tuples;
}

t_tuple substract_tuple(t_tuple tuple1, t_tuple tuple2)
{//change to handle pointers if Im to work on them as ptrs
    t_tuple added_tuples;
    added_tuples.x = tuple1.x - tuple2.x;
    added_tuples.y = tuple1.y - tuple2.y;
    added_tuples.z = tuple1.z - tuple2.z;
    added_tuples.w = tuple1.w - tuple2.w;
    return added_tuples;
}

t_tuple negate_tuple(t_tuple tuple1)//to find opposite vector
{
    if (!is_equal(tuple1.x,0.0))
        tuple1.x = -tuple1.x;
    if (!is_equal(tuple1.y,0.0))
        tuple1.y = -tuple1.y;
    if (!is_equal(tuple1.z,0.0))
        tuple1.z = -tuple1.z;
    return tuple1;
}

t_tuple tuple_scalar_multiplication(t_tuple tuple1, float scalar)//to make vector big by number of times
{   
    t_tuple scaled_vector;

	scaled_vector = tuple1;
    scaled_vector.x = tuple1.x * scalar;
    scaled_vector.y = tuple1.y * scalar;
   	scaled_vector.z = tuple1.z * scalar;
    scaled_vector.w = tuple1.w * scalar;
    return scaled_vector;
}

t_tuple tuple_scalar_division(t_tuple tuple1, float scalar)//to make vector big by number of times
{   
    t_tuple scaled_vector;

    tuple1.x = tuple1.x / scalar;
    tuple1.y = tuple1.y / scalar;
    tuple1.z = tuple1.z / scalar;
    tuple1.w = tuple1.w / scalar;
    scaled_vector = tuple1;
    return scaled_vector;
}

float tuple_magnitude(t_tuple tuple)//to make vector big by number of times
{//tuple distance// a vector as usual
    float magnitude;

    magnitude = sqrt(tuple.x * tuple.x + tuple.y * tuple.y + tuple.z * tuple.z + tuple.w * tuple.w);
    return magnitude;
}

int tuple_isequal(t_tuple tuple1, t_tuple tuple2)
{
    if(!is_equal(tuple1.x,tuple2.x))
      return FALSE;
    if(!is_equal(tuple1.y,tuple2.y))
      return FALSE;
    if(!is_equal(tuple1.z,tuple2.z))
      return FALSE;
    if(!is_equal(tuple1.w,tuple2.w))
      return FALSE;
    return TRUE;
}

t_tuple tuple_normalize(t_tuple tuple)
{//converting vectors into unit vectors
    float magnitude; 
    t_tuple normalized_vector;

    magnitude = tuple_magnitude(tuple);
    normalized_vector.x = tuple.x / magnitude;
    normalized_vector.y = tuple.y / magnitude;
    normalized_vector.z = tuple.z / magnitude;
    normalized_vector.w = tuple.w / magnitude;
    return normalized_vector;
}

float dot_product(t_tuple tuple1,t_tuple tuple2)
{
    float product;

    product = tuple1.x * tuple2.x + tuple1.y * tuple2.y + \
                tuple1.z * tuple2.z + tuple1.w * tuple2.w;
    return product;
}

t_tuple cross_product(t_tuple tuple1,t_tuple tuple2)
{//order matters, its using matrices//for cross vector
    t_tuple product;

    product.x = tuple1.y*tuple2.z - tuple1.z * tuple2.y;
    product.y = tuple1.z*tuple2.x - tuple1.x * tuple2.z;
    product.z = tuple1.x*tuple2.y - tuple1.y * tuple2.x;
    product.w = tuple1.w;
    return product;
    //returns whatever vector thats 90degrees with both
}

/*
(0,1,0), (1,0,0)

|b|.(-b.x, 0, b.z);
|b.x*(-b.x) + b.y * 0 + b.z * b.z|
|b.x * b.x + b.z * b.z|

*/









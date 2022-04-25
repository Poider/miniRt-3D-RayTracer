#include "miniRt.h"

typedef struct  s_ray{
    t_tuple origin;
    t_tuple direction;
	//t_intersections *intersections;
}               t_ray;
// u can simply copy structs into each other a = b;

t_ray make_ray(t_tuple origin,t_tuple direction);
t_tuple position(t_ray ray, float distance);
t_ray transform_ray(t_ray ray, t_matrices matrix);

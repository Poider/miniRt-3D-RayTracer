#include "miniRt.h"

typedef struct  s_ray{
    t_tuple origin;
    t_tuple direction;
}               t_ray;

t_ray make_ray(t_tuple origin,t_tuple direction);
t_ray transform_ray(t_ray ray, t_matrices matrix);
t_tuple position(t_ray ray, float t);
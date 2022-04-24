#include "./includes/miniRt.h"

t_ray make_ray(t_tuple origin,t_tuple direction)
{
    t_ray ray;

    ray.origin = origin;
    ray.direction = direction;
    return (ray);
}

t_tuple position(t_ray ray, float t)
{
    return (add_tuple(ray.origin,tuple_scalar_multiplication(ray.direction,t)));
}



t_ray transform_ray(t_ray ray, t_matrices matrix)
{
    t_ray transformed_ray;

    transformed_ray.origin = multiply_matrix_tuple(matrix,ray.origin);
    transformed_ray.direction = multiply_matrix_tuple(matrix,ray.direction);
    return (transformed_ray);
}



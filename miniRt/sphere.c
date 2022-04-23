#include "./includes/miniRt.h"

t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param)
{
    t_sphere *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->origin = origin; //(0,0,0) usually (use make_tuple function to send a tuple in)
    sphere->radius = radius
    param->object_id++;
    sphere->object_id = param->object_id;
    sphere->transformation = identity_matrix(4);
    return sphere;
}

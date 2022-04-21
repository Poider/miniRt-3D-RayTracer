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

t_intersections *ray_sphere_intersect(t_ray ray, t_sphere *sphere)
{
    t_equations_vars vars;

    vars.a = dot_product(ray.direction, ray.direction);
    vars.b = 2 * dot_product(ray.direction, substract_tuple(ray.origin, sphere->origin));
    vars.c = dot_product(substract_tuple(ray.origin, sphere->origin), substract_tuple(ray.origin, sphere->origin)) - pow(sphere->radius,2);
   
    vars.determinant = (b * b) - (4.0 * a * c);
    if (vars.determinant < 0)
		return NULL; //means no solutions
	else
	{
		vars.sol1 = ((-1.0 * b) - sqrt(vars.determinant)) / (2.0 * a);
		vars.sol2 = ((-1.0 * b) + sqrt(vars.determinant)) / (2.0 * a);
	}
}
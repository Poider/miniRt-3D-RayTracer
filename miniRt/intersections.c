#include "./includes/miniRt.h"

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

float get_hit(t_ray *ray)
{//the hit is the distance away from that exact ray

/*
	find min	ray->intersections with the lowest non negative result
	return that intersection// it includes the id of that one
*/
}

//sort_intersections(t_ray *ray)


#include "./includes/miniRt.h"

t_plane	*plane()
{
    t_plane *plane;

    plane = malloc(sizeof(t_plane));
    plane->transformation = identity_matrix(DEFAULT_DIMENSION);
	plane->material = make_material();
    return (plane);
}

t_tuple	normal_at_plane(t_object *plane,t_tuple world_point)
{
	return (make_tuple(0,1,0,VECTOR));
}

t_intersections	*intersect_plane(t_object *plane,t_ray ray)
{
	float	t;

	if(abs_float(ray.direction.y) <= EPSILON)
		return (NULL);
	t = (-ray.origin.y) / ray.direction.y;
	return (intersection(t, plane));
}
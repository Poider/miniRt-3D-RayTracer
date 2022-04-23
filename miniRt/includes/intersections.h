#include "miniRt.h"

typedef struct  s_intersections{
	float	t1;
	float	t2;
	int		id;
}               t_intersections;

t_intersections *ray_sphere_intersect(t_ray ray, t_sphere *sphere);
float get_hit(t_ray *ray);
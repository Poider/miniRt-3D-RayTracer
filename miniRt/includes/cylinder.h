#include "miniRt.h"

typedef struct  s_cylinder {

    t_tuple		origin;
    float		radius;
	float		min;
	float		max;
	int			closed;
    t_matrices *transformation;
	t_matrices *inverse_transformation;
    t_material	material;
}               t_cylinder;


t_cylinder 		*cylinder();
t_tuple			normal_at_cylinder(t_object *shape,t_tuple world_point);
t_intersections	*intersect_cylinder(t_object *cylinder,t_ray ray);
int				cylinder_check_cap(t_ray ray, float t);
void			cylinder_intersect_caps(t_object *cylinder_object, t_ray ray, t_intersections **l_intersections);
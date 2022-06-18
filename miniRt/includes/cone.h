#include "miniRt.h"

typedef struct  s_cone {

    t_tuple		origin;
    float		radius;
	float		min;
	float		max;
	int			closed;
    t_matrices *transformation;
	t_matrices *inverse_transformation;
    t_material	material;
}               t_cone;


t_cone 			*cone();
t_tuple			normal_at_cone(t_object *shape,t_tuple world_point);
t_intersections	*intersect_cone(t_object *cone,t_ray ray);
int				cone_check_cap(t_ray ray, float t);
void			cone_intersect_caps(t_object *cone_object, t_ray ray, t_intersections **l_intersections);
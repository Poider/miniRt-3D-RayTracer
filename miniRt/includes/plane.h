#include "miniRt.h"

typedef struct  s_plane 
{
    t_matrices *transformation;
	t_matrices *inverse_transformation;
    t_material material;
}               t_plane;


t_plane 		*plane();
t_tuple			normal_at_plane(t_object *plane, t_tuple world_point);
t_intersections	*intersect_plane(t_object *plane, t_ray ray);


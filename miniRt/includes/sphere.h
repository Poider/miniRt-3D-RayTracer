#include "miniRt.h"

typedef struct  s_sphere {

    t_tuple origin;
    float radius;
    int object_id;
    t_matrices *transformation;
	t_matrices *inverse_transformation;
    t_material material;
}               t_sphere;


t_sphere 		*sphere();
//t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param);
void 			draw_sphere(t_tuple camera, float z_image_plane);
t_tuple			normal_at_sphere(t_object *sphere,t_tuple world_point);
t_intersections	*intersect_sphere(t_object *sphere,t_ray ray);


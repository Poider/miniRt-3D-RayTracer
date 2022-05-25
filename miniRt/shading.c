#include "./includes/miniRt.h"

//what if that shadowed point is lighted by another point
int is_shadowed(t_world *world, t_tuple point)
{
    t_tuple light_pos;
    t_ray   shadow_ray;
    t_intersections *shadow_intersect = NULL;
    t_intersections *hit_intersection = NULL;
    float magnitude;

    light_pos = world->light.position;
    shadow_ray.direction = substract_tuple(light_pos,point);
    shadow_ray.origin = point;
    magnitude = tuple_magnitude(shadow_ray.direction);
	shadow_ray.direction = tuple_normalize(shadow_ray.direction);
    shadow_intersect = intersect_word(*world,shadow_ray);
    hit_intersection = hit(shadow_intersect);
    if(hit_intersection)
    {
        if(hit_intersection->t < magnitude)
            return TRUE;
    }
    return FALSE;
}
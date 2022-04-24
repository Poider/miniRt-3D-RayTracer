#include "miniRt.h"

// typedef struct  s_intersections
// {
// 	float	t1;
// 	float	t2;
// 	int		id;
// }               t_intersections;

t_intersections *ray_sphere_intersect(t_ray ray, t_sphere *sphere);
float get_hit(t_ray *ray);
t_intersections *intersection(float t, void *obj);
t_intersections *intersect(t_ray ray, t_sphere *sphere);
t_intersections *hit(t_intersections *l_intersections);//list intersections
void print_solution(t_intersections *head);


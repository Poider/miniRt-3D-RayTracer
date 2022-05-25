#include "miniRt.h"


typedef struct  s_intersections{
    float	t;
    t_object	*object;
    struct s_intersections *next;
}               t_intersections;

float 			get_hit(t_ray *ray);
t_intersections *intersection(float t, t_object *shape);
t_intersections *hit(t_intersections *l_intersections);//list intersections
void 			print_solution(t_intersections *head);
t_intersections	*get_last_intersection(t_intersections *intersections);
void			add_intersection(t_intersections **intersections, t_intersections *new_intersection);
t_intersections	*get_new_intetsection(float t, t_object *shape);
int				get_size_intersections(t_intersections *intersections);
t_intersections *intersect_word(t_world world, t_ray ray);
void			sort_intersectios(t_intersections *list_intersections);
void 			free_list_intersection(t_intersections *list_intersections);
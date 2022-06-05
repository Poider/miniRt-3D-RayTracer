#include "miniRt.h"

typedef struct  s_light
{
    t_tuple			intensity;
    t_tuple			position;
	struct s_light	*next;
}           t_light;

typedef struct  s_world 
{

	t_light		*light;
	t_object	*objects;
}               t_world;

typedef struct  s_precomputed t_precomputed;


t_light	*make_light(t_tuple position, t_tuple intensity);
void	add_light(t_light **lights, t_object *new_light);
t_light	*get_last_light(t_light *objects);
t_tuple	reflect(t_tuple in, t_tuple normal);
t_tuple	reflected_color(t_world world, t_precomputed comps, int max_depth);
t_tuple	shade_hit(t_world world, t_precomputed comps, int max_depth);
t_tuple lighting(t_world world, t_precomputed comps, int is_shadow);

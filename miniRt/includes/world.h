#include "miniRt.h"

// typedef struct  s_world 
// {

// 	t_light		light;
// 	t_object	*objects;
// }               t_world;

t_world create_world();
t_world default_world();//just for test
t_tuple color_at(t_world world, t_ray ray, int max_depth);
void	draw_world(t_tuple camera, float z_image_plane);
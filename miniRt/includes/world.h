#include "miniRt.h"

typedef struct  s_world 
{

	t_light		*light;
	t_object	*objects;
}               t_world;

t_world create_world();
t_world default_world();//just for test
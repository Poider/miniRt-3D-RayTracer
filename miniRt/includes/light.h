#include "miniRt.h"

typedef struct  s_light
{
    t_tuple intensity;
    t_tuple position;
}           t_light;

typedef struct  s_world 
{

	t_light		light;
	t_object	*objects;
}               t_world;


typedef struct	s_precomputed
{
	float		t;
	t_object	*object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			is_inside;
	t_material 	material;
}				t_precomputed;


t_light make_light(t_tuple position, t_tuple intensity);
t_tuple  reflect(t_tuple in, t_tuple normal);
t_tuple  lighting(t_world world, t_precomputed comps);
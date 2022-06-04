#include "miniRt.h"

typedef struct s_pattern t_pattern;

typedef struct s_material
{
  t_tuple	color;
  float		ambient;
  float		diffuse;
  float		specular;
  float		shininess;
  float		reflective;
  float		transparency;
  float		refractive_index;
  t_pattern	*pattern;
}              t_material;

t_material	make_material();
void		set_material_pattern(t_material *material,t_pattern *pattern);

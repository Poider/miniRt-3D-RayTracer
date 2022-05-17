#include "miniRt.h"


typedef struct s_material
{
  t_tuple color;
  float  ambient;
  float  diffuse;
  float  specular;
  float  shininess;
}              t_material;

t_material make_material();

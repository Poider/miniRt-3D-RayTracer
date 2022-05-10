#include "miniRt.h"

typedef struct  s_light
{
    t_tuple intensity;
    t_tuple position;
}           t_light;

t_light make_light(t_tuple position, t_tuple intensity);
t_tuple  reflect(t_tuple in, t_tuple normal);
t_tuple  lighting(t_material material, t_light light, t_tuple point, t_tuple eyev,t_tuple normalv);

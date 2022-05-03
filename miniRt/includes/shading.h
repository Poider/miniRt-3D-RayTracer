#include "miniRt.h"


t_tuple  reflect(t_tuple in, t_tuple normal);
t_tuple  lighting(t_material material, t_light light, t_tuple point, t_tuple eyev,t_tuple normalv);

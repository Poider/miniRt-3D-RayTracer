#include "miniRt.h"

typedef struct  s_light
{
    t_tuple intensity;
    t_tuple position;
}           t_light;

t_light make_light(t_tuple position, t_tuple intensity);
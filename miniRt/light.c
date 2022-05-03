#include "includes/miniRt.h"

t_light make_light(t_tuple position, t_tuple intensity)
{
    t_light point_light;

    point_light.position = position;
    point_light.intensity = intensity;
    return (point_light);
}
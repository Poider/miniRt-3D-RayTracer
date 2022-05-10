#include "includes/miniRt.h"

t_material make_material()
{
    t_material material;

    material.color = make_color(1, 1, 1);
    material.ambient = 0.2;
    material.diffuse = 0.9;
    material.specular = 0.9;
    material.shininess = 200.00;
    return (material);
}


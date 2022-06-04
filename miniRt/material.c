#include "includes/miniRt.h"

t_material make_material()
{
    t_material material;

    material.color = make_color(1, 1, 1);
    material.ambient = 0.1;
    material.diffuse = 0.9;
    material.specular = 0.9;
    material.shininess = 200.00;
	material.reflective = 0.0;
	material.transparency = 0.0;
	material.refractive_index = 1.0;
	material.pattern = NULL;
    return (material);
}

void set_material_pattern(t_material *material,t_pattern *pattern)
{
	material ->pattern = pattern;
}
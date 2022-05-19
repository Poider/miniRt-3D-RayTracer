#include "miniRt.h"

// typedef struct	s_precomputed
// {
// 	float		t;
// 	t_object	*object;
// 	t_tuple		point;
// 	t_tuple		eyev;
// 	t_tuple		normalv;
// 	int			is_inside;
// 	t_material 	material;
// }				t_precomputed;

t_precomputed	prepare_computations(t_intersections *intersection, t_ray ray);
t_material		get_material_object(t_object shape);

#include "./includes/miniRt.h"


t_precomputed prepare_computations(t_intersections *intersection, t_ray ray)
{
	t_precomputed pre_computed;

	pre_computed.t = intersection ->t;
	pre_computed.point = ray_position(ray,pre_computed.t);
	pre_computed.object = intersection ->object;
	pre_computed.eyev = negate_tuple(ray.direction);
	pre_computed.normalv = normal_at(pre_computed.object,pre_computed.point);
	if (dot_product(pre_computed.normalv,pre_computed.eyev) < 0)
	{
		pre_computed.is_inside = TRUE;
		pre_computed.normalv = negate_tuple(pre_computed.normalv);
	}
	else
		pre_computed.is_inside = FALSE;
	return (pre_computed);
}
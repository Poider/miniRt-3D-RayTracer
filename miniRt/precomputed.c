#include "./includes/miniRt.h"


t_material get_material_object(t_object shape)
{
	if (shape.type_object ==  SPHERE)
	{
		t_sphere *sphere = shape.object;
		return (sphere->material);
	}
	else
		return (make_material());//i will update this just for now

}

t_precomputed prepare_computations(t_intersections *intersection, t_ray ray)
{
	t_precomputed pre_computed;

	pre_computed.t = intersection ->t;
	pre_computed.point = ray_position(ray,pre_computed.t);
	pre_computed.object = intersection ->object;
	pre_computed.eyev = negate_tuple(ray.direction);
	pre_computed.normalv = normal_at(pre_computed.object->object,pre_computed.point);
	if (dot_product(pre_computed.normalv,pre_computed.eyev) < 0)
	{
		pre_computed.is_inside = TRUE;
		pre_computed.normalv = negate_tuple(pre_computed.normalv);
	}
	else
		pre_computed.is_inside = FALSE;
	pre_computed.material = get_material_object(*intersection->object);
	pre_computed.over_point = add_tuple(pre_computed.point, tuple_scalar_multiplication(pre_computed.normalv, EPSILON));
	// printf("%f %f %f / over %f %f %f\n",pre_computed.point.x,pre_computed.point.y,pre_computed.point.z,pre_computed.over_point.x,pre_computed.over_point.y,pre_computed.over_point.z);
	return (pre_computed);
}
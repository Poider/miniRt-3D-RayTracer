#include "./includes/miniRt.h"

t_tuple position(t_ray ray, float distance)
{
	t_tuple point;
	
	ray.direction = tuple_scalar_multiplication(ray.direction, distance);
	point = make_tuple(ray.direction.x + ray.origin.x, ray.direction.y + ray.origin.y,\
			ray.direction.z +ray.origin.z,ray.direction.w + ray.origin.w);
	return point;
	//returns what point lays after certain distance of that ray
}

//transform_ray(ray, object_transofrm_matrix)
//>>will transform the ray with inverse of that matrix(returns a new ray)

//change interesct function to transform ray b4 interesct

//create ray

//destroy ray (it destroys also the intersections if they exist)
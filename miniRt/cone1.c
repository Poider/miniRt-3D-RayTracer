/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:22:36 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/26 14:17:07 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	cone_check_cap(t_ray ray, float t, float y)
{
	t_tuple	pos_intersection;

	pos_intersection = ray_position(ray, t);
	return (pow(pos_intersection.x, 2) + pow(pos_intersection.z, 2) <= y * y);
}

void	cone_intersect_caps(t_object *cone_object, \
			t_ray ray, t_intersections **l_intersections)
{
	float	t;
	t_cone	*cone;

	cone = cone_object->object;
	if (cone->closed == 0 || \
			is_equal(ray.direction.y, EPSILON))
		return ;
	t = (cone->min - ray.origin.y) / ray.direction.y;
	if (cone_check_cap(ray, t, cone->min))
		add_intersection(l_intersections, intersection(t, cone_object));
	t = (cone->max - ray.origin.y) / ray.direction.y;
	if (cone_check_cap(ray, t, cone->max))
		add_intersection(l_intersections, intersection(t, cone_object));
}

t_tuple	normal_at_cone(t_object *shape, t_tuple world_point)
{
	t_cone	*cone;
	t_tuple	object_normal;
	float	dist;
	float	y;

	cone = (t_cone *)shape->object;
	dist = pow(world_point.x, 2) + pow(world_point.z, 2);
	if (dist < pow(cone->max, 2) && world_point.y >= cone->max - EPSILON)
		object_normal = make_tuple(0, 1, 0, VECTOR);
	else if (dist < pow(cone->min, 2) && world_point.y <= cone->min + EPSILON)
		object_normal = make_tuple(0, -1, 0, VECTOR);
	else
	{
		y = sqrt(dist);
		if (world_point.y > 0)
			y = -y;
		object_normal = make_tuple(world_point.x, y, world_point.z, VECTOR);
	}
	return (object_normal);
}

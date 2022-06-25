/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:24:44 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:30:09 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	cylinder_check_cap(t_ray ray, float t)
{
	t_tuple	pos_intersection;

	pos_intersection = ray_position(ray, t);
	return (pow(pos_intersection.x, 2) + pow(pos_intersection.z, 2) <= 1);
}

void	cylinder_intersect_caps(t_object *cylinder_object, \
					t_ray ray, t_intersections **l_intersections)
{
	float		t;
	t_cylinder	*cylinder;

	cylinder = cylinder_object->object;
	if (cylinder->closed == 0 || is_equal(ray.direction.y, EPSILON))
		return ;
	t = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (cylinder_check_cap(ray, t))
		add_intersection(l_intersections, intersection(t, cylinder_object));
	t = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (cylinder_check_cap(ray, t))
		add_intersection(l_intersections, intersection(t, cylinder_object));
}

t_tuple	normal_at_cylinder(t_object *shape, t_tuple world_point)
{
	t_cylinder	*cylinder;
	t_tuple		object_normal;
	float		dist;

	cylinder = (t_cylinder *)shape->object;
	dist = pow(world_point.x, 2) + pow(world_point.z, 2);
	if (dist < 1 && world_point.y >= cylinder->max - EPSILON)
		object_normal = make_tuple(0, 1, 0, VECTOR);
	else if (dist < 1 && world_point.y <= cylinder->min + EPSILON)
		object_normal = make_tuple(0, -1, 0, VECTOR);
	else
		object_normal = make_tuple(world_point.x, 0, world_point.z, VECTOR);
	return (object_normal);
}

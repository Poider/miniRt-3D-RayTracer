/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init_shapes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:49:04 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:57:33 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	init_sphere_attr(t_object *shape, \
		t_matrices **transform, t_material *material)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)shape->object;
	*transform = sphere->transformation;
	*material = sphere->material;
	shape->local_normal_at = normal_at_sphere;
	shape->local_intersect = intersect_sphere;
}

void	init_plane_attr(t_object *shape, \
		t_matrices **transform, t_material *material)
{
	t_plane	*plane;

	plane = (t_plane *)shape->object;
	*transform = plane->transformation;
	*material = plane->material;
	shape->local_normal_at = normal_at_plane;
	shape->local_intersect = intersect_plane;
}

void	init_cylinder_attr(t_object *shape, \
		t_matrices **transform, t_material *material)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)shape->object;
	*transform = cylinder->transformation;
	*material = cylinder->material;
	shape->local_normal_at = normal_at_cylinder;
	shape->local_intersect = intersect_cylinder;
}

void	init_cone_attr(t_object *shape, \
		t_matrices **transform, t_material *material)
{
	t_cone	*cone;

	cone = (t_cone *)shape->object;
	*transform = cone->transformation;
	*material = cone->material;
	shape->local_normal_at = normal_at_cone;
	shape->local_intersect = intersect_cone;
}

void	init_object_attr(int type_object, t_object *obj)
{
	void		*object;
	t_matrices	*transform;
	t_material	material;

	transform = NULL;
	object = obj->object;
	if (type_object == SPHERE)
		init_sphere_attr(obj, &transform, &material);
	else if (type_object == PLANE)
		init_plane_attr(obj, &transform, &material);
	else if (type_object == CYLINDER)
		init_cylinder_attr(obj, &transform, &material);
	else if (type_object == CONE)
		init_cone_attr(obj, &transform, &material);
	set_tranform(obj, transform);
	set_material(obj, material);
}

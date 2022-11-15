/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:19:12 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:19:12 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_sphere	*sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	sphere->origin = origin();
	sphere->radius = 1.0;
	sphere->transformation = identity_matrix(DEFAULT_DIMENSION);
	sphere->material = make_material();
	return (sphere);
}

t_sphere	*glass_sphere(void)
{
	t_sphere	*s;

	s = sphere();
	s->material.transparency = 1;
	s->material.refractive_index = 1.5;
	return (s);
}

t_intersections	*intersect_sphere(t_object *shape, t_ray ray)
{
	t_equations_vars	vars;
	t_intersections		*head_entersections;
	t_tuple				sphere_to_ray;
	t_sphere			*sphere;

	head_entersections = NULL;
	sphere = (t_sphere *)shape->object;
	sphere_to_ray = substract_tuple(ray.origin, sphere->origin);
	vars.a = dot_product(ray.direction, ray.direction);
	vars.b = 2 * dot_product(ray.direction, sphere_to_ray);
	vars.c = dot_product(substract_tuple(ray.origin, sphere->origin), \
								sphere_to_ray) - 1;
	vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
	if (vars.determinant < EPSILON)
		return (NULL);
	else
	{
		vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
		vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
		add_intersection(&head_entersections, intersection(vars.sol1, shape));
		add_intersection(&head_entersections, intersection(vars.sol2, shape));
		return (head_entersections);
	}
}

t_tuple	normal_at_sphere(t_object *shape, t_tuple object_point)
{
	t_sphere	*sphere;
	t_tuple		object_normal;

	sphere = (t_sphere *)shape->object;
	object_normal = substract_tuple(object_point, make_tuple(0, 0, 0, POINT));
	return (object_normal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:12:08 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:22:57 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_cone	*cone(void)
{
	t_cone	*cone_shape;

	cone_shape = malloc(sizeof(t_cone));
	cone_shape->origin = origin();
	cone_shape->radius = 1.0;
	cone_shape->min = -INFINITY;
	cone_shape->max = INFINITY;
	cone_shape->closed = FALSE;
	cone_shape->transformation = identity_matrix(DEFAULT_DIMENSION);
	cone_shape->material = make_material();
	return (cone_shape);
}

void	set_intersections_cone(t_intersections **cone_intersections, \
					t_object *shape, t_ray ray, t_equations_vars vars)
{
	float				y_intersection;
	t_cone				*cone;

	cone = (t_cone *)shape->object;
	vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
	if (vars.determinant < 0)
		return ;
	else
	{
		vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
		vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
		y_intersection = ray.origin.y + vars.sol1 * ray.direction.y;
		if (y_intersection >= cone->min && y_intersection <= cone->max)
			add_intersection(&cone_intersections, \
					intersection(vars.sol1, shape));
		y_intersection = ray.origin.y + vars.sol2 * ray.direction.y;
		if (y_intersection >= cone->min && y_intersection <= cone->max)
			add_intersection(&cone_intersections, \
						intersection(vars.sol2, shape));
	}
}

t_intersections	*intersect_cone(t_object *shape, t_ray ray)
{
	t_equations_vars	vars;
	t_intersections		*head_entersections;

	head_entersections = NULL;
	vars.a = ray.direction.x * ray.direction.x - ray.direction.y * \
				ray.direction.y + ray.direction.z * ray.direction.z;
	vars.b = 2 * ray.origin.x * ray.direction.x - 2 * ray.origin.y * \
				ray.direction.y + 2 * ray.origin.z * ray.direction.z;
	vars.c = ray.origin.x * ray.origin.x - ray.origin.y * \
				ray.origin.y + ray.origin.z * ray.origin.z;
	if (fabs(vars.a) >= EPSILON && fabs(vars.b) < EPSILON)
	{
		vars.sol1 = (-vars.c / (2 * vars.b));
		add_intersection(&head_entersections, \
			intersection(vars.sol1, shape));
	}
	else if (fabs(vars.a) >= EPSILON)
		set_intersections_cone(&head_entersections, shape, ray, vars);
	cone_intersect_caps(shape, ray, &head_entersections);
	return (head_entersections);
}

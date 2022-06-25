/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:23:12 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:28:53 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_cylinder	*cylinder(void)
{
	t_cylinder	*cylinder_shape;

	cylinder_shape = malloc(sizeof(t_cylinder));
	cylinder_shape->origin = origin();
	cylinder_shape->radius = 1.0;
	cylinder_shape->min = -INFINITY;
	cylinder_shape->max = INFINITY;
	cylinder_shape->closed = 0;
	cylinder_shape->transformation = identity_matrix(DEFAULT_DIMENSION);
	cylinder_shape->material = make_material();
	return (cylinder_shape);
}

void	set_intersections_cylinder(t_intersections **cyl_intersections, \
					t_object *shape, t_ray ray, t_equations_vars vars)
{
	float				y_intersection;
	t_cylinder			*cylinder;

	cylinder = (t_cylinder *)shape->object;
	vars.b = 2 * ray.origin.x * ray.direction.x + 2 * \
			ray.origin.z * ray.direction.z;
	vars.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
	vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
	if (vars.determinant < 0)
		return ;
	else
	{
		vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
		vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
		y_intersection = ray.origin.y + vars.sol1 * ray.direction.y;
		if (y_intersection >= cylinder->min && y_intersection <= cylinder->max)
			add_intersection(&cyl_intersections, \
				intersection(vars.sol1, shape));
		y_intersection = ray.origin.y + vars.sol2 * ray.direction.y;
		if (y_intersection >= cylinder->min && y_intersection <= cylinder->max)
			add_intersection(&cyl_intersections, \
				intersection(vars.sol2, shape));
		cylinder_intersect_caps(shape, ray, &cyl_intersections);
	}
}

t_intersections	*intersect_cylinder(t_object *shape, t_ray ray)
{
	t_equations_vars	vars;
	t_intersections		*head_entersections;
	float				y_intersection;
	t_cylinder			*cylinder;

	head_entersections = NULL;
	cylinder = (t_cylinder *)shape->object;
	vars.a = ray.direction.x * ray.direction.x + \
				ray.direction.z * ray.direction.z;
	if (is_equal(vars.a, 0))
		cylinder_intersect_caps(shape, ray, &head_entersections);
	else
	{
		set_intersections_cylinder(&head_entersections, shape, ray, vars);
	}
	return (head_entersections);
}

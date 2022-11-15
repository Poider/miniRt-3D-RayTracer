/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:25:28 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 15:35:03 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "miniRt.h"

typedef struct s_cylinder
{
	t_tuple		origin;
	float		radius;
	float		min;
	float		max;
	int			closed;
	t_matrices	*transformation;
	t_matrices	*inverse_transformation;
	t_material	material;
}				t_cylinder;

t_cylinder		*cylinder(void);
t_tuple			normal_at_cylinder(t_object *shape, t_tuple world_point);
t_intersections	*intersect_cylinder(t_object *cylinder, t_ray ray);
int				cylinder_check_cap(t_ray ray, float t);
void			cylinder_intersect_caps(t_object *cylinder_object, \
						t_ray ray, t_intersections **l_intersections);
void			set_intersections_cylinder(t_intersections **cyl_intersections, \
					t_object *shape, t_ray ray, t_equations_vars vars);
#endif
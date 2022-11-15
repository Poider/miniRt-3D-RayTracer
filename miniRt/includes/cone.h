/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:23:39 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 15:34:46 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "miniRt.h"

typedef struct s_cone
{
	t_tuple		origin;
	float		radius;
	float		min;
	float		max;
	int			closed;
	t_matrices	*transformation;
	t_matrices	*inverse_transformation;
	t_material	material;
}				t_cone;

t_cone			*cone(void);
t_tuple			normal_at_cone(t_object *shape, t_tuple world_point);
t_intersections	*intersect_cone(t_object *cone, t_ray ray);
int				cone_check_cap(t_ray ray, float t, float y);
void			cone_intersect_caps(t_object *cone_object, \
					t_ray ray, t_intersections **l_intersections);
void			set_intersections_cone(t_intersections **cone_intersections, \
					t_object *shape, t_ray ray, t_equations_vars vars);

#endif
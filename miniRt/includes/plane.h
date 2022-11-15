/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:51:23 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 16:32:21 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "miniRt.h"

typedef struct s_plane
{
	t_matrices	*transformation;
	t_matrices	*inverse_transformation;
	t_material	material;
}			t_plane;

t_plane			*plane(void);
t_tuple			normal_at_plane(t_object *plane, t_tuple world_point);
t_intersections	*intersect_plane(t_object *plane, t_ray ray);

#endif
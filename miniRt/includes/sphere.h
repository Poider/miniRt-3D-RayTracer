/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:57:05 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:57:05 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "miniRt.h"

typedef struct s_sphere
{
	t_tuple		origin;
	float		radius;
	t_matrices	*transformation;
	t_matrices	*inverse_transformation;
	t_material	material;
}				t_sphere;

t_sphere		*sphere(void);
t_sphere		*glass_sphere(void);
void			draw_sphere(t_tuple camera, float z_image_plane);
t_tuple			normal_at_sphere(t_object *sphere, t_tuple world_point);
t_intersections	*intersect_sphere(t_object *sphere, t_ray ray);

#endif
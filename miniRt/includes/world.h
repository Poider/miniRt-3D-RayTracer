/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:02:06 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:03:47 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "miniRt.h"

typedef struct s_world
{
	t_tuple		ambient_color;
	float		ambient_ratio;
	t_light		*light;
	t_object	*objects;
}				t_world;

t_world	create_world(void);
t_world	default_world(void);
t_tuple	color_at(t_world world, t_ray ray, int max_depth);
void	draw_world(t_tuple camera, float z_image_plane);

#endif
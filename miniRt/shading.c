/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:18:09 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 17:50:06 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	is_shadowed(t_world *world, t_light *light, t_tuple point)
{
	t_tuple			light_pos;
	t_ray			shadow_ray;
	t_intersections	*shadow_intersect;
	t_intersections	*hit_intersection;
	float			magnitude;

	shadow_intersect = NULL;
	hit_intersection = NULL;
	light_pos = light->position;
	shadow_ray.direction = substract_tuple(light_pos, point);
	shadow_ray.origin = point;
	magnitude = tuple_magnitude(shadow_ray.direction);
	shadow_ray.direction = tuple_normalize(shadow_ray.direction);
	shadow_intersect = intersect_word(*world, shadow_ray);
	hit_intersection = hit(shadow_intersect);
	if (hit_intersection)
	{
		if (hit_intersection->t < magnitude)
		{
			free_list_intersection(shadow_intersect);
			return (TRUE);
		}
	}
	free_list_intersection(shadow_intersect);
	return (FALSE);
}

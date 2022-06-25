/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:10:09 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:16:24 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_tuple	stripe_at(t_pattern *pattern, t_tuple point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_tuple	gradien_at(t_pattern *pattern, t_tuple point)
{
	t_tuple	colors_distance;
	t_tuple	res_color;
	float	fraction_x;

	colors_distance = substract_tuple(pattern->color_b, pattern->color_a);
	fraction_x = point.x - floor(point.x);
	res_color = add_tuple(pattern->color_a, \
				tuple_scalar_multiplication(colors_distance, fraction_x));
	return (res_color);
}

t_tuple	ring_at(t_pattern *pattern, t_tuple point)
{
	float	distance;

	distance = sqrt(pow(point.x, 2) + pow(point.z, 2));
	if ((int)floor(distance) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_tuple	checkerbord_at(t_pattern *pattern, t_tuple point)
{
	float	u;
	float	v;
	float	r;
	int		floor_z;

	u = point.x;
	v = point.y;
	floor_z = floor(point.z);
	if (pattern->is_3d == FALSE)
	{
		floor_z = 0;
		r = sqrt(pow(point.x, 2) + pow(point.y, 2) + pow(point.z, 2));
		u = (atan(point.z / point.x) + M_PI) / (M_PI * 2);
		v = (acos(point.y / r)) / M_PI;
		u = (u * 20);
		v = (v * 10);
	}
	if ((int)(floor(u) + floor(v) + floor_z) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

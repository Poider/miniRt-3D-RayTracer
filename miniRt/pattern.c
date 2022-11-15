/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:10:09 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/14 18:39:39 by klaarous         ###   ########.fr       */
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

float	*spherical_map(t_tuple p)
{
	float	theta;
	float	*res;
	float	radius;
	float	phi;
	float	raw_u;

	theta = atan2(p.x, p.z);
	res = malloc(sizeof(float) * 2);
	radius = tuple_magnitude(make_tuple(p.x, p.y, p.z, VECTOR));
	phi = acos(p.y / radius);
	raw_u = theta / (2 * M_PI);
	res[0] = 1 - (raw_u + 0.5);
	res[1] = 1 - phi / M_PI;
	return (res);
}

t_tuple	checkerbord_at(t_pattern *pattern, t_tuple point)
{
	float	u;
	float	v;
	float	r;
	int		floor_z;
	float	*uv;

	u = point.x;
	v = point.y;
	floor_z = floor(point.z);
	if (pattern->is_3d == FALSE)
	{
		floor_z = 0;
		uv = spherical_map(point);
		uv[0] *= 22;
		uv[1] *= 10;
		u = uv[0];
		v = uv[1];
		free(uv);
	}
	if ((int)(floor(u) + floor(v) + floor_z) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:39:01 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/04 21:51:42 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	image_pixel_put(t_parameters *param, t_tuple point, int color)
{
	char	*pixel;
	int		x;
	int		y;

	x = point.x;
	y = point.y;
	if (x > 0 && y > 0 && x < param->camera.hsize && y < param->camera.vsize)
	{
		pixel = param->address + (y * (param->linesize)
				+ x * (param->bitsperpixel) / 8);
		*(int *)pixel = color;
	}
}

void	plot(int x, int y, t_tuple color, t_parameters *param)
{
	image_pixel_put(param, make_tuple(x, y, 0, POINT), get_color(color));
}

void	render(t_camera camera, t_world world, t_parameters *param)
{
	int		y;
	int		x;
	t_ray	ray;

	y = 0;
	while (y < camera.vsize)
	{
		x = 0;
		while (x < camera.hsize)
		{
			ray = ray_for_pixel(camera, x, y);
			plot(x, y, color_at(world, ray, 0), param);
			x++;
		}
		y++;
	}
}

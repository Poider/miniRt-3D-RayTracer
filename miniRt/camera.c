/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:04:13 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 16:49:55 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_matrices	*view_transformation(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrices	*orientation;
	t_matrices	*transformation;

	forward = tuple_normalize(substract_tuple(to, from));
	left = cross_product(forward, tuple_normalize(up));
	true_up = cross_product(left, forward);
	orientation = identity_matrix(DEFAULT_DIMENSION);
	orientation->matrix[0][0] = left.x;
	orientation->matrix[0][1] = left.y;
	orientation->matrix[0][2] = left.z;
	orientation->matrix[1][0] = true_up.x;
	orientation->matrix[1][1] = true_up.y;
	orientation->matrix[1][2] = true_up.z;
	orientation->matrix[2][0] = negate_val(forward.x);
	orientation->matrix[2][1] = negate_val(forward.y);
	orientation->matrix[2][2] = negate_val(forward.z);
	transformation = multiply_matrices(orientation, \
						translation(negate_tuple(from)), FALSE, TRUE);
	free_matrix(orientation);
	return (transformation);
}

t_camera	make_camera(float hsize, float vsize, float field_of_view)
{
	t_camera	camera;
	float		aspect_ratio;
	float		half_view;

	camera.hsize = hsize;
	camera.vsize = vsize;
	camera.fov = field_of_view;
	camera.transform = identity_matrix(DEFAULT_DIMENSION);
	camera.inverse_transform = identity_matrix(DEFAULT_DIMENSION);
	half_view = tan(field_of_view / 2);
	aspect_ratio = hsize / vsize;
	if (aspect_ratio >= 1.0)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / aspect_ratio;
	}
	else
	{
		camera.half_width = half_view * aspect_ratio;
		camera.half_height = half_view;
	}
	camera.pixel_size = (camera.half_width * 2) / hsize;
	return (camera);
}

t_ray	ray_for_pixel(t_camera camera, int x, int y)
{
	t_ray	ray;
	float	word_x;
	float	word_y;
	t_tuple	pixel;

	word_x = camera.half_width - ((x + 0.5) * camera.pixel_size);
	word_y = camera.half_height - ((y + 0.5) * camera.pixel_size);
	pixel = multiply_matrix_tuple(*camera.inverse_transform, \
						make_tuple(word_x, word_y, -1, POINT));
	ray.origin = multiply_matrix_tuple(*camera.inverse_transform, origin());
	ray.direction = tuple_normalize(substract_tuple(pixel, ray.origin));
	return (ray);
}

void	set_camera_transformation(t_camera *camera, \
					t_tuple from, t_tuple to, t_tuple up)
{
	t_matrices	*inverse_matrix;

	free_matrix(camera->transform);
	camera->transform = view_transformation(from, to, up);
	inverse_matrix = invert_matrix(camera->transform);
	if (inverse_matrix)
		free_matrix(camera->inverse_transform);
	camera->inverse_transform = inverse_matrix;
}

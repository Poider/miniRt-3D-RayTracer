/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:36 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:17:36 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_ray	make_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	ray_position(t_ray ray, float distance)
{
	return (add_tuple(ray.origin, \
		tuple_scalar_multiplication(ray.direction, distance)));
}

t_ray	transform_ray(t_ray ray, t_matrices matrix)
{
	t_ray	transformed_ray;

	transformed_ray.origin = multiply_matrix_tuple(matrix, ray.origin);
	transformed_ray.direction = multiply_matrix_tuple(matrix, ray.direction);
	return (transformed_ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:45:43 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 17:55:11 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	set_tranform(t_object *object, t_matrices *matrix)
{
	object->transformation = matrix;
	object->inverse_transformation = invert_matrix(matrix);
}

void	set_material(t_object *object, t_material material)
{
	object->material = material;
}

t_tuple	normal_at(t_object *shape, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrices	*transposed_matrix;

	object_point = multiply_matrix_tuple(\
		*shape->inverse_transformation, world_point);
	object_normal = shape->local_normal_at(shape, object_point);
	transposed_matrix = transpose_matrix(shape->inverse_transformation);
	world_normal = multiply_matrix_tuple(\
	*transposed_matrix, object_normal);
	world_normal.w = 0;
	free_matrix(transposed_matrix);
	return (tuple_normalize(world_normal));
}

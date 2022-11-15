/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:15:46 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/14 18:25:37 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	set_local_pattern_function(t_pattern *pattern)
{
	int	type_pattern;

	type_pattern = pattern->type_pattern;
	if (type_pattern == STRIPE_PATTERN)
		pattern->local_pattern_at = stripe_at;
	else if (type_pattern == GRADIENT_PATTERN)
		pattern->local_pattern_at = gradien_at;
	else if (type_pattern == RING_PATTERN)
		pattern->local_pattern_at = ring_at;
	else if (type_pattern == CHECKERBORAD_PATTERN)
		pattern->local_pattern_at = checkerbord_at;
	else
	{
		printf("Error pattern not exist\n");
		exit(0);
	}
}

t_pattern	*make_pattern(t_tuple white, t_tuple black, \
							int type_pattern, int is_3d)
{
	t_pattern	*pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->color_a = white;
	pattern->color_b = black;
	pattern->type_pattern = type_pattern;
	pattern->transformation = identity_matrix(DEFAULT_DIMENSION);
	pattern->inverse_transformation = identity_matrix(DEFAULT_DIMENSION);
	pattern->is_3d = is_3d;
	set_local_pattern_function(pattern);
	return (pattern);
}

void	set_transformation_pattern(t_pattern *pattern, t_matrices *matrix)
{
	t_matrices	*inverse_transform;

	if (!pattern)
		return ;
	free_matrix(pattern->transformation);
	pattern->transformation = matrix;
	inverse_transform = invert_matrix(matrix);
	if (inverse_transform)
		pattern->inverse_transformation = inverse_transform;
}

t_tuple	pattern_at_shape(t_pattern *pattern, t_tuple point, t_object *shape)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = multiply_matrix_tuple(*shape->inverse_transformation, point);
	pattern_point = multiply_matrix_tuple(\
					*pattern->inverse_transformation, object_point);
	return (pattern->local_pattern_at(pattern, pattern_point));
}

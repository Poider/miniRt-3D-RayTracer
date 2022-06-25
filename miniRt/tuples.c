/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:24:14 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:24:14 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_tuple	make_tuple(float x, float y, float z, float w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

float	tuple_magnitude(t_tuple tuple)
{
	float	magnitude;

	magnitude = sqrt(tuple.x * tuple.x + tuple.y * tuple.y \
					+ tuple.z * tuple.z + tuple.w * tuple.w);
	return (magnitude);
}

t_tuple	tuple_normalize(t_tuple tuple)
{
	float	magnitude;
	t_tuple	normalized_vector;

	magnitude = tuple_magnitude(tuple);
	normalized_vector.x = tuple.x / magnitude;
	normalized_vector.y = tuple.y / magnitude;
	normalized_vector.z = tuple.z / magnitude;
	normalized_vector.w = tuple.w / magnitude;
	return (normalized_vector);
}

float	dot_product(t_tuple tuple1, t_tuple tuple2)
{
	float	product;

	product = tuple1.x * tuple2.x + tuple1.y * tuple2.y + \
				tuple1.z * tuple2.z + tuple1.w * tuple2.w;
	return (product);
}

t_tuple	cross_product(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	product;

	product.x = tuple1.y * tuple2.z - tuple1.z * tuple2.y;
	product.y = tuple1.z * tuple2.x - tuple1.x * tuple2.z;
	product.z = tuple1.x * tuple2.y - tuple1.y * tuple2.x;
	product.w = tuple1.w;
	return (product);
}

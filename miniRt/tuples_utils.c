/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:28:49 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:29:17 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_tuple	origin(void)
{
	make_tuple(0, 0, 0, POINT);
}

t_tuple	add_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	added_tuples;

	added_tuples.x = tuple1.x + tuple2.x;
	added_tuples.y = tuple1.y + tuple2.y;
	added_tuples.z = tuple1.z + tuple2.z;
	added_tuples.w = tuple1.w + tuple2.w;
	return (added_tuples);
}

t_tuple	substract_tuple(t_tuple tuple1, t_tuple tuple2)
{
	t_tuple	added_tuples;

	added_tuples.x = tuple1.x - tuple2.x;
	added_tuples.y = tuple1.y - tuple2.y;
	added_tuples.z = tuple1.z - tuple2.z;
	added_tuples.w = tuple1.w - tuple2.w;
	return (added_tuples);
}

t_tuple	negate_tuple(t_tuple tuple1)
{
	if (!is_equal(tuple1.x, 0.0))
		tuple1.x = -tuple1.x;
	if (!is_equal(tuple1.y, 0.0))
		tuple1.y = -tuple1.y;
	if (!is_equal(tuple1.z, 0.0))
		tuple1.z = -tuple1.z;
	return (tuple1);
}

t_tuple	tuple_scalar_multiplication(t_tuple tuple1, float scalar)
{
	t_tuple	scaled_vector;

	scaled_vector = tuple1;
	scaled_vector.x = tuple1.x * scalar;
	scaled_vector.y = tuple1.y * scalar;
	scaled_vector.z = tuple1.z * scalar;
	scaled_vector.w = tuple1.w * scalar;
	return (scaled_vector);
}

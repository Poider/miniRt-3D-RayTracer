/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:29:34 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:30:17 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_tuple	tuple_scalar_division(t_tuple tuple1, float scalar)
{
	t_tuple	scaled_vector;

	tuple1.x = tuple1.x / scalar;
	tuple1.y = tuple1.y / scalar;
	tuple1.z = tuple1.z / scalar;
	tuple1.w = tuple1.w / scalar;
	scaled_vector = tuple1;
	return (scaled_vector);
}

int	tuple_isequal(t_tuple tuple1, t_tuple tuple2)
{
	if (!is_equal(tuple1.x, tuple2.x))
		return (FALSE);
	if (!is_equal(tuple1.y, tuple2.y))
		return (FALSE);
	if (!is_equal(tuple1.z, tuple2.z))
		return (FALSE);
	return (TRUE);
}

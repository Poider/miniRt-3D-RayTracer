/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:59:59 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:59:59 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include "miniRt.h"

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_tuple;

t_tuple	make_tuple(float x, float y, float z, float w);
t_tuple	origin(void);
t_tuple	add_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple	substract_tuple(t_tuple tuple1, t_tuple tuple2);
t_tuple	negate_tuple(t_tuple tuple1);
t_tuple	tuple_scalar_multiplication(t_tuple tuple1, float scalar);
t_tuple	tuple_scalar_division(t_tuple tuple1, float scalar);
float	tuple_magnitude(t_tuple tuple);
int		tuple_isequal(t_tuple tuple1, t_tuple tuple2);
t_tuple	tuple_normalize(t_tuple tuple);
float	dot_product(t_tuple tuple1, t_tuple tuple2);
t_tuple	cross_product(t_tuple tuple1, t_tuple tuple2);

#endif
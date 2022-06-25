/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomputed_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:32:43 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 16:57:37 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

float	schlick(t_precomputed *pre_computed)
{
	float	_cos;
	float	cos_t;
	float	nr;
	float	sin2_t;
	float	r0;

	_cos = dot_product(pre_computed->eyev, pre_computed->normalv);
	if (pre_computed->n1 > pre_computed->n2)
	{
		nr = pre_computed->n1 / pre_computed->n2;
		sin2_t = nr * nr * (1 - _cos * _cos);
		if (sin2_t > 1)
			return (1);
		cos_t = sqrt(1 - sin2_t);
		_cos = cos_t;
	}
	r0 = pow((pre_computed->n1 - pre_computed->n2) / \
				(pre_computed->n1 + pre_computed->n2), 2);
	return (r0 + (1 - r0) * pow((1 - _cos), 5));
}

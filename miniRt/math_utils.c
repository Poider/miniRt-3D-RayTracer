/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:17:09 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:17:09 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	is_greater(float a, float b)
{
	if (a - b >= EPSILON)
		return (TRUE);
	return (FALSE);
}

float	abs_float(float x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

float	negate_val(float a)
{
	if (is_equal(a, 0))
		return (a);
	return (-a);
}

int	is_equal(float a, float b)
{
	if (abs_float(a - b) <= EPSILON)
		return (TRUE);
	return (FALSE);
}

int	is_lesser(float a, float b)
{
	if (a - b <= EPSILON)
		return (TRUE);
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:18:08 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:18:08 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	is_pos(int a)
{
	if (a >= 0)
		return (1);
	return (0);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrices1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:42 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:24:04 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_matrices	*translation(t_tuple vector)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][3] = vector.x;
	m[1][3] = vector.y;
	m[2][3] = vector.z;
	return (matrix);
}

t_matrices	*scaling(t_tuple vector)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = vector.x;
	m[1][1] = vector.y;
	m[2][2] = vector.z;
	return (matrix);
}

t_matrices	*shearing(t_shear shear)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][1] = shear.hxy;
	m[0][2] = shear.hxz;
	m[1][0] = shear.hyx;
	m[1][2] = shear.hyz;
	m[2][0] = shear.hzx;
	m[2][1] = shear.hzy;
	return (matrix);
}

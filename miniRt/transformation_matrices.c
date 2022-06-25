/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrices.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:21:55 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 14:23:59 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_matrices	*rotation_x(float angle)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[1][1] = cos(angle);
	m[1][2] = -sin(angle);
	m[2][1] = sin(angle);
	m[2][2] = cos(angle);
	return (matrix);
}

t_matrices	*rotation_y(float angle)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = cos(angle);
	m[0][2] = sin(angle);
	m[2][0] = -sin(angle);
	m[2][2] = cos(angle);
	return (matrix);
}

t_matrices	*rotation_z(float angle)
{
	t_matrices	*matrix;
	float		**m;

	matrix = identity_matrix(DEFAULT_DIMENSION);
	m = matrix->matrix;
	m[0][0] = cos(angle);
	m[0][1] = -sin(angle);
	m[1][0] = sin(angle);
	m[1][1] = cos(angle);
	return (matrix);
}

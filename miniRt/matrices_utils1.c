/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:22:50 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 16:34:23 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

float	element_multiplication(t_matrices *matrix1, \
		t_matrices *matrix2, int row, int col)
{
	float	sum;
	int		i;

	sum = 0.0;
	i = 0;
	while (i < matrix2->rows_num)
	{
		sum += matrix1->matrix[row][i] * matrix2->matrix[i][col];
		i++;
	}
	return (sum);
}

t_matrices	*multiply_matrices(t_matrices *matrix1, t_matrices *matrix2, \
			int is_free_mat1, int is_free_mat2)
{
	t_matrices	*final_matrix;
	int			current_row;
	int			current_col;

	if (matrix1->rows_num != matrix2->cols_num)
		return (NULL);
	final_matrix = create_matrix(matrix1->rows_num, matrix2->cols_num);
	current_row = 0;
	while (current_row < matrix1->rows_num)
	{
		current_col = 0;
		while (current_col < matrix2->cols_num)
		{
			final_matrix->matrix[current_row][current_col] = \
			element_multiplication(matrix1, matrix2, current_row, current_col);
			current_col++;
		}
		current_row++;
	}
	if (is_free_mat1)
		free_matrix(matrix1);
	if (is_free_mat2)
		free_matrix(matrix2);
	return (final_matrix);
}

t_tuple	multiply_matrix_tuple(t_matrices matrix, t_tuple tuple)
{
	t_tuple	multiplied_tuple;
	float	**m;

	m = matrix.matrix;
	if (matrix.rows_num != 4)
		return (multiplied_tuple);
	multiplied_tuple.x = tuple.x * m[0][0] + tuple.y * m[0][1] \
						+ tuple.z * m[0][2] + tuple.w * m[0][3];
	multiplied_tuple.y = tuple.x * m[1][0] + tuple.y * m[1][1] \
						+ tuple.z * m[1][2] + tuple.w * m[1][3];
	multiplied_tuple.z = tuple.x * m[2][0] + tuple.y * m[2][1] \
						+ tuple.z * m[2][2] + tuple.w * m[2][3];
	multiplied_tuple.w = tuple.x * m[3][0] + tuple.y * m[3][1] \
						+ tuple.z * m[3][2] + tuple.w * m[3][3];
	return (multiplied_tuple);
}

float	m2_determinant(t_matrices *matrix)
{
	float	determinant;
	float	**m;

	if (matrix->rows_num != 2)
		return (0);
	m = matrix->matrix;
	determinant = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	free_matrix(matrix);
	return (determinant);
}

float	get_minor(t_matrices *matrix)
{
	int		dimension;
	int		i;
	float	minor;
	float	**m;

	dimension = matrix->rows_num;
	minor = 0;
	m = matrix->matrix;
	if (matrix->rows_num == 2 && matrix->cols_num == 2)
		return (m2_determinant(matrix));
	i = 0;
	while (i < matrix->cols_num)
	{
		minor += m[0][i] * \
		get_cofactor(get_minor(get_submatrix(matrix, 0, i)), 0, i);
		i++;
	}
	if (matrix->rows_num != 4)
		free_matrix(matrix);
	return (minor);
}

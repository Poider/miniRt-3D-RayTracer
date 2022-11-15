/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:41:49 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:41:49 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_matrices	*create_matrix(int rows, int cols)
{
	t_matrices	*matrix;
	int			i;

	matrix = malloc(sizeof(t_matrices));
	matrix->rows_num = rows;
	matrix->cols_num = cols;
	matrix->matrix = malloc(sizeof(float *) * rows);
	i = 0;
	while (i < rows)
		matrix->matrix[i++] = malloc(sizeof(float) * cols);
	null_matrix(matrix);
	return (matrix);
}

t_matrices	*transpose_matrix(t_matrices *matrix)
{
	t_matrices	*transposed_matrix;
	int			i;
	int			j;

	i = 0;
	transposed_matrix = create_matrix(matrix->rows_num, matrix->cols_num);
	while (i < matrix->rows_num)
	{
		j = 0;
		while (j < matrix->cols_num)
		{
			transposed_matrix->matrix[j][i] = matrix->matrix[i][j];
			j++;
		}
		i++;
	}
	return (transposed_matrix);
}

int	is_invertible_matrix(t_matrices *matrix)
{
	float	det;

	det = determinant(matrix);
	if (is_equal(det, 0))
		return (FALSE);
	return (TRUE);
}

t_matrices	*cofactor_matrix(t_matrices *matrix)
{
	int			i;
	int			j;
	t_matrices	*final_matrix;

	final_matrix = create_matrix(matrix->rows_num, matrix->cols_num);
	i = 0;
	while (i < matrix->rows_num)
	{
		j = 0;
		while (j < matrix->cols_num)
		{
			final_matrix->matrix[i][j] = get_cofactor(\
					determinant(get_submatrix(matrix, i, j)), i, j);
			j++;
		}
		i++;
	}
	return (final_matrix);
}

t_matrices	*invert_matrix(t_matrices *matrix)
{
	t_matrices	*transposed;
	t_matrices	*inverted;
	float		det;

	det = determinant(matrix);
	if (is_equal(det, 0))
	{
		printf("here %.2f\n", det);
		return (NULL);
	}
	inverted = cofactor_matrix(matrix);
	transposed = transpose_matrix(inverted);
	free_matrix(inverted);
	inverted = matrix_element_divide(transposed, det);
	return (inverted);
}

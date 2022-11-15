/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:54:12 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 15:38:43 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	matrix_destroyer(t_matrices *matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (i < matrix->rows_num)
	{
		free(matrix->matrix[i]);
		i++;
	}
	free(matrix->matrix);
}

void	free_matrix(t_matrices *matrix)
{
	t_matrices	*matrix_to_destroy;

	matrix_to_destroy = matrix;
	matrix_destroyer(matrix_to_destroy);
	free(matrix_to_destroy);
}

void	null_matrix(t_matrices *matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->rows_num)
	{
		j = 0;
		while (j < matrix->cols_num)
		{
			matrix->matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	fill_diagonal(t_matrices *matrix, float number)
{
	int	i;

	if (!matrix)
		return (FAIL);
	i = 0;
	while (i < matrix->rows_num)
	{
		matrix->matrix[i][i] = number;
		i++;
	}
	return (SUCCESS);
}

t_matrices	*identity_matrix(int dimension)
{
	t_matrices	*matrix;

	matrix = create_matrix(dimension, dimension);
	fill_diagonal(matrix, 1);
	return (matrix);
}

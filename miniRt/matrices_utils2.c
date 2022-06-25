/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:31:05 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:41:05 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_submatrix_vars	init_submatrix_vars(int rows_num)
{
	t_submatrix_vars	vars;

	vars.i = 0;
	vars.i1 = 0;
	vars.subdimension = rows_num - 1;
	if (vars.subdimension > 1)
		vars.submatrix = create_matrix(vars.subdimension, vars.subdimension);
	return (vars);
}

int	is_count_equal(int *count, int val)
{
	if (*count == val)
	{
		(*count)++;
		return (TRUE);
	}
	return (FALSE);
}

t_matrices	*get_submatrix(t_matrices *matrix, int current_row, int current_col)
{
	t_submatrix_vars	vars;

	vars = init_submatrix_vars(matrix->rows_num);
	if (vars.subdimension <= 1)
		return (matrix);
	while (vars.i < vars.subdimension)
	{
		vars.j = 0;
		vars.j1 = 0;
		if (is_count_equal(&(vars.i1), current_row))
			continue ;
		while (vars.j < vars.subdimension)
		{
			if (is_count_equal(&(vars.j1), current_col))
				continue ;
			vars.submatrix->matrix[vars.i][vars.j] = \
					matrix->matrix[vars.i1][vars.j1];
			vars.j++;
			vars.j1++;
		}
		vars.i++;
		vars.i1++;
	}
	return (vars.submatrix);
}

float	get_cofactor(float determinant, int current_row, int current_col)
{
	float	cofactor;

	cofactor = determinant * pow(-1, current_col + current_row);
	return (cofactor);
}

float	determinant(t_matrices *matrix)
{
	return (get_minor(matrix));
}

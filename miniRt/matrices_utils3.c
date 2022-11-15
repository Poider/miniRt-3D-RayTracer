/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:44:50 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:45:22 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_matrices	*matrix_element_divide(t_matrices *matrix, float num)
{
	int	i;
	int	j;

	i = 0;
	while (i < matrix->rows_num)
	{
		j = 0;
		while (j < matrix->cols_num)
		{
			matrix->matrix[i][j] /= num;
			j++;
		}
		i++;
	}
	return (matrix);
}

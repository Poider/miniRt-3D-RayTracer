/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:36:32 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:36:32 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "miniRt.h"

# define DEFAULT_DIMENSION 4

typedef struct s_matrices
{
	int		rows_num;
	int		cols_num;
	float	**matrix;
}				t_matrices;

typedef struct s_shear
{
	float	hxy;
	float	hxz;
	float	hyx;
	float	hyz;
	float	hzx;
	float	hzy;
}			t_shear;

typedef struct s_submatrix_vars
{
	int			subdimension;
	t_matrices	*submatrix;
	int			i;
	int			j;
	int			i1;
	int			j1;

}				t_submatrix_vars;

void		matrix_destroyer(t_matrices *matrix);
void		free_matrix(t_matrices *matrix);
void		null_matrix(t_matrices *matrix);
t_matrices	*create_matrix(int rows, int cols);
int			fill_diagonal(t_matrices *matrix, float number);
t_matrices	*identity_matrix(int dimension);
t_matrices	*multiply_matrices(t_matrices *matrix1, t_matrices *matrix2, \
				int is_free_mat1, int is_free_mat2);
t_tuple		multiply_matrix_tuple(t_matrices matrix, t_tuple tuple);
t_matrices	*get_submatrix(t_matrices *matrix, \
					int current_row, int current_col);
float		get_minor(t_matrices *matrix);
float		get_cofactor(float determinant, int current_row, int current_col);
float		determinant(t_matrices *matrix);
t_matrices	*transpose_matrix(t_matrices *matrix);
int			is_invertible_matrix(t_matrices *matrix);
t_matrices	*cofactor_matrix(t_matrices *matrix);
t_matrices	*matrix_element_divide(t_matrices *matrix, float num);
t_matrices	*invert_matrix(t_matrices *matrix);
t_matrices	*transform(void (*func)(void), t_matrices *sphere_matrix);
void		print_matrix(t_matrices matrix);

// transformations
t_matrices	*rotation_x(float angle);
t_matrices	*rotation_y(float angle);
t_matrices	*rotation_z(float angle);
t_matrices	*translation(t_tuple vector);
t_matrices	*scaling(t_tuple vector);
t_matrices	*shearing(t_shear shear);

#endif

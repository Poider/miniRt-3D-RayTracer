/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transformations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:34:43 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 16:29:27 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

t_matrices	*rotation_make(t_matrices *matrix, char *line, char c)
{
	t_matrices	*transformation;
	t_matrices	*transformed_matrix;
	float		angle;

	angle = degree_to_radian(float_parse(line));
	if (c == 'x')
		transformation = rotation_x(angle);
	else if (c == 'y')
		transformation = rotation_y(angle);
	else if (c == 'z')
		transformation = rotation_z(angle);
	transformed_matrix = multiply_matrices(transformation, \
							matrix, FALSE, FALSE);
	free_matrix(matrix);
	free_matrix(transformation);
	return (transformed_matrix);
}

t_matrices	*translate_scale_make(t_matrices *matrix, char *line, char c)
{
	t_tuple		transformation_vector;
	t_matrices	*transformation;
	t_matrices	*transformed_matrix;

	transformation_vector = tuple_from_line(line);
	if (c == 't')
	{
		transformation = translation(transformation_vector);
		transformed_matrix = multiply_matrices(transformation, \
							matrix, FALSE, FALSE);
	}
	else if (c == 's')
	{
		transformation = scaling(transformation_vector);
		transformed_matrix = multiply_matrices(transformation, \
							matrix, FALSE, FALSE);
	}
	free_matrix(matrix);
	free_matrix(transformation);
	return (transformed_matrix);
}

t_matrices	*shear_make(t_matrices *matrix, char *line)
{
	t_shear		sh;
	t_matrices	*transformation;
	t_matrices	*transformed_matrix;
	char		**shear;

	shear = ft_split(line, ',');
	sh.hxy = float_parse(shear[0]);
	sh.hxz = float_parse(shear[1]);
	sh.hyx = float_parse(shear[2]);
	sh.hyz = float_parse(shear[3]);
	sh.hzx = float_parse(shear[4]);
	sh.hzy = float_parse(shear[5]);
	transformation = shearing(sh);
	transformed_matrix = multiply_matrices(transformation, \
						matrix, FALSE, FALSE);
	free_split(shear);
	free_matrix(matrix);
	free_matrix(transformation);
	return (transformed_matrix);
}

t_matrices	*set_transformation_matrice(t_matrices *transformations, \
			char **lines, int i)
{
	t_matrices	*old_transformation;

	old_transformation = transformations;
	if (!ft_strncmp(to_upper(lines[i]), "ROTX", 4))
		transformations = rotation_make(transformations, lines[i + 1], 'x');
	else if (!ft_strncmp(to_upper(lines[i]), "ROTY", 4))
		transformations = rotation_make(transformations, lines[i + 1], 'y');
	else if (!ft_strncmp(to_upper(lines[i]), "ROTZ", 4))
		transformations = rotation_make(transformations, lines[i + 1], 'z');
	else if (!ft_strncmp(to_upper(lines[i]), "TRANSLATE", 4))
		transformations = translate_scale_make(transformations, \
		lines[i + 1], 't');
	else if (!ft_strncmp(to_upper(lines[i]), "SCALE", 4))
		transformations = translate_scale_make(transformations, \
		lines[i + 1], 's');
	else if (!ft_strncmp(to_upper(lines[i]), "SHEAR", 4))
		transformations = shear_make(transformations, lines[i + 1]);
	return (transformations);
}

t_matrices	*get_transformations(char *line)
{
	char		**lines;
	int			i;
	t_matrices	*transformations;

	transformations = identity_matrix(4);
	i = 0;
	lines = ft_split(line, ' ');
	if (len(lines) % 2 != 0)
		parse_error();
	while (lines[i])
	{
		transformations = set_transformation_matrice(transformations, lines, i);
		i += 2;
	}
	free_split(lines);
	free(line);
	return (transformations);
}

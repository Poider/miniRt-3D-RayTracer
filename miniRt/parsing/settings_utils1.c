/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:33:51 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 15:43:15 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

t_matrices	*get_coordinate_matrix(char *line, t_matrices *matrix)
{
	t_matrices	*coordinates_matrix;
	t_tuple		translation_vector;
	t_matrices	*transformations_matrix;

	translation_vector = tuple_set(line);
	transformations_matrix = translation(translation_vector);
	coordinates_matrix = multiply_matrices(transformations_matrix, \
						matrix, FALSE, FALSE);
	free_matrix(matrix);
	free_matrix(transformations_matrix);
	return (coordinates_matrix);
}

t_matrices	*coordinate_set(t_matrices *matrix, char *line, int fd)
{
	t_matrices	*coordinates_matrix;
	t_tuple		translation_vector;
	char		*transformations;
	t_matrices	*transformations_matrix;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (matrix);
	}
	transformations = get_next_line(fd);
	if (!ft_strncmp(to_upper(transformations), "NULL", 4))
		free(transformations);
	else
	{
		transformations_matrix = get_transformations(transformations);
		coordinates_matrix = matrix;
		matrix = multiply_matrices(transformations_matrix, matrix, \
				FALSE, FALSE);
		free_matrix(coordinates_matrix);
		free_matrix(transformations_matrix);
		coordinates_matrix = 0;
	}
	return (get_coordinate_matrix(line, matrix));
}

t_tuple	color_set_no_free(char *line)
{
	t_tuple	color;
	float	r;
	float	g;
	float	b;
	char	**vector;

	vector = ft_split(line, ',');
	r = min(max(0, float_parse(vector[0])), 255) / 255;
	g = min(max(0, float_parse(vector[1])), 255) / 255;
	b = min(max(0, float_parse(vector[2])), 255) / 255;
	color = make_color(r, g, b);
	free_split(vector);
	return (color);
}

t_tuple	color_set(char *line)
{
	t_tuple	color;
	float	r;
	float	g;
	float	b;
	char	**vector;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (make_color(1, 0, 0));
	}
	vector = ft_split(line, ',');
	if (len(vector) < 3)
		return (make_color(0, 0, 0));
	r = min(max(0, float_parse(vector[0])), 255) / 255;
	g = min(max(0, float_parse(vector[1])), 255) / 255;
	b = min(max(0, float_parse(vector[2])), 255) / 255;
	color = make_color(r, g, b);
	free_split(vector);
	free(line);
	return (color);
}

float	reflection_set(char *line)
{
	float	reflection;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (0);
	}
	reflection = max(min(float_parse(line), 1), 0);
	free(line);
	return (reflection);
}

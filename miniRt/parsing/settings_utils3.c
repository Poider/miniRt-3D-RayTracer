/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:46:16 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/14 18:34:50 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

float	specular_set(float default_specular, char *line)
{
	float	specular;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (0.3);
	}
	specular = max(float_parse(line), 0);
	free(line);
	return (specular);
}

float	diffuse_set(float default_diffuse, char *line)
{
	float	diffuse;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (0.7);
	}
	diffuse = max(min(float_parse(line), 1), 0);
	free(line);
	return (diffuse);
}

t_matrices	*diameter_set(t_matrices *matrix, char *line, char c)
{
	t_matrices	*transformed_matrix;
	t_matrices	*transformation;
	float		d;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (matrix);
	}
	d = max(0, float_parse(line));
	if (c == 's')
		transformation = scaling(make_tuple(d, d, d, VECTOR));
	else
		transformation = scaling(make_tuple(d, d, 1, VECTOR));
	transformed_matrix = multiply_matrices(transformation, \
						matrix, FALSE, FALSE);
	free_matrix(transformation);
	free_matrix(matrix);
	free(line);
	return (transformed_matrix);
}

void	height_set(float *_min, float *_max, char *line)
{
	char	**numbers;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		*_min = 0;
		*_max = 2;
		return ;
	}
	numbers = ft_split(line, ' ');
	*_min = float_parse(numbers[0]);
	*_max = *_min + max(float_parse(numbers[1]), 0);
	free_split(numbers);
	free(line);
}

void	set_max(float *_min, float *_max, char *line)
{
	*_min = 0;
	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		*_max = 2;
		return ;
	}
	*_max = max(float_parse(line), 0);
	free(line);
}

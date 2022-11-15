/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:39:35 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 15:41:28 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

float	transparency_set(char *line)
{
	float	transparency;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (0);
	}
	transparency = max(min(float_parse(line), 1), 0);
	free(line);
	return (transparency);
}

float	refractive_set(char *line)
{
	float	refractive;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (1);
	}
	refractive = float_parse(line);
	free(line);
	return (refractive);
}

t_matrices	*pattern_transformation_set(int fd)
{
	t_matrices	*transformed_matrice;
	char		*line;

	transformed_matrice = NULL;
	line = get_next_line(fd);
	if (!ft_strncmp(to_upper(line), "NULL", 4))
		free(line);
	else
		transformed_matrice = get_transformations(line);
	return (transformed_matrice);
}

int	get_pattern_type(char *parameter)
{
	int	pattern_type;

	if (!ft_strncmp(to_upper(parameter), "CHECKERBOARD", 12))
		pattern_type = CHECKERBORAD_PATTERN;
	else if (!ft_strncmp(to_upper(parameter), "RING", 4))
		pattern_type = RING_PATTERN;
	else if (!ft_strncmp(to_upper(parameter), "STRIPE", 6))
		pattern_type = STRIPE_PATTERN;
	else if (!ft_strncmp(to_upper(parameter), "GRADIENT", 8))
		pattern_type = GRADIENT_PATTERN;
	else
		pattern_type = CHECKERBORAD_PATTERN;
	return (pattern_type);
}

void	pattern_set(t_material *material, char *line, int fd, int is_3d)
{
	int			pattern_type;
	t_pattern	*pattern;
	char		**parameters;
	t_matrices	*pattern_transformation;

	pattern_transformation = NULL;
	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return ;
	}
	parameters = ft_split(line, ' ');
	pattern_type = get_pattern_type(parameters[0]);
	pattern_transformation = pattern_transformation_set(fd);
	pattern = make_pattern(color_set_no_free(parameters[1]), \
			color_set_no_free(parameters[2]), pattern_type, is_3d);
	set_material_pattern(material, pattern);
	if (pattern_transformation)
		set_transformation_pattern(material->pattern, pattern_transformation);
	free(line);
	free_split(parameters);
}

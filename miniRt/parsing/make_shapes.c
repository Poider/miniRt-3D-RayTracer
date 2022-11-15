/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:41:40 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 16:56:22 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"





t_object	*plane_make(int fd)
{
	char	*line;
	t_plane	*shape;

	line = NULL;
	shape = plane();
	plane_settings(fd, shape, line);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return ((t_object *)shape);
}

t_object	*cylinder_make(int fd)
{
	char		*line;
	t_cylinder	*shape;

	line = NULL;
	shape = cylinder();
	cylinder_settings(fd, shape, line);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return ((t_object *)shape);
}

t_object	*cone_make(int fd)
{
	char	*line;
	t_cone	*shape;

	line = NULL;
	shape = cone();
	cone_settings(fd, shape, line);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return ((t_object *)shape);
}

t_object	*sphere_make(int fd)
{
	char		*line;
	t_sphere	*shape;

	line = NULL;
	shape = sphere();
	sphere_settings(fd, shape, line);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return ((t_object *)shape);
}

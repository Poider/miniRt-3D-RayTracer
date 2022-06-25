/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:41:40 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 17:13:55 by klaarous         ###   ########.fr       */
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
	while (ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
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
	while (ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
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
	while (ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
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
	while (ft_strncmp(line, "END", 3))
	{
		if (line)
		{
			free(line);
			line = 0;
		}
		line = get_next_line(fd);
	}
	return ((t_object *)shape);
}

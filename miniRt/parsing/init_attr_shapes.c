/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_attr_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:15:08 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 17:08:42 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

void	plane_settings(int fd, t_plane *shape, char *line)
{
	line = get_next_line(fd);
	shape->transformation = coordinate_set(shape->transformation, line, fd);
	line = get_next_line(fd);
	shape->material.color = color_set(line);
	line = get_next_line(fd);
	shape->material.reflective = reflection_set(line);
	line = get_next_line(fd);
	shape->material.transparency = transparency_set(line);
	line = get_next_line(fd);
	shape->material.refractive_index = refractive_set(line);
	line = get_next_line(fd);
	pattern_set(&shape->material, line, fd, TRUE);
	line = get_next_line(fd);
	shape->material.specular = specular_set(shape->material.specular, line);
	line = get_next_line(fd);
	shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
}

void	cylinder_settings(int fd, t_cylinder *shape, char *line)
{
	line = get_next_line(fd);
	shape->transformation = diameter_set(shape->transformation, line, 'c');
	line = get_next_line(fd);
	shape->transformation = coordinate_set(shape->transformation, line, fd);
	line = get_next_line(fd);
	height_set(&shape->min, &shape->max, line);
	line = get_next_line(fd);
	shape->material.color = color_set(line);
	line = get_next_line(fd);
	shape->material.reflective = reflection_set(line);
	line = get_next_line(fd);
	shape->material.transparency = transparency_set(line);
	line = get_next_line(fd);
	shape->material.refractive_index = refractive_set(line);
	line = get_next_line(fd);
	pattern_set(&shape->material, line, fd, TRUE);
	line = get_next_line(fd);
	shape->material.specular = specular_set(shape->material.specular, line);
	line = get_next_line(fd);
	shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
	line = get_next_line(fd);
	shape->closed = close_set(line);
}

void	cone_settings(int fd, t_cone *shape, char *line)
{
	line = get_next_line(fd);
	shape->transformation = diameter_set(shape->transformation, line, 'c');
	line = get_next_line(fd);
	shape->transformation = coordinate_set(shape->transformation, line, fd);
	line = get_next_line(fd);
	set_max(&shape->min, &shape->max, line);
	line = get_next_line(fd);
	shape->material.color = color_set(line);
	line = get_next_line(fd);
	shape->material.reflective = reflection_set(line);
	line = get_next_line(fd);
	shape->material.transparency = transparency_set(line);
	line = get_next_line(fd);
	shape->material.refractive_index = refractive_set(line);
	line = get_next_line(fd);
	pattern_set(&shape->material, line, fd, FALSE);
	line = get_next_line(fd);
	shape->material.specular = specular_set(shape->material.specular, line);
	line = get_next_line(fd);
	shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
	line = get_next_line(fd);
	shape->closed = close_set(line);
}

void	sphere_settings(int fd, t_sphere *shape, char *line)
{
	line = get_next_line(fd);
	shape->transformation = diameter_set(shape->transformation, line, 's');
	line = get_next_line(fd);
	shape->transformation = coordinate_set(shape->transformation, line, fd);
	line = get_next_line(fd);
	shape->material.color = color_set(line);
	line = get_next_line(fd);
	shape->material.reflective = reflection_set(line);
	line = get_next_line(fd);
	shape->material.transparency = transparency_set(line);
	line = get_next_line(fd);
	shape->material.refractive_index = refractive_set(line);
	line = get_next_line(fd);
	pattern_set(&shape->material, line, fd, FALSE);
	line = get_next_line(fd);
	shape->material.specular = specular_set(shape->material.specular, line);
	line = get_next_line(fd);
	shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
}

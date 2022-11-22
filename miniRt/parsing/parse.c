/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:40:29 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/22 11:47:02 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

void	ambient_make(t_world *world, int fd)
{
	char	*line;
	float	ambient_ratio;

	line = get_next_line(fd);
	ambient_ratio = max(min(float_parse(line), 1), 0);
	free(line);
	line = get_next_line(fd);
	if (!ft_strncmp(to_upper(line), "NULL", 4))
		free(line);
	else
		world->ambient_color = color_set(line);
	world->ambient_ratio = ambient_ratio;
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

t_light	*light_make(int fd)
{
	char	*line;
	t_light	*light;
	t_tuple	coordinates;
	float	brightness;

	line = get_next_line(fd);
	coordinates = tuple_set(line);
	line = get_next_line(fd);
	brightness = max(min(float_parse(line), 1), 0);
	free(line);
	line = get_next_line(fd);
	light = make_light(coordinates, \
	tuple_scalar_multiplication(color_set(line), brightness));
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (light);
}

void	camera_make(t_camera *camera, int fd)
{
	char	*line;
	t_tuple	camera_origin;
	t_tuple	up;

	line = get_next_line(fd);
	camera_origin = tuple_set(line);
	line = get_next_line(fd);
	up = make_tuple(0, 1, 0, VECTOR);
	if (ft_strncmp(to_upper(line), "NULL", 4))
		up = tuple_set(line);
	line = get_next_line(fd);
	*camera = make_camera(WINDOW_WIDTH, WINDOW_HEIGHT, fov_set(line));
	set_camera_transformation(camera, camera_origin, \
		make_tuple(0, 1, 0, POINT), up);
	line = get_next_line(fd);
	while (line && ft_strncmp(line, "END", 3))
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	make_scene(t_camera *camera, t_object **objects, char *line, int fd)
{
	if (!ft_strncmp(line, "camera", 6))
		camera_make(camera, fd);
	else if (!ft_strncmp(line, "sphere", 6))
		add_object(objects, create_object(SPHERE, sphere_make(fd)));
	else if (!ft_strncmp(line, "plane", 5))
		add_object(objects, create_object(PLANE, plane_make(fd)));
	else if (!ft_strncmp(line, "cylinder", 8))
		add_object(objects, create_object(CYLINDER, cylinder_make(fd)));
	else if (!ft_strncmp(line, "cone", 4))
		add_object(objects, create_object(CONE, cone_make(fd)));
	else if (!ft_strncmp(line, "cube", 4))
		add_object(objects, create_object(CUBE, cube_make(fd)));
}

void	parse_file(t_world *world, t_camera *camera, int fd)
{
	char		*line;
	t_object	*objects;
	t_light		*lights;

	lights = NULL;
	line = NULL;
	objects = NULL;
	world->ambient_color = make_color(-1, -1, -1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!ft_strncmp(line, "light", 5))
			add_light(&lights, light_make(fd));
		else if (!ft_strncmp(line, "ambient", 6))
			ambient_make(world, fd);
		else
			make_scene(camera, &objects, line, fd);
		free (line);
	}
	printf("parsing done\n");
	world->objects = objects;
	world->light = lights;
}

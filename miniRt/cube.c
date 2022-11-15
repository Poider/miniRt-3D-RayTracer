/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:13 by mel-amma          #+#    #+#             */
/*   Updated: 2022/11/15 17:54:39 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRt.h"




static void swap(t_cube_min_max *var)
{
    float temp;
    temp = var->min;
    var->min = var->max;
    var->max = temp;
}

t_cube_min_max check_axis(float origin, float direction)
{
    float low_line_numenator;
    float top_line_numenator;
    t_cube_min_max ret;
    
    low_line_numenator = -1 - origin;
    top_line_numenator =  1 - origin;
    if(fabs(direction) >= EPSILON)
    {
        ret.min = low_line_numenator/direction;
        ret.max = top_line_numenator/direction;
    }
    else
    {
        ret.min = low_line_numenator * INFINITY;
        ret.max = top_line_numenator * INFINITY;
    }
    if(ret.min > ret.max)
        swap(&ret);
    return ret;
}

t_intersections	*intersect_cube(t_object *shape, t_ray ray)
{
    t_equations_vars	vars;
	t_intersections		*head_intersections;
    t_cube_min_max      ret;
    t_cube_intersects   minmax_vars;

	head_intersections = NULL;
    ret = check_axis(ray.origin.x,ray.direction.x);
    minmax_vars.x_min = ret.min;
    minmax_vars.x_max = ret.max;

    ret = check_axis(ray.origin.y,ray.direction.y);
    minmax_vars.y_min = ret.min;
    minmax_vars.y_max = ret.max;

    ret = check_axis(ray.origin.z,ray.direction.z);
    minmax_vars.z_min = ret.min;
    minmax_vars.z_max = ret.max;
    
    ret.min = max(minmax_vars.x_min,max(minmax_vars.y_min,minmax_vars.z_min));
    ret.max = min(minmax_vars.x_max,min(minmax_vars.y_max,minmax_vars.z_max));
    if(ret.min > ret.max)
        return NULL;
    add_intersection(&head_intersections, intersection(ret.min, shape));
    add_intersection(&head_intersections, intersection(ret.max, shape));
    return head_intersections;
}


t_tuple cube_normal(t_object *shape, t_tuple object_point)
{
    t_cube *cube;
    float maximum;

    cube = (t_cube *)shape->object;
    maximum = max(max(fabs(object_point.x),fabs(object_point.y)),fabs(object_point.z));
    if(maximum == fabs(object_point.x))
    return make_tuple(object_point.x,0,0,VECTOR);
    else if(maximum == fabs(object_point.y))
    return make_tuple(0,object_point.y,0,VECTOR);
    else
    return make_tuple(0,0,object_point.z,VECTOR);
}




void	init_cube_attr(t_object *shape, \
		t_matrices **transform, t_material *material)
{
	t_cube	*cube;

	cube = (t_cube *)shape->object;
	*transform = cube->transformation;
	*material = cube->material;
	shape->local_normal_at = cube_normal;
	shape->local_intersect = intersect_cube;
}

t_cube	*_cube_(void)
{
	t_cube	*cube;

	cube = malloc(sizeof(t_cube));
	cube->origin = origin();
	cube->transformation = identity_matrix(DEFAULT_DIMENSION);

	cube->material = make_material();
	return (cube);
}

t_object	*cube_make(int fd)
{
	char	*line;
	t_cube	*shape;

	line = NULL;

	shape = _cube_();

	cube_settings(fd, shape, line);
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


void	cube_settings(int fd, t_cube *shape, char *line)
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

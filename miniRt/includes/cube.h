/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:12:23 by mel-amma          #+#    #+#             */
/*   Updated: 2022/11/15 17:21:11 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _cube
#define _cube
#include "miniRt.h"

typedef struct s_cube
{
	t_tuple		origin;
	t_matrices	*transformation;
	t_matrices	*inverse_transformation;
	t_material	material;
}				t_cube;


typedef struct s_cube_intersects
{
    float x_min;
    float x_max;
    float y_min;
    float y_max;
    float z_min;
    float z_max;

}               t_cube_intersects;

typedef struct s_cube_min_max
{
    float min;
    float max;
}               t_cube_min_max;


t_cube_min_max check_axis(float origin, float direction);
t_intersections	*intersect_cube(t_object *shape, t_ray ray);
t_tuple cube_normal(t_object *shape, t_tuple object_point);
void	init_cube_attr(t_object *shape, \
		t_matrices **transform, t_material *material);
t_cube	*_cube_(void);
t_object	*cube_make(int fd);
void	cube_settings(int fd, t_cube *shape, char *line);



#endif
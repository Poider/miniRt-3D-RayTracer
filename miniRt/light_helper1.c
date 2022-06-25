/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_helper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:55:30 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:58:43 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

typedef struct s_lighting_vars
{
	t_tuple	diffuse;
	t_tuple	specular;
	t_tuple	effective_color;
	t_tuple	color;
	t_tuple	ambient;
	t_tuple	lightv;
	float	light_dot_normal;
	t_tuple	negate_lightv;
	t_tuple	reflectv;
	float	reflect_dot_eye;
	float	factor;
}				t_lighting_vars;

void	set_ambient_light(t_lighting_vars *vars, \
	t_world world, t_light *light, t_precomputed comps)
{
	if (comps.material.pattern)
		vars->color = pattern_at_shape(comps.object->material.pattern, \
									comps.over_point, comps.object);
	else
		vars->color = comps.material.color;
	vars->effective_color = multiply_color(vars->color, light->intensity);
	vars->lightv = tuple_normalize(substract_tuple(light->position, \
									comps.over_point));
	if (tuple_isequal(world.ambient_color, make_color(-1, -1, -1)))
		vars->ambient = tuple_scalar_multiplication(vars->effective_color, \
													comps.material.ambient);
	else
		vars->ambient = tuple_scalar_multiplication(world.ambient_color, \
													world.ambient_ratio);
	vars->light_dot_normal = dot_product(vars->lightv, comps.normalv);
}

void	set_diffuse_specular_light(t_lighting_vars *vars, \
				t_world world, t_light *light, t_precomputed comps)
{
	vars->diffuse = tuple_scalar_multiplication(tuple_scalar_multiplication(\
		vars->effective_color, comps.material.diffuse), vars->light_dot_normal);
	vars->negate_lightv = negate_tuple(vars->lightv);
	vars->reflectv = reflect(vars->negate_lightv, comps.normalv);
	vars->reflect_dot_eye = dot_product(vars->reflectv, comps.eyev);
	if (vars->reflect_dot_eye < 0)
		vars->specular = black();
	else
	{
		vars->factor = pow(vars->reflect_dot_eye, comps.material.shininess);
		vars->specular = tuple_scalar_multiplication(light->intensity, \
			comps.material.specular * vars->factor);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:41:51 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/08 15:57:02 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRt.h"

t_tuple	lighting(t_world world, t_light *light, \
				t_precomputed comps, int is_shadow)
{
	t_lighting_vars	vars;

	set_ambient_light(&vars, world, light, comps);
	if (vars.light_dot_normal < 0 || is_shadow == TRUE)
	{
		vars.diffuse = black();
		vars.specular = black();
	}
	else
		set_diffuse_specular_light(&vars, world, light, comps);
	return (add_tuple(add_tuple(vars.ambient, \
				vars.diffuse), vars.specular));
}

t_tuple	color_at(t_world world, t_ray ray, int max_depth)
{
	t_intersections	*list_intersections;
	t_intersections	*hit_intersection;
	t_precomputed	comps;

	list_intersections = NULL;
	list_intersections = intersect_word(world, ray);
	hit_intersection = hit(list_intersections);
	if (hit_intersection)
	{
		comps = prepare_computations(hit_intersection, ray, list_intersections);
		free_list_intersection(list_intersections);
		return (shade_hit(world, comps, max_depth));
	}
	free_list_intersection(list_intersections);
	return (black());
}

t_tuple	reflected_color(t_world world, t_precomputed comps, int max_depth)
{
	t_ray	reflected_ray;
	t_tuple	color;
	t_tuple	res_color;

	if (is_equal(comps.object->material.reflective, 0.00) || \
				max_depth >= MAX_DEPTH)
		return (black());
	reflected_ray = make_ray(comps.over_point, comps.reflecv);
	color = color_at(world, reflected_ray, max_depth);
	res_color = tuple_scalar_multiplication(color, \
		comps.object->material.reflective);
	return (res_color);
}

t_tuple	refracted_color(t_world world, t_precomputed comps, int max_depth)
{
	t_refrection_vars	vars;
	t_tuple				color;

	if (is_equal(comps.object->material.transparency, 0.00) || \
					max_depth >= MAX_DEPTH)
		return (black());
	vars.n_ratio = comps.n1 / comps.n2;
	vars.cos_i = dot_product(comps.eyev, comps.normalv);
	vars.sin2_t = (vars.n_ratio * vars.n_ratio) * (1 - vars.cos_i * vars.cos_i);
	if (vars.sin2_t > 1)
		return (black());
	vars.cos_t = sqrt(1.0 - vars.sin2_t);
	vars.direction = substract_tuple(tuple_scalar_multiplication(comps.normalv, \
		(vars.n_ratio * vars.cos_i - vars.cos_t)), \
		tuple_scalar_multiplication(comps.eyev, vars.n_ratio));
	vars.refracted_ray = make_ray(comps.under_point, vars.direction);
	return (tuple_scalar_multiplication(color_at(world, vars.refracted_ray, \
			max_depth), comps.object->material.transparency));
}

t_tuple	shade_hit(t_world world, t_precomputed comps, int max_depth)
{
	t_shade_hit_vars	vars;

	vars.c_surface = black();
	vars.curr_light = world.light;
	while (vars.curr_light)
	{
		vars.c_surface = add_tuple(vars.c_surface, lighting(world, \
		vars.curr_light, comps, is_shadowed(&world, \
		vars.curr_light, comps.over_point)));
		vars.curr_light = vars.curr_light->next;
	}
	vars.c_reflection = reflected_color(world, comps, max_depth + 1);
	vars.c_refraction = refracted_color(world, comps, max_depth + 1);
	if (comps.object->material.reflective > 0 && \
			comps.object->material.transparency > 0)
	{
		vars.reflectance = schlick(&comps);
		return (add_tuple(add_tuple(vars.c_surface, \
		tuple_scalar_multiplication(vars.c_reflection, vars.reflectance)), \
		tuple_scalar_multiplication(vars.c_refraction, 1 - vars.reflectance)));
	}
	return (add_tuple(add_tuple(vars.c_surface, vars.c_reflection), \
		vars.c_refraction));
}

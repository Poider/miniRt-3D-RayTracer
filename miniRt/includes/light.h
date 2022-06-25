/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:29:42 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 12:15:33 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "miniRt.h"

typedef struct s_light
{
	t_tuple			intensity;
	t_tuple			position;
	struct s_light	*next;
}					t_light;

typedef struct s_world			t_world;

typedef struct s_precomputed	t_precomputed;

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

typedef struct s_refrection_vars
{
	t_ray	refracted_ray;
	t_tuple	direction;
	float	n_ratio;
	float	cos_i;
	float	sin2_t;
	float	cos_t;
}				t_refrection_vars;

typedef struct s_shade_hit_vars
{
	t_tuple	c_surface;
	t_tuple	c_reflection;
	t_tuple	c_refraction;
	t_light	*curr_light;
	float	reflectance;
}				t_shade_hit_vars;

t_light	*make_light(t_tuple position, t_tuple intensity);
void	add_light(t_light **lights, t_light *new_light);
t_light	*get_last_light(t_light *objects);
t_tuple	reflect(t_tuple in, t_tuple normal);
t_tuple	reflected_color(t_world world, t_precomputed comps, int max_depth);
t_tuple	shade_hit(t_world world, t_precomputed comps, int max_depth);
t_tuple	lighting(t_world world, t_light *light, \
				t_precomputed comps, int is_shadow);

#endif
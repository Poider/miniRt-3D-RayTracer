/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:31:35 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:32:44 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "miniRt.h"

typedef struct s_pattern	t_pattern;

typedef struct s_material
{
	t_tuple		color;
	t_tuple		ambient_color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
	float		reflective;
	float		transparency;
	float		refractive_index;
	t_pattern	*pattern;
}				t_material;

t_material	make_material(void);
void		set_material_pattern(t_material *material, t_pattern *pattern);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomputed.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:52:17 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 16:01:36 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRECOMPUTED_H
# define PRECOMPUTED_H

# include "miniRt.h"

typedef struct s_precomputed
{
	float		t;
	t_object	*object;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		under_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		reflecv;
	int			is_inside;
	float		n1;
	float		n2;
	t_material	material;
}			t_precomputed;

# define VACUUM 1.0

t_precomputed	prepare_computations(t_intersections *intersection, \
						t_ray ray, t_intersections *list_intersections);
t_material		get_material_object(t_object shape);
float			schlick(t_precomputed *pre_computed);

#endif
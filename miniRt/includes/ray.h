/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:53:49 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:53:49 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "miniRt.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}		t_ray;

t_ray	make_ray(t_tuple origin, t_tuple direction);
t_tuple	ray_position(t_ray ray, float distance);
t_ray	transform_ray(t_ray ray, t_matrices matrix);

#endif
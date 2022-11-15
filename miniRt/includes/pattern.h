/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:48:56 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/14 18:35:06 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_H
# define PATTERN_H

# include "miniRt.h"

# define STRIPE_PATTERN 1
# define GRADIENT_PATTERN 2
# define RING_PATTERN 3
# define CHECKERBORAD_PATTERN 4

typedef struct s_pattern	t_pattern;

typedef t_tuple				(*t_pattern_at)(t_pattern *pattern, t_tuple point);

typedef struct s_pattern
{
	t_tuple			color_a;
	t_tuple			color_b;
	int				type_pattern;
	t_matrices		*transformation;
	t_matrices		*inverse_transformation;
	int				is_3d;
	t_pattern_at	local_pattern_at;
}					t_pattern;

t_pattern	*make_pattern(t_tuple white, t_tuple black, \
					int type_pattern, int is_3d);
void		set_local_pattern_function(t_pattern *pattern);
void		set_transformation_pattern(t_pattern *pattern, t_matrices *matrix);
t_tuple		pattern_at_shape(t_pattern *pattern, \
						t_tuple point, t_object *shape);
t_tuple		stripe_at(t_pattern *pattern, t_tuple point);
t_tuple		gradien_at(t_pattern *pattern, t_tuple point);
t_tuple		ring_at(t_pattern *pattern, t_tuple point);
t_tuple		checkerbord_at(t_pattern *pattern, t_tuple point);

#endif
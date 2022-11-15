/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:43:20 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 17:08:50 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "miniRt.h"

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CONE 4
# define CUBE 5

typedef struct s_object			t_object;
typedef struct s_intersections	t_intersections;
typedef t_tuple					(*t_normal_vec)(t_object *shape, \
									t_tuple world_point);
typedef t_intersections			*(*t_intersect)(t_object *shape, t_ray ray);

typedef struct s_object
{
	int				type_object;
	void			*object;
	t_matrices		*transformation;
	t_matrices		*inverse_transformation;
	t_material		material;
	t_normal_vec	local_normal_at;
	t_intersect		local_intersect;
	struct s_object	*next;
}			t_object;

void			set_material(t_object *object, t_material material);
void			set_tranform(t_object *object, t_matrices *matrix);
void			init_object_attr(int type_object, t_object *obj);
t_object		*get_last_object(t_object *objects);
t_intersections	*get_prev_object(t_intersections *list, t_object *object);
void			add_object(t_object **objects, t_object *new_object);
t_object		*create_object(int type_object, void *object);
int				get_number_objects(t_object *objects);
t_tuple			normal_at(t_object *shape, t_tuple world_point);

#endif
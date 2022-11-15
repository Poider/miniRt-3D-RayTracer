/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precomputed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:15:58 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/08 15:59:21 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	set_n1(t_precomputed *pre_computed, t_intersections *hit, \
				t_intersections *list, t_intersections *containers)
{
	if (hit == list)
	{
		if (containers == NULL)
			pre_computed->n1 = VACUUM;
		else
			pre_computed->n1 = get_last_intersection(\
				containers)->object->material.refractive_index;
	}
}

void	set_n2(t_precomputed *pre_computed, t_intersections *hit, \
				t_intersections *list, t_intersections *containers)
{
	if (containers == NULL)
		pre_computed->n2 = VACUUM;
	else
		pre_computed->n2 = get_last_intersection(\
			containers)->object->material.refractive_index;
}

int	remove_object(t_intersections **list, t_intersections **containers)
{
	t_intersections	*prev_object;
	t_intersections	*tmp;

	prev_object = NULL;
	prev_object = get_prev_object(*containers, (*list)->object);
	if (prev_object)
	{
		if ((*containers)->next == NULL)
		{
			free((*containers));
			*containers = NULL;
		}
		else
		{
			tmp = prev_object->next;
			prev_object->next = prev_object->next->next;
			free(tmp);
		}
		return (SUCCESS);
	}
	return (FAIL);
}

void	set_refractives_idx(t_precomputed *pre_computed, \
			t_intersections *hit, t_intersections *list)
{
	t_intersections	*containers;
	t_intersections	*prev_object;

	containers = NULL;
	prev_object = NULL;
	while (list)
	{
		set_n1(pre_computed, hit, list, containers);
		if (remove_object(&list, &containers) == FAIL)
			add_intersection(&containers, intersection(list->t, list->object));
		if (hit == list)
		{
			set_n2(pre_computed, hit, list, containers);
			break ;
		}		
		list = list ->next;
	}
	free_list_intersection(containers);
}

t_precomputed	prepare_computations(t_intersections *intersection, \
				t_ray ray, t_intersections *list_intersections)
{
	t_precomputed	pre_computed;
	t_tuple			epsilon_normal;

	pre_computed.t = intersection->t;
	pre_computed.point = ray_position(ray, pre_computed.t);
	pre_computed.object = intersection->object;
	pre_computed.eyev = negate_tuple(ray.direction);
	pre_computed.normalv = normal_at(intersection->object, pre_computed.point);
	if (dot_product(pre_computed.normalv, pre_computed.eyev) < 0)
	{
		pre_computed.is_inside = TRUE;
		pre_computed.normalv = negate_tuple(pre_computed.normalv);
	}
	else
		pre_computed.is_inside = FALSE;
	pre_computed.reflecv = reflect(ray.direction, pre_computed.normalv);
	pre_computed.material = intersection->object->material;
	epsilon_normal = tuple_scalar_multiplication(pre_computed.normalv, EPSILON);
	pre_computed.over_point = add_tuple(pre_computed.point, epsilon_normal);
	pre_computed.under_point = substract_tuple(pre_computed.point, \
												epsilon_normal);
	pre_computed.over_point.w = POINT;
	set_refractives_idx(&pre_computed, intersection, list_intersections);
	return (pre_computed);
}

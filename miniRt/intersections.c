/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:32:12 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/08 15:45:44 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	add_intersection(t_intersections **intersections, \
						t_intersections *new_intersection)
{
	t_intersections	*temp;

	if (!intersections)
		return ;
	if (*intersections == NULL)
		*intersections = new_intersection;
	else
	{
		temp = get_last_intersection(*intersections);
		temp->next = new_intersection;
	}
}

t_intersections	*get_new_intetsection(float t, t_object *shape)
{
	t_intersections	*node;

	node = malloc(sizeof(t_intersections));
	if (!node)
		return (NULL);
	node->t = t;
	node->object = shape;
	node->next = NULL;
	return (node);
}

t_intersections	*intersect_word(t_world world, t_ray ray)
{
	t_intersections	*list_intersections;
	t_ray			transformed_ray;
	t_object		*object_iter;

	list_intersections = NULL;
	object_iter = world.objects;
	while (object_iter)
	{
		transformed_ray = transform_ray(ray, \
				*object_iter->inverse_transformation);
		if (list_intersections == NULL)
			list_intersections = \
			object_iter->local_intersect(object_iter, transformed_ray);
		else
			add_intersection(&list_intersections, \
			object_iter->local_intersect(object_iter, transformed_ray));
		object_iter = object_iter->next;
	}
	sort_intersectios(list_intersections);
	return (list_intersections);
}

t_intersections	*intersection(float t, t_object *shape)
{
	return (get_new_intetsection(t, shape));
}

t_intersections	*hit(t_intersections *l_intersections)
{
	while (l_intersections)
	{
		if (l_intersections->t >= EPSILON)
			return (l_intersections);
		l_intersections = l_intersections->next;
	}
	return (0);
}

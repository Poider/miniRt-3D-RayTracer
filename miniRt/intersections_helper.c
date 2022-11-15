/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:36:42 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/04 21:29:27 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_intersections	*get_last_intersection(t_intersections *intersections)
{
	t_intersections	*temp;

	if (!intersections)
		return (NULL);
	temp = intersections;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	sort_intersectios(t_intersections *list_intersections)
{
	t_intersections	*curr;
	t_intersections	*next_node;
	t_object		*obj_tmp;
	float			tmp;

	curr = list_intersections;
	while (curr)
	{
		next_node = curr->next;
		while (next_node)
		{
			if (is_greater(curr->t, next_node->t))
			{
				obj_tmp = curr->object;
				tmp = curr->t;
				curr->t = next_node->t;
				curr->object = next_node->object;
				next_node->t = tmp;
				next_node->object = obj_tmp;
			}
			next_node = next_node->next;
		}
		curr = curr->next;
	}
}

int	get_size_intersections(t_intersections *intersections)
{
	t_intersections	*temp;
	int				countnode;

	countnode = 0;
	temp = intersections;
	while (temp)
	{
		temp = temp->next;
		countnode += 1;
	}
	return (countnode);
}

void	free_list_intersection(t_intersections *list_intersections)
{
	t_intersections	*tmp;

	tmp = list_intersections;
	while (tmp)
	{
		list_intersections = tmp->next;
		free(tmp);
		tmp = list_intersections;
	}
}

t_intersections	*get_prev_object(t_intersections *list, t_object *object)
{
	t_intersections	*prev;

	if (list == NULL)
		return (NULL);
	prev = list;
	while (list)
	{
		if (list->object == object)
			return (prev);
		prev = list;
		list = list->next;
	}
	return (0);
}

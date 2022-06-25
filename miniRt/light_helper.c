/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:42:24 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 11:44:07 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_light	*make_light(t_tuple position, t_tuple intensity)
{
	t_light	*point_light;

	point_light = malloc(sizeof(t_light));
	point_light->position = position;
	point_light->intensity = intensity;
	point_light->next = NULL;
	return (point_light);
}

void	add_light(t_light **lights, t_light *new_light)
{
	t_light	*temp;

	if (!lights)
		return ;
	if (*lights == NULL)
		*lights = new_light;
	else
	{
		temp = get_last_light(*lights);
		temp->next = new_light;
	}
}

t_light	*get_last_light(t_light *objects)
{
	t_light	*temp;

	if (!objects)
		return (NULL);
	temp = objects;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	float	in_normal_dot;

	in_normal_dot = dot_product(in, normal);
	return (tuple_normalize((substract_tuple(in, \
			tuple_scalar_multiplication(normal, 2 * in_normal_dot)))));
}

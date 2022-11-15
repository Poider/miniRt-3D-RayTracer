/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:35:14 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 16:44:42 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

void	free_objects(t_object *objects)
{
	t_object	*next;

	next = objects ->next;
	while (objects)
	{
		free_matrix(objects->inverse_transformation);
		free_matrix(objects->transformation);
		if (objects->material.pattern)
		{
			free_matrix(objects->material.pattern->transformation);
			free_matrix(objects->material.pattern->inverse_transformation);
			free(objects->material.pattern);
		}
		free(objects->object);
		next = objects ->next;
		free(objects);
		objects = next;
	}
}

void	free_lights(t_light *lights)
{
	t_light	*next_light;

	next_light = lights ->next;
	while (lights)
	{
		next_light = lights ->next;
		free(lights);
		lights = next_light;
	}
}

void	free_camera(t_camera *camera)
{
	free_matrix(camera->transform);
	free_matrix(camera->inverse_transform);
}

void	free_ressource(t_world *world, t_camera *camera)
{
	free_objects(world->objects);
	free_lights(world->light);
	free_camera(camera);
}

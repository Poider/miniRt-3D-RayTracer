/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:33:27 by klaarous          #+#    #+#             */
/*   Updated: 2022/11/15 15:37:43 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

int	len(char **line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	parse_error(void)
{
	printf("parse error\n");
	exit(1);
}

void	free_split(char **vector)
{
	int	i;

	i = 0;
	while (vector[i])
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}

float	degree_to_radian(float angle)
{
	return (angle * (M_PI / 180));
}

float	float_parse(char *line)
{
	if (!line)
		return (0.0f);
	return (atof(line));
}

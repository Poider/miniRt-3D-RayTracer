/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:32:18 by klaarous          #+#    #+#             */
/*   Updated: 2022/07/05 15:48:34 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/miniRt.h"

int	close_set(char *line)
{
	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (TRUE);
	}
	if (!ft_strncmp(to_upper(line), "TRUE", 4))
	{
		free(line);
		return (TRUE);
	}
	free(line);
	return (FALSE);
}

t_tuple	tuple_from_line(char *line)
{
	char	**vector;
	t_tuple	_tuple;

	vector = ft_split(line, ',');
	_tuple.x = float_parse(vector[0]);
	_tuple.y = float_parse(vector[1]);
	_tuple.z = float_parse(vector[2]);
	if (vector[3])
	{
		if (!ft_strncmp(to_upper(vector[3]), "POINT", 5))
			_tuple.w = POINT;
		else
			_tuple.w = VECTOR;
	}
	free_split(vector);
	return (_tuple);
}

t_tuple	tuple_set(char *line)
{
	char	**vector;
	t_tuple	_tuple;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (make_tuple(0, 0, -1, POINT));
	}
	vector = ft_split(line, ',');
	_tuple.x = float_parse(vector[0]);
	_tuple.y = float_parse(vector[1]);
	_tuple.z = float_parse(vector[2]);
	if (vector[3])
	{
		if (!ft_strncmp(to_upper(vector[3]), "POINT", 5))
			_tuple.w = POINT;
		else
			_tuple.w = VECTOR;
	}
	free_split(vector);
	free(line);
	return (_tuple);
}

float	fov_set(char *line)
{
	float	fov;

	if (!ft_strncmp(to_upper(line), "NULL", 4))
	{
		free(line);
		return (M_PI / 2);
	}
	fov = degree_to_radian(float_parse(line));
	free(line);
	return (fov);
}

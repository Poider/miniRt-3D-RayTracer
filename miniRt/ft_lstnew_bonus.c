/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:23:30 by klaarous          #+#    #+#             */
/*   Updated: 2022/04/23 05:15:49 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_intersections	*ft_lstnew(float t, void *object)
{
	t_intersections	*node;

	node = malloc(sizeof(t_intersections));
	if (!node)
		return (NULL);
	node -> t = t;
	node ->object = object;
	node -> next = NULL;
	return (node);
}

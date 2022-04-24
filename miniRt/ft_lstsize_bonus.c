/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:53:41 by klaarous          #+#    #+#             */
/*   Updated: 2022/04/22 13:39:44 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

int	ft_lstsize(t_intersections *lst)
{
	t_intersections	*temp;
	int		countnode;

	countnode = 0;
	temp = lst;
	while (temp)
	{
		temp = temp -> next;
		countnode += 1;
	}
	return (countnode);
}

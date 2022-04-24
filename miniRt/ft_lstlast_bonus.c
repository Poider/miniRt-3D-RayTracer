/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:31:39 by klaarous          #+#    #+#             */
/*   Updated: 2022/04/22 13:40:50 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/miniRt.h"

t_intersections	*ft_lstlast(t_intersections *lst)
{
	t_intersections	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}

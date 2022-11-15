/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:18:38 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 15:53:07 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "miniRt.h"

t_tuple	make_color(float red, float green, float blue);
t_tuple	black(void);
t_tuple	white(void);
int		get_color(t_tuple color);
t_tuple	multiply_color(t_tuple c1, t_tuple c2);

#endif
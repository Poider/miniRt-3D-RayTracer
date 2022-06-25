/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:32:56 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 10:32:56 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include "miniRt.h"

# define MAX_INT 2147483647

typedef struct s_equations_vars
{
	float	a;
	float	b;
	float	c;
	float	determinant;
	float	sol1;
	float	sol2;
}				t_equations_vars;

int		is_equal(float a, float b);
float	abs_float(float x);
int		is_pos(int a);
int		is_greater(float a, float b);
int		is_lesser(float a, float b);
float	min(float a, float b);
float	max(float a, float b);
float	negate_val(float a);

#endif
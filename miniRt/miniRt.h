/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:34:48 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/03 17:44:52 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef miniRt_H
# define miniRt_H


# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080


typedef struct s_parameters //has map + image infos
{
	void	*mlx_ptre;
	void	*win_ptre;
	void	*img_ptre;

	int		width;
	int		height;
	char	*address;
	int		endian;
	int		bitsperpixel;
	int		linesize;
}			t_parameters;

#endif
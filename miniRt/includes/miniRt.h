/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaarous <klaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:35:15 by klaarous          #+#    #+#             */
/*   Updated: 2022/06/25 16:06:59 by klaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define TRUE 1
# define FALSE 0
# define VECTOR 0
# define POINT 1
# define SUCCESS 1
# define FAIL 0

# define MAX_DEPTH 5

# include "../gnl/get_next_line.h"
# include "tuples.h"
# include "matrices.h"
# include "math_utils.h"
# include "color.h"
# include "material.h"
# include "ray.h"
# include "object.h"
# include "light.h"
# include "pattern.h"
# include "world.h"
# include "intersections.h"
# include "precomputed.h"
# include "sphere.h"
# include "plane.h"
# include "cylinder.h"
# include "cone.h"
# include "shading.h"
# include "camera.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "settings.h"
# include "parse.h"

# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 1200
# define COLOR 111111222
# define EPSILON 0.001
# define EPSILON1 0.00001818181
# define MARGIN 1

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	color;
}			t_point;

typedef struct s_data
{
	char		**ambient_light;
	char		**camera;
	char		**light;
	t_object	*obj;
}				t_data;

typedef struct s_parameters
{
	void		*mlx_ptre;
	void		*win_ptre;
	void		*img_ptre;
	int			width;
	int			height;
	char		*address;
	int			endian;
	int			bitsperpixel;
	int			linesize;
	t_camera	camera;
	int			object_id;
	t_data		*data;
}				t_parameters;

// helpers
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		white_spaces(char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*to_upper(char *line);
int		ft_toupper(int a);
// drawing functions

void	plot(int x, int y, t_tuple color);
void	image_pixel_put(t_parameters *param, \
				t_point point, int color);
#endif
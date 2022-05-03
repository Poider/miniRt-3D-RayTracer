/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ./includes/miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:34:48 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/04 17:00:00 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef miniRt_H
#define miniRt_H


#define TRUE 1
#define FALSE 0
#define VECTOR 0
#define POINT 1

#include "../gnl/get_next_line.h"
#include "tuples.h"
#include "matrices.h"
#include "math_utils.h"
#include "color.h"
#include "light.h"
#include "material.h"
#include "sphere.h"
#include "ray.h"
#include "shading.h"
#include "intersections.h"
#include "mlx.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define COLOR 111111222
#define EPSILON 0.001
#define MARGIN 1

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	color;
}				t_point;

typedef struct	s_object // convert objects to equations and when you need to check if light hits there check if pixels on screen hit any equation
{
	char	**object;
	struct	s_object *next;
}				t_object;

typedef struct	s_data
{
	char **ambient_light; // ambient light and its args
	char **camera;		  // camera and its args
	char **light;		  // light and its args

	// you can split each arg of those with ',' and atoi it to get the stuff you need
	t_object *obj; // first object address
} 				t_data;

typedef struct	s_parameters // has map + image infos
{
	void *mlx_ptre;
	void *win_ptre;
	void *img_ptre;

	int width;
	int height;
	char *address;
	int endian;
	int bitsperpixel;
	int linesize;


	int object_id;//first object will be 1 on id
	t_data *data;
}				t_parameters;

// helpers
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		whitespaces(char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
t_intersections	*ft_lstlast(t_intersections *lst);
void	ft_lstadd_back(t_intersections **lst, t_intersections *new);
t_intersections	*ft_lstnew(float t, void *object);
int	ft_lstsize(t_intersections *lst);


//drawing functions

void plot(int x,int y,t_tuple color);
void	image_pixel_put(t_parameters *param, t_point point, int color);
#endif
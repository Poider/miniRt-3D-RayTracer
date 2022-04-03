/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:34:48 by mel-amma          #+#    #+#             */
/*   Updated: 2022/04/03 22:36:48 by mel-amma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef miniRt_H
#define miniRt_H

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

typedef struct	s_object // convert objects to equations and when you need to check if light hits there check if pixels on screen hit any equation
{
	char **object;
	s_objects next;
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

	t_data *data;
}				t_parameters;

// helpers
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		whitespaces(char c);
char	**ft_split(char const *s, char c);

#endif
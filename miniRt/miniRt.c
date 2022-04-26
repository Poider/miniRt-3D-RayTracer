// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   miniRt.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-amma <mel-amma@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/04/03 17:34:33 by mel-amma          #+#    #+#             */
// /*   Updated: 2022/04/04 17:37:00 by mel-amma         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "./includes/miniRt.h"

t_parameters *param;

t_point	makepoint(int x, int y, int z)
{
	t_point	newpoint;

	newpoint.x = x;
	newpoint.y = y;
	newpoint.z = z;
	return (newpoint);
}

void	image_pixel_put(t_parameters *param, t_point point, int color)
{
	char	*pixel;
	int		x;
	int		y;
	int		z;

	x = point.x;
	y = point.y;
	z = point.z;
	//printf("x:%d y %d z%d\n",x,y,z);
	if (x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
	{
		// printf("check\n");
		pixel = param->address + (y * (param->linesize)
				+ x * (param->bitsperpixel) / 8);
		*(int *)pixel = COLOR;
	}
}

int exitit(int button, void *unused)
{
	button = 1;
	exit(0);
	return (0);
}

void failure_exit(char *message)
{
	// free stuff
	printf("Error\n");
	if (message)
		printf("%s\n", message);
	exit(1);
}

void put_menu(t_parameters *param)
{
	/*
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 15, 130140150, "Rotate around (x,y,z): A-W-D");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 30, 130140150, "Reverse rotate around (x,y,z): UP-RIGHT-LEFT");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 45, 130140150, "Zoom : + -");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 60, 130140150, "Shift : I-J-K-L");
	mlx_string_put(param->mlx_ptre, param->win_ptre,
		10, 75, 130140150, "Swap projection: / *");
		*/
}

void initializemlx(t_parameters *param)
{
	param->mlx_ptre = mlx_init();
	param->win_ptre = mlx_new_window(param->mlx_ptre,
									 WINDOW_WIDTH, WINDOW_HEIGHT, "mi ferst windew");

	param->img_ptre = mlx_new_image(param->mlx_ptre, WINDOW_WIDTH, WINDOW_HEIGHT);

	param->address = mlx_get_data_addr(param->img_ptre,
									   &param->bitsperpixel, &param->linesize, &param->endian);
	// TODO: make it initiaze data func
	param->object_id = 0;
}

int esc_hook(int button, void *param)
{
	if (button == 53 || button == 17)
	{
		// freestuff(hooker);
		exit(0);
	}
	return (0);
}

// char *get_first_word(char *str)
// {
// 	char *first_word;
// 	int i;

// 	i = 0;
// 	while(!whitespaces(str[i]))
// 	i++;

// 	first_word = ft_substr(str, 0, i);
// 	return first_word;
// }

t_object *get_last_object(t_object *obj)
{
	while(obj->next != 0)
		obj = obj->next;
	return obj;
}

int fill_struct(char **line)
{
	// store the array in the correct place in "data"
	// if its an object get last object then malloc a new object and initialize its next then fill it
	return 1;
}

// int parse_file(t_parameters *param, char *filename)
// {
// 	int fd;
// 	char *line;

// 	line = "get in";
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		exit(0);
// 	//malloc the struct of data and initialize stuff with null
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		// fill a struct with the stuff
// 		// do split and send to a function with ifs its one of the 3 params it stores there otherwise it stores in object
// 		free(line);
// 	}
// 	close(fd);
// 	return 1;
//}

void plot(int x,int y,int z)
{
	image_pixel_put(param,makepoint(x,y,z),0);
}

void DrawSphere(double r, int lats, int longs)
{
	int i, j;
	for (i = 0; i <= lats; i++)
	{
		double lat0 = 3.14 * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0) * r;
		double zr0 = cos(lat0) * r;

		double lat1 = 3.14 * (-0.5 + (double)i / lats);
		double z1 = sin(lat1) * r;
		double zr1 = cos(lat1) * r;

		for (j = 0; j <= longs; j++)
		{
			double lng = 2 * 3.14 * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			plot(x * zr0, y * zr0, z0);
			plot(x * zr1, y * zr1, z1);
		}
	}
}

int main(int argc, char **argv)
{
	

	// error handling

	// read the file and parse it



	// init
	param = malloc(sizeof(t_parameters));
	initializemlx(param);

	//first draw
	// printf("%s %d %d %d \n",param->address,param->endian,param->bitsperpixel,param->linesize);
	// for( int i = 0; i<500; i++) {
	// 	for (int j = 0; j< 500;j++)
	// 		image_pixel_put(param,makepoint(j,i,0),0);
	// }

	//DrawSphere(300, 400, 500);

    t_tuple camera;

    camera = make_tuple(0,0,-5,1);
    draw_sphere(camera,10);

	mlx_put_image_to_window(param->mlx_ptre,param->win_ptre,param->img_ptre,0,0);


	//make a hook each time you rotate you re render that and do the light and all recalculation

	// for all keys
	mlx_hook(param->win_ptre, 02, 0L, esc_hook, param /*(the parameter)*/);

	// for closin window
	mlx_hook(param->win_ptre, 17, 0L, exitit, param /*(the parameter)*/);

	put_menu(param);
	mlx_loop(param->mlx_ptre);

	return (0);
}

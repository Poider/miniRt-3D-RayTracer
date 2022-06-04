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

	x = point.x;
	y = point.y;
	//printf("x:%d y %d z%d\n",x,y,z);
	if (x > 0 && y > 0 && x < param->camera.hsize && y < param->camera.vsize)
	{
		// printf("check\n");
		pixel = param->address + (y * (param->linesize)
				+ x * (param->bitsperpixel) / 8);
		*(int *)pixel = color;
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
									  param->camera.hsize, param->camera.vsize, "mi ferst windew");

	param->img_ptre = mlx_new_image(param->mlx_ptre, param->camera.hsize, param->camera.vsize);

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

void plot(int x,int y,t_tuple color)
{
	image_pixel_put(param,makepoint(x,y,0),get_color(color));
}

void	render(t_camera camera, t_world world)
{
	int y;
    int x;
    
    y = 0;
    while (y < camera.vsize)
    {
        x = 0;
        while (x < camera.hsize)
        {
			t_ray ray = ray_for_pixel(camera, x, y);
			plot(x,y,color_at(world,ray,0));
            x++;
        }
        y++;
    }
}


void create_test_scene(t_world *world)
{
	//walls
	t_plane *floor = plane();
	floor->material.color = make_color(1, 0.9, 0.9);
	floor->material.specular = 0;
	floor->material.reflective = 0;
	set_material_pattern(&floor->material,make_pattern(WHITE, BLACK, CHECKERBORAD_PATTERN, TRUE));
	set_transformation_pattern(floor->material.pattern,scaling(make_tuple(0.5,0.5,0.5,POINT)));
	//set_material_pattern(&floor->material,make_pattern(WHITE, BLACK, STRIPE_PATTERN));

	//LEFT WALL
	t_plane *left_wall = plane();
	left_wall->transformation = multiply_matrices(translation(make_tuple(0,0,5, POINT)),rotation_x(M_PI / 2));
	left_wall->material.color = make_color(1, 0.9, 0.9);
	left_wall->material.specular = 0;
	left_wall->material.reflective = 0;
	// set_material_pattern(&left_wall->material,make_pattern(make_color(0.8,0.4,0),make_color(0,0.3,0.9), RING_PATTERN, TRUE));
	// set_transformation_pattern(left_wall->material.pattern,multiply_matrices(translation(make_tuple(0,0,25,0)), scaling(make_tuple(0.2,0.2,0.2,POINT))));
	//left_wall->material.pattern = 0;
	//left_wall->material.color = make_color(1,0.9,0.7);
	set_material_pattern(&left_wall->material,make_pattern(WHITE, BLACK, CHECKERBORAD_PATTERN, TRUE));
	set_transformation_pattern(left_wall->material.pattern,scaling(make_tuple(0.2,0.2,0.2,POINT)));

	//RIGHT WALL
	t_plane *right_wall = plane();
	right_wall->transformation = multiply_matrices(translation(make_tuple(0, 0, 5,POINT)),multiply_matrices(rotation_y(M_PI/4) ,rotation_x(M_PI/2)));
	right_wall->material = floor->material;
	right_wall->material.pattern = 0;
	right_wall->material.reflective = 0;
	right_wall->material.color = make_color(0.8,0.9,0.9);
	right_wall->material.pattern = 0;


	t_sphere *middle_sphere = glass_sphere();
	middle_sphere->transformation = translation(make_tuple(-0.5, 1, 0.5,POINT));
	middle_sphere->material.color = make_color(0.9, 0.7, 0.8);
	middle_sphere->material.diffuse = 0.7;
	middle_sphere ->material.refractive_index = 1;
	//middle_sphere ->material.reflective = 0.4;
	middle_sphere ->material.transparency = 0.2;	
	middle_sphere->material.specular = 0.5;
	//middle_sphere->material.reflective = 0.3;
	// set_material_pattern(&middle_sphere->material,make_pattern(make_color(1,1,0),make_color(0,0,1) ,CHECKERBORAD_PATTERN, FALSE));
	// set_transformation_pattern(middle_sphere->material.pattern,scaling(make_tuple(0.1,0.1,0.1,VECTOR)));


	t_sphere *right_sphere = sphere();
	right_sphere->transformation = multiply_matrices(translation(make_tuple(1.5, 0.5, -0.5,POINT)) ,scaling(make_tuple(0.5, 0.5, 0.5,VECTOR)));
	right_sphere->material = make_material();
	right_sphere->material.color = make_color(0.5, 1, 0.1);
	right_sphere->material.diffuse = 0.7;
	right_sphere->material.specular = 0;
	set_material_pattern(&right_sphere->material,make_pattern(make_color(1,1,0),make_color(0,0,1) ,RING_PATTERN, TRUE));
	set_transformation_pattern(right_sphere->material.pattern,multiply_matrices(scaling(make_tuple(0.1,0.1,0.1,VECTOR)),multiply_matrices(rotation_y(45) ,rotation_x(-90))));

	t_sphere *left_sphere = sphere();
	left_sphere->transformation = multiply_matrices(translation(make_tuple (-1.5, 0.33, -0.75,POINT)) , scaling(make_tuple(0.33, 0.33, 0.33,VECTOR)));
	left_sphere->material = make_material();
	left_sphere->material.color = make_color(1, 0.8, 0.1);
	left_sphere->material.diffuse = 0.7;
	left_sphere->material.specular = 0.3;
	set_material_pattern(&left_sphere->material,make_pattern(make_color(1,0,0),make_color(0,1,0) ,GRADIENT_PATTERN, TRUE));
	set_transformation_pattern(left_sphere->material.pattern,multiply_matrices(translation(make_tuple(1,0,0,POINT)),scaling(make_tuple(2,2,2,VECTOR))));
	//set_transformation_pattern(left_sphere->material.pattern,rotation_z(M_PI / 4));

	//lighting
	world->light = make_light(make_tuple(-10, 10, -10,POINT), make_color(1, 1, 1));
	

	t_object *objects;

	objects = NULL;
	add_object(&objects,create_object(PLANE,floor));
	add_object(&objects,create_object(PLANE,left_wall));
	//add_object(&objects,create_object(PLANE,right_wall));
	add_object(&objects,create_object(SPHERE,middle_sphere));
	//add_object(&objects,create_object(SPHERE,left_sphere));
	//add_object(&objects,create_object(SPHERE,right_sphere));
	world ->objects = objects;
}	


void set_obj_inverse_transformation(t_object *objects)
{
	t_object shape;
	while (objects)
	{
		if (objects->type_object == SPHERE)
		{
			t_sphere *s = (t_sphere *)objects->object;
			s->inverse_transformation = invert_matrix(s ->transformation);
		}
		objects = objects ->next;
	}

}

int main(int argc, char **argv)
{
	

	// error handling

	// read the file and parse it



	// init
	param = malloc(sizeof(t_parameters));
	t_world world;
	create_test_scene(&world);
	//set_obj_inverse_transformation(world.objects);


	t_camera camera = make_camera(1400, 1000, M_PI / 3);
	//t_camera camera = make_camera(1500, 1000, M_PI / 2);
	//camera.transform = view_transformation(make_tuple(0, 1.5, -5,POINT),make_tuple(0, 1, 0,POINT),make_tuple(0, 1, 0,VECTOR));
	set_camera_transformation(&camera,make_tuple(0, 3,-1,POINT),make_tuple(0, 1, 0,POINT),make_tuple(0, 1, 0,VECTOR));
	
	param ->camera = camera;
	initializemlx(param);
	render(camera,world);
	

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

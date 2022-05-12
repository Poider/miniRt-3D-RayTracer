#include "./includes/miniRt.h"

t_world create_world()
{
	t_world world;

	world.light.intensity = BLACK
	world.objects = NULL;
	return (world);
}
t_world default_world()//just for test
{
	t_world world;
	t_object *objects;
	t_sphere *s1,*s2;

	objects = NULL;
	world.light = make_light(make_tuple(-10,10,-10,POINT), make_color(1,1,1));
	s1 = sphere();
	s1->material.color = make_color(0.8, 1.0, 0.6);
	s1 ->material.diffuse = 0.7;
	s1 ->material.specular = 0.2;
	add_object(&objects,create_object(SPHERE,s1));
	s2 = sphere();
	set_tranform(s2,scaling(make_tuple(0.5, 0.5, 0.5,VECTOR)));
	add_object(&objects,create_object(SPHERE,s2));
	world.objects = objects;
	return (world);
}

t_tuple color_at(t_world world, t_ray ray)
{
	t_intersections *list_intersections;
	t_intersections *hit_intersection;
	t_precomputed comps;

	list_intersections = intersect_word(world, ray);
	hit_intersection = hit(list_intersections);
	if (hit_intersection)
	{
		comps = prepare_computations(hit_intersection, ray);
		free_list_intersection(list_intersections);
		return (shade_hit(world, comps));
	}
	else
		return BLACK
}

void draw_world(t_tuple camera, float z_image_plane)
{
    int y;
    int x;
    float half,word_y,word_x;
    float pixel_size;
    float image_plane_size;
    float abs_z_camera = abs(camera.z);

    image_plane_size = (((abs_z_camera + z_image_plane)/ abs_z_camera) * 2) + MARGIN;
    pixel_size = image_plane_size / WINDOW_WIDTH;
    half = image_plane_size / 2;
    y = 0;
	t_world world = default_world();
    while (y < WINDOW_HEIGHT)
    {
        x = 0;
        word_y = half - pixel_size * y;
        while (x < WINDOW_WIDTH)
        {
            word_x = -half + pixel_size * x;
            t_tuple position = make_tuple(word_x,word_y,z_image_plane,POINT);
            t_ray ray = make_ray(camera,tuple_normalize(substract_tuple(position,camera)));
			plot(x,y,color_at(world,ray));
            x++;
        }
        y++;
    }
}

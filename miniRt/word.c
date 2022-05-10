#include "./includes/miniRt.h"

t_world create_world()
{
	t_world world;

	world.light = NULL;
	world.objects = NULL;
	return (world);
}
t_world default_world()//just for test
{
	t_world world;
	t_light *light;
	t_object *objects;
	t_sphere *s1,*s2;

	objects = NULL;
	light = malloc(sizeof(t_light));
	light->position = make_tuple(-10,10,-10,POINT);
	light ->intensity = make_color(1,1,1);
	s1 = sphere();
	s1->material.color = make_color(0.8, 1.0, 0.6);
	s1 ->material.diffuse = 0.7;
	s1 ->material.specular = 0.2;
	add_object(&objects,create_object(SPHERE,s1));
	s2 = sphere();
	set_tranform(s2,scaling(make_tuple(0.5, 0.5, 0.5,VECTOR)));
	add_object(&objects,create_object(SPHERE,s2));
	world.light =light;
	world.objects = objects;
	return (world);
}


int main()
{
	t_world world = default_world();
	// printf("intentsity : %.2f %.2f %.2f %.2f\n",world.light->position.x,world.light->position.y,world.light->position.z,world.light->position.w);
	// printf("color : %.2f %.2f %.2f %.2f\n",world.light->intensity.x,world.light->intensity.y,world.light->intensity.z,world.light->intensity.w);
	// t_sphere *s1 = (t_sphere *)world.objects ->object;
	// t_sphere *s2 = (t_sphere *)world.objects ->next ->object;
	// printf("material color : %.2f %.2f %.2f %.2f\n",s1->material.color.x,s1->material.color.y,s1->material.color.z,s1->material.color.w);
	// printf("diffuse = %.2f specular = %.2f \n",s1->material.diffuse,s1->material.specular);
	// printf("matrix : \n");
	// print_matrix(*s2 ->transformation);
	t_ray r = make_ray(make_tuple(0, 0, 0,POINT), make_tuple(0, 0, 1,VECTOR));
	t_sphere *s = sphere();
	printf("radious = %.2f\n",s ->radius);
	t_precomputed comp = prepare_computations(intersection(1,s),r);
	printf("%.2f \n",comp.t);
	//printf("object radious = %.2f\n",*(t_sphere *)comp.object->object.radious);
	printf("is_inside = %d\n",comp.is_inside);
	printf("point : %.2f %.2f %.2f %.2f\n",comp.point.x,comp.point.y,comp.point.z,comp.point.w);
	printf("eyev : %.2f %.2f %.2f %.2f\n",comp.eyev.x,comp.eyev.y,comp.eyev.z,comp.eyev.w);
	printf("noraml : %.2f %.2f %.2f %.2f\n",comp.normalv.x,comp.normalv.y,comp.normalv.z,comp.normalv.w);

	return (0);
}

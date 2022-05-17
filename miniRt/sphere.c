#include "./includes/miniRt.h"

// t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param)
// {
//     t_sphere *sphere;

//     sphere = malloc(sizeof(t_sphere));
//     sphere->origin = origin; //(0,0,0) usually (use make_tuple function to send a tuple in)
//     sphere->radius = radius;
//     param->object_id++;
//     sphere->object_id = param->object_id;
//     sphere->transformation = identity_matrix(4);
//     return sphere;
// }

t_sphere *sphere()
{
    static int object_id = 0;
    t_sphere *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->origin = make_tuple(0,0,0,1); //(0,0,0) usually (use make_tuple function to send a tuple in)
    sphere->radius = 1.0;
    object_id++;
    sphere->object_id = object_id;
    sphere->transformation = identity_matrix(DEFAULT_DIMENSION);
	sphere->material = make_material();
    return sphere;
}

void set_tranform(t_sphere *s,t_matrices *matrix)
{
    s->transformation = matrix;
}

void set_material(t_sphere *s , t_material material)
{
    s ->material = material;
}

t_intersections *intersect(t_object *object,t_ray ray)
{
    t_equations_vars vars;
    t_intersections *head_entersections = NULL;
	t_sphere *sphere = (t_sphere *)object ->object;
    t_tuple sphere_to_ray;
    t_ray ray2 = ray;

    ray2 = transform_ray(ray,*sphere ->inverse_transformation);
    sphere_to_ray =  substract_tuple(ray2.origin,sphere->origin);
    vars.a = dot_product(ray2.direction, ray2.direction);
    vars.b = 2 * dot_product(ray2.direction, sphere_to_ray);
    vars.c = dot_product(substract_tuple(ray2.origin, sphere->origin), sphere_to_ray) - 1;
    vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
    if (vars.determinant < 0)
		return NULL; //means no solutions
	else
	{
		vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
		vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
        add_intersection(&head_entersections,intersection(vars.sol1,object));
        add_intersection(&head_entersections,intersection(vars.sol2,object));
        return (head_entersections);
	}
}

t_tuple normal_at(t_sphere *sphere,t_tuple world_point)
{
    t_tuple object_point = multiply_matrix_tuple(*invert_matrix(sphere->transformation),world_point);
    t_tuple object_normal = substract_tuple(object_point,make_tuple(0, 0, 0,POINT));
    t_tuple world_normal =  multiply_matrix_tuple(*transpose_matrix(invert_matrix(sphere->transformation)),object_normal);
    world_normal.w = 0;
    return  tuple_normalize(world_normal);
}


// void draw_sphere(t_tuple camera, float z_image_plane)
// {
//     int y;
//     int x;
//     float half,word_y,word_x;
//     float pixel_size;
//     float image_plane_size;
//     float abs_z_camera = abs(camera.z);

//     image_plane_size = (((abs_z_camera + z_image_plane)/ abs_z_camera) * 2) + MARGIN;
//     pixel_size = image_plane_size / WINDOW_WIDTH;
//     half = image_plane_size / 2;
//     y = 0;
//     t_sphere *s = sphere();
//     s->material = make_material();
// 	s ->transformation = multiply_matrices(rotation_y(45),scaling(make_tuple(1,0.5,1,VECTOR)));
// 	s->material.shininess = 50;
//     s->material.color =  make_color(1, 1, 1);
//     t_tuple light_position = make_tuple(-10, -10, -10,POINT);
//     t_tuple light_color = make_color(0.7, 0.5, 1);
//     t_light light = make_light(light_position, light_color);
//     while (y < WINDOW_HEIGHT)
//     {
//         x = 0;
//         word_y = half - pixel_size * y;
//         while (x < WINDOW_WIDTH)
//         {
//             word_x = -half + pixel_size * x;
//             t_tuple position = make_tuple(word_x,word_y,z_image_plane,POINT);
//             t_ray ray = make_ray(camera,tuple_normalize(substract_tuple(position,camera)));
//             t_intersections *ray_intersection = intersect(s,ray);
//             t_intersections *intersection = hit(ray_intersection);
//             if (intersection)
//             {
//                 t_sphere intersect_sphere = *(t_sphere *)intersection->object;
//                 t_tuple point = ray_position(ray, intersection->t);
//                 t_tuple normal = normal_at(intersect_sphere, point);
//                 t_tuple eye = negate_tuple(ray.direction);                
//                 t_tuple color = lighting(intersect_sphere.material, light, point, eye, normal);
//                 plot(x,y,color);
//             }
//             x++;
//         }
//         y++;
//     }
// }

/*
intersect_sphere
intersect plane
intersect sylinder
*/
// int main()
// {
//     t_tuple origin= make_tuple(0,0,5,1),direction = make_tuple(0,0,1,0);
//     t_ray ray = make_ray(origin,direction);
//     t_sphere *s = sphere();
//     //set_tranform(s,translation(make_tuple(5,0,0,1)));
//     t_intersections *head = intersect(ray,s);
//     if (!head)
//         printf("NULL\n");
//     else
//     {
//         print_solution(head);
//     }
//     // t_intersections *head;
//     // t_intersections *i1 = intersection(5,s);
//     // t_intersections *i2= intersection(7,s);
//     // t_intersections *i3 = intersection(-3,s);
//     // i3 ->next= intersection(2,s);
//     // head = i1;
//     // head ->next = i2;
//     // i2 ->next = i3;

//     // t_intersections *hit_intersection = hit(head);
//     // if (!hit_intersection)
//     //     printf("NULL\n");
//     // else
//     // {
//     //     printf("%.2f\n",hit_intersection->t);
//     // }
//     return (0);
// }
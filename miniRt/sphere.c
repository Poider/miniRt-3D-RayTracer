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
    return sphere;
}

void set_tranform(t_sphere *s,t_matrices *matrix)
{
    s->transformation = matrix;
}

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
#include "./includes/miniRt.h"

t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param)
{
    t_sphere *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->origin = origin; //(0,0,0) usually (use make_tuple function to send a tuple in)
    sphere->radius = radius;
    param->object_id++;
    sphere->object_id = 1;
    sphere->transformation = identity_matrix(4);
    return sphere;
}

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

t_intersections *intersection(float t, void *obj)
{
    return (ft_lstnew(t,obj));
}

t_intersections *intersect(t_ray ray, t_sphere *sphere)
{
    t_equations_vars vars;
    t_intersections *head_entersections = NULL;
    t_tuple sphere_to_ray;
    t_ray ray2;

    ray2 = transform_ray(ray,*invert_matrix(sphere->transformation));
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
        ft_lstadd_back(&head_entersections,intersection(vars.sol1,sphere));
        ft_lstadd_back(&head_entersections,intersection(vars.sol2,sphere));
        return (head_entersections);
	}
}

void print_solution(t_intersections *head)
{
    while (head)
    {
        printf("%.2f id = %p\n",head ->t,head ->object);
        head = head ->next;
    }
}

//get hits

t_intersections *hit(t_intersections *l_intersections)//list intersections
{
    float min;
    t_intersections *min_intersection;
    

    min = MAX_INT;
    min_intersection = NULL;
    while(l_intersections)
    {
        if (is_pos(l_intersections ->t) && is_lesser(l_intersections->t,min))
        {
            min = l_intersections ->t;
            min_intersection = l_intersections;
        }
        l_intersections =l_intersections ->next;
    }
    return (min_intersection);
}


void set_tranform(t_sphere *s,t_matrices *matrix)
{
    s->transformation = matrix;
}


// int main()
// {
//     t_tuple origin= make_tuple(0,0,-5,1),direction = make_tuple(0,0,1,0);
//     t_ray ray = make_ray(origin,direction);
//     t_sphere *s = sphere();
//     set_tranform(s,translation(make_tuple(5,0,0,1)));
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
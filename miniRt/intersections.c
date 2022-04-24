#include "./includes/miniRt.h"

// t_intersections *ray_sphere_intersect(t_ray ray, t_sphere *sphere)
// {
//     t_equations_vars vars;

//     vars.a = dot_product(ray.direction, ray.direction);
//     vars.b = 2 * dot_product(ray.direction, substract_tuple(ray.origin, sphere->origin));
//     vars.c = dot_product(substract_tuple(ray.origin, sphere->origin), substract_tuple(ray.origin, sphere->origin)) - pow(sphere->radius,2);
   
//     vars.determinant = (b * b) - (4.0 * a * c);
//     if (vars.determinant < 0)
// 		return NULL; //means no solutions
// 	else
// 	{
// 		vars.sol1 = ((-1.0 * b) - sqrt(vars.determinant)) / (2.0 * a);
// 		vars.sol2 = ((-1.0 * b) + sqrt(vars.determinant)) / (2.0 * a);
// 	}
// }

t_intersections *intersection(float t, void *obj)
{
    return (ft_lstnew(t,obj));
}

t_intersections *intersect(t_ray ray, t_sphere *sphere)
{
    t_equations_vars vars;
    t_intersections *head_entersections = NULL;
    t_tuple sphere_to_ray;
    t_ray ray2 = ray;

    //ray2 = transform_ray(ray,*invert_matrix(sphere->transformation));
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

//sort_intersections(t_ray *ray)


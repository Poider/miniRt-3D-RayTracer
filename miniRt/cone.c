#include "./includes/miniRt.h"

t_cone *cone()
{
    t_cone *cone_shape;

    cone_shape = malloc(sizeof(t_cone));
    cone_shape->origin = ORIGIN; //(0,0,0) usually (use make_tuple function to send a tuple in)
    cone_shape->radius = 1.0;
	cone_shape ->min = -INFINITY;
	cone_shape ->max = INFINITY;
	cone_shape ->closed = FALSE;
    cone_shape->transformation = identity_matrix(DEFAULT_DIMENSION);
	cone_shape->material = make_material();
    return (cone_shape);
}

t_intersections *intersect_cone(t_object *shape,t_ray ray)
{
    t_equations_vars vars;
    t_intersections	*head_entersections = NULL;
	float			y_intersection;
	t_cone		*cone = (t_cone *)shape ->object;

    vars.a = ray.direction.x * ray.direction.x - ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
	vars.b = 2 * ray.origin.x * ray.direction.x - 2 * ray.origin.y * ray.direction.y + 2 * ray.origin.z * ray.direction.z;
	vars.c = ray.origin.x * ray.origin.x - ray.origin.y * ray.origin.y + ray.origin.z * ray.origin.z;
	if (is_equal(vars.a, 0) && is_equal(vars.b, 0))
	{
		return (NULL);
	}
	else
	{
		if (is_equal(vars.a, 0))
		{
			vars.sol1 = (-vars.c / (2 * vars.b));
			add_intersection(&head_entersections,intersection(vars.sol1,shape));
			return (head_entersections);
		}
		else
		{
			vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
			// if (is_equal(vars.determinant, -0.0))
			// 	vars.determinant *= -1;
			if (vars.determinant < 0)
				return (NULL);
			else
			{
				vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
				vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
				// if (vars.sol1 > vars.sol2)
				// {
				// 	float tmp = vars.sol1;
				// 	vars.sol1 = vars.sol2;
				// 	vars.sol2 = tmp;
				// }
				y_intersection = ray.origin.y + vars.sol1 * ray.direction.y;
				if (y_intersection >= cone ->min && y_intersection <= cone ->max)
					add_intersection(&head_entersections,intersection(vars.sol1,shape));
				y_intersection = ray.origin.y + vars.sol2 * ray.direction.y;
				if (y_intersection >= cone ->min && y_intersection <= cone ->max)
					add_intersection(&head_entersections,intersection(vars.sol2,shape));
			}
		}
	}
	cone_intersect_caps(shape, ray, &head_entersections);
	return (head_entersections);
}

int				cone_check_cap(t_ray ray, float t)
{
	t_tuple	pos_intersection;

	pos_intersection = ray_position(ray, t);
	return (pow(pos_intersection.x,2) + pow(pos_intersection.z,2) <= abs_float(pos_intersection.y));
}

void	cone_intersect_caps(t_object *cone_object, t_ray ray, t_intersections **l_intersections)
{
	float	t;
	t_cone	*cone;

	cone = cone_object ->object;
	if (cone ->closed == 0 || is_equal(ray.direction.y, EPSILON))
		return ;
	t = (cone->min - ray.origin.y) / ray.direction.y; //check intersection with lower end cap
	if (cone_check_cap(ray, t))
		add_intersection(l_intersections,intersection(t, cone_object));
	t = (cone->max - ray.origin.y) / ray.direction.y; //check intersection with lower end cap
	if (cone_check_cap(ray, t))
		add_intersection(l_intersections,intersection(t, cone_object));
}

t_tuple			normal_at_cone(t_object *shape,t_tuple world_point)
{
	t_cone *cone;
	t_tuple object_normal;
	float		dist;
	float		y;

	cone = (t_cone *)shape ->object;
	dist = pow(world_point.x,2) +  pow(world_point.z,2);
	if (dist < 1 && world_point.y >= cone ->max - EPSILON)
		object_normal = make_tuple(0, 1, 0,VECTOR);
	else if (dist < 1 && world_point.y <= cone ->min + EPSILON)
		object_normal = make_tuple(0,-1, 0,VECTOR);
	else
	{
		y = sqrt(dist);
		if (world_point.y > 0)
			y = -y;
		object_normal = make_tuple(world_point.x, y, world_point.z,VECTOR);
	}
	return  (object_normal);
}


// int main()
// {
// 	t_object *shape;
// 	t_cone *cone_obj = cone();
// 	// cone_obj ->min = -0.5;
// 	// cone_obj ->max = 0.5;
// 	// cone_obj ->closed = TRUE;
// 	// t_tuple dir = tuple_normalize(make_tuple(0,1,0, VECTOR));
// 	// t_ray r = make_ray(make_tuple(0,0,-0.25,POINT), dir);
// 	shape = create_object(CONE, cone_obj);
// 	// t_intersections *inters = intersect_cone(shape, r);
// 	// while (inters)
// 	// {
// 	// 	printf("%.2f | ",inters ->t);
// 	// 	inters = inters ->next;
// 	// }

// 	t_tuple n = normal_at_cone(shape, make_tuple(1,1,1,POINT));
// 	printf("%.2f %.2f %.2f\n",n.x, n.y, n.z);
// 	return (0);
// }
#include "./includes/miniRt.h"

t_cylinder *cylinder()
{
    t_cylinder *cylinder_shape;

    cylinder_shape = malloc(sizeof(t_cylinder));
    cylinder_shape->origin = ORIGIN; //(0,0,0) usually (use make_tuple function to send a tuple in)
    cylinder_shape->radius = 1.0;
	cylinder_shape ->min = -INFINITY;
	cylinder_shape ->max = INFINITY;
	cylinder_shape ->closed = 0;
    cylinder_shape->transformation = identity_matrix(DEFAULT_DIMENSION);
	cylinder_shape->material = make_material();
    return (cylinder_shape);
}

t_intersections *intersect_cylinder(t_object *shape,t_ray ray)
{
    t_equations_vars vars;
    t_intersections	*head_entersections = NULL;
	float			y_intersection;
	t_cylinder		*cylinder = (t_cylinder *)shape ->object;

    vars.a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
	if (is_equal(vars.a, 0))
		cylinder_intersect_caps(shape, ray, &head_entersections);
	else
	{
		vars.b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
		vars.c = ray.origin.x * ray.origin.x + ray.origin.z * ray.origin.z - 1;
		vars.determinant = (vars.b * vars.b) - (4.0 * vars.a * vars.c);
		if (vars.determinant < 0)
			return NULL; //means no solutions
		else
		{
			vars.sol1 = ((-1.0 * vars.b) - sqrt(vars.determinant)) / (2.0 * vars.a);
			vars.sol2 = ((-1.0 * vars.b) + sqrt(vars.determinant)) / (2.0 * vars.a);
			y_intersection = ray.origin.y + vars.sol1 * ray.direction.y;
			if (y_intersection >= cylinder ->min && y_intersection <= cylinder ->max)
				add_intersection(&head_entersections,intersection(vars.sol1,shape));
			y_intersection = ray.origin.y + vars.sol2 * ray.direction.y;
			if (y_intersection >= cylinder ->min && y_intersection <= cylinder ->max)
				add_intersection(&head_entersections,intersection(vars.sol2,shape));
			cylinder_intersect_caps(shape, ray, &head_entersections);
		}
	}
	return (head_entersections);
}

int				cylinder_check_cap(t_ray ray, float t)
{
	t_tuple	pos_intersection;

	pos_intersection = ray_position(ray, t);
	return (pow(pos_intersection.x,2) + pow(pos_intersection.z,2) <= 1);
}

void	cylinder_intersect_caps(t_object *cylinder_object, t_ray ray, t_intersections **l_intersections)
{
	float		t;
	t_cylinder *cylinder;

	cylinder = cylinder_object ->object;
	if (cylinder ->closed == 0 || is_equal(ray.direction.y, EPSILON))
		return ;
	t = (cylinder->min - ray.origin.y) / ray.direction.y; //check intersection with lower end cap
	if (cylinder_check_cap(ray, t))
		add_intersection(l_intersections,intersection(t, cylinder_object));
	t = (cylinder->max - ray.origin.y) / ray.direction.y; //check intersection with lower end cap
	if (cylinder_check_cap(ray, t))
		add_intersection(l_intersections,intersection(t, cylinder_object));
}

t_tuple			normal_at_cylinder(t_object *shape,t_tuple world_point)
{
	t_cylinder *cylinder;
	t_tuple object_normal;
	float		dist;

	cylinder = (t_cylinder *)shape ->object;
	dist = pow(world_point.x,2) +  pow(world_point.z,2);
	if (dist < 1 && world_point.y >= cylinder ->max - EPSILON)
		object_normal = make_tuple(0, 1, 0,VECTOR);
	else if (dist < 1 && world_point.y <= cylinder ->min + EPSILON)
		object_normal = make_tuple(0,-1, 0,VECTOR);
	else
		object_normal = make_tuple(world_point.x, 0, world_point.z,VECTOR);
	return  (object_normal);
}




// int main()
// {
// 	t_object *shape;
// 	t_cylinder *cyl = cylinder();

// 	t_tuple dir = tuple_normalize(make_tuple(0.1,1,1, VECTOR));
// 	t_ray r = make_ray(make_tuple(0.5,0,-5,POINT), dir);
// 	shape = create_object(CYLINDER, cyl);
// 	t_intersections *inters = intersect_cylinder(shape, r);
// 	while (inters)
// 	{
// 		printf("%.2f | ",inters ->t);
// 		inters = inters ->next;
// 	}
// 	printf("\n");
// 	return (0);
// }
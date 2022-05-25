#include "./includes/miniRt.h"

void	set_local_pattern_function(t_pattern *pattern)
{
	int	type_pattern;

	type_pattern = pattern ->type_pattern;
	if (type_pattern == STRIPE_PATTERN)
		pattern ->local_pattern_at = stripe_at;
	else if (type_pattern == GRADIENT_PATTERN)
		pattern ->local_pattern_at = gradien_at;
	else if (type_pattern == RING_PATTERN)
		pattern ->local_pattern_at = ring_at;
	else if (type_pattern == CHECKERBORAD_PATTERN)
		pattern ->local_pattern_at = checkerbord_at;
	else
	{
		printf("Error pattern not exist\n");
		exit (0);
	}
}

t_pattern	*make_pattern(t_tuple white ,t_tuple black, int type_pattern, int is_3D)
{
	t_pattern *pattern;

	pattern = malloc(sizeof(t_pattern));
	pattern->color_a = white;
	pattern->color_b = black;
	pattern ->type_pattern = type_pattern;
	pattern ->transformation = identity_matrix(DEFAULT_DIMENSION);
	pattern ->is_3D = is_3D;
	pattern ->inverse_transformation = pattern ->transformation;
	set_local_pattern_function(pattern);
	return (pattern);
}

void	set_transformation_pattern(t_pattern *pattern, t_matrices *matrix)
{
	if (!pattern)
		return;
	t_matrices *inverse_transform;

	pattern ->transformation = matrix;
	inverse_transform = invert_matrix(matrix);
	if (inverse_transform)
		pattern ->inverse_transformation = inverse_transform;
}

t_tuple stripe_at(t_pattern *pattern,t_tuple point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_tuple pattern_at_shape(t_pattern *pattern,t_tuple point, t_object *shape)
{
	t_tuple object_point = multiply_matrix_tuple(*shape->inverse_transformation, point);
	t_tuple pattern_point = multiply_matrix_tuple(*pattern->inverse_transformation, object_point);
	return (pattern->local_pattern_at(pattern, pattern_point));
}

t_tuple		gradien_at(t_pattern *pattern,t_tuple point)
{
	t_tuple colors_distance;
	t_tuple	res_color;
	float	fraction_x;

	colors_distance = substract_tuple(pattern->color_b , pattern->color_a);
	fraction_x = point.x - floor(point.x);
	res_color =  add_tuple(pattern->color_a, tuple_scalar_multiplication(colors_distance, fraction_x)); 
	return (res_color);
}


t_tuple		ring_at(t_pattern *pattern,t_tuple point)
{
	float distance;

	distance = sqrt(pow(point.x, 2) + pow(point.z, 2));
	if ((int)floor(distance) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

t_tuple		checkerbord_at(t_pattern *pattern,t_tuple point)
{
	int floor_z;

	floor_z = 0;
	if (pattern->is_3D)
		floor_z = floor(point.z);
	if ((int)(floor(point.x) + floor(point.y) + floor_z ) % 2 == 0)
		return (pattern->color_a);
	return (pattern->color_b);
}

// int main()
// {
// 	t_pattern pattern = stripe_pattern(WHITE,BLACK);

// 	t_tuple c = stripe_at(pattern , make_tuple(1,10,-2,POINT));
// 	printf("%.2f %.2f %.2f\n",c.x , c.y, c.z);
// 	return (0);
// }


//any object max size is 1 unit
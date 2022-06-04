#include "./includes/miniRt.h"


t_material get_material_object(t_object shape)
{
	if (shape.type_object ==  SPHERE)
	{
		t_sphere *sphere = shape.object;
		return (sphere->material);
	}
	else
		return (make_material());//i will update this just for now

}

void	set_refractives_idx(t_precomputed *pre_computed,t_intersections *hit, t_intersections *list)
{
	t_intersections	*containers = NULL;
	t_intersections	*prev_object = 0;

	while (list)
	{
		if (hit == list)
		{
			if (containers == NULL)
				pre_computed ->n1 =  VACUUM;
			else
				pre_computed ->n1 = get_last_intersection(containers)->object->material.refractive_index;
		}
		prev_object = get_prev_object(containers, list->object);
		if (prev_object)
		{
			if (containers ->next == NULL)
			{
				free(containers);
				containers = NULL;
			}
			else
			{
				t_intersections *tmp  = prev_object ->next;
				prev_object ->next = prev_object ->next->next;
				free(tmp);
			}
		}
		else
		{
			t_intersections *new = intersection(list ->t, list ->object);
			add_intersection(&containers,new);
		}
		if (hit == list)
		{
			if (containers == NULL)
				pre_computed ->n2 =  VACUUM;
			else
				pre_computed ->n2 =  get_last_intersection(containers)->object->material.refractive_index;
			break;
		}		
		list = list ->next;
	}
}

t_precomputed prepare_computations(t_intersections *intersection, t_ray ray, t_intersections *list_intersections)
{
	t_precomputed	pre_computed;
	t_tuple			epsilon_normal;

	pre_computed.t = intersection ->t;
	pre_computed.point = ray_position(ray,pre_computed.t);
	pre_computed.object = intersection ->object;
	pre_computed.eyev = negate_tuple(ray.direction);
	pre_computed.normalv = normal_at(intersection->object, pre_computed.point);
	if (dot_product(pre_computed.normalv,pre_computed.eyev) < 0)
	{
		pre_computed.is_inside = TRUE;
		pre_computed.normalv = negate_tuple(pre_computed.normalv);
	}
	else
		pre_computed.is_inside = FALSE;
	pre_computed.reflecv = reflect(ray.direction, pre_computed.normalv);
	pre_computed.material = intersection->object->material;
	epsilon_normal = tuple_scalar_multiplication(pre_computed.normalv, 0.003);
	pre_computed.over_point = add_tuple(pre_computed.point, epsilon_normal);
	pre_computed.under_point = substract_tuple(pre_computed.point, epsilon_normal);
	pre_computed.over_point.w = POINT;
	set_refractives_idx(&pre_computed, intersection, list_intersections);
	return (pre_computed);
}



// int main()
// {
// 	t_sphere *A = glass_sphere();
// 	A->transformation = scaling(make_tuple(2,2,2,VECTOR));
// 	A ->material.refractive_index = 1.5;
// 	t_sphere *B = glass_sphere();
// 	B->transformation = translation(make_tuple(0,0,-0.25,VECTOR));
// 	B ->material.refractive_index = 2;
// 	t_sphere *C = glass_sphere();
// 	C ->transformation = translation(make_tuple(0,0,0.25,VECTOR));
// 	C ->material.refractive_index = 2.5;


// 	t_object *a_obj = create_object(SPHERE, A);
// 	t_object *b_obj = create_object(SPHERE, B);
// 	t_object *c_obj = create_object(SPHERE, C);
// 	a_obj ->next = b_obj;
// 	b_obj ->next = c_obj;
// 	t_ray ray = make_ray(make_tuple(0,0,-4,POINT), make_tuple(0,0,1,VECTOR));
// 	t_intersections *head = NULL;
// 	t_intersections *iter = NULL;
// 	add_intersection(&head, get_new_intetsection(2, a_obj));
// 	add_intersection(&head, get_new_intetsection(2.75, b_obj));
// 	add_intersection(&head, get_new_intetsection(3.25, c_obj));
// 	add_intersection(&head, get_new_intetsection(4.75, b_obj));
// 	add_intersection(&head, get_new_intetsection(5.25, c_obj));
// 	add_intersection(&head, get_new_intetsection(6, a_obj));
// 	iter = head;
// 	int i = 1;
// 	while (iter)
// 	{
// 		t_precomputed pre = prepare_computations(iter, ray,head);
// 		printf("| %d | = | %f | | %f |\n",i,pre.n1,pre.n2);
// 		i++;
// 		iter = iter ->next;
// 	}
// 	return (0);
// }
#include "./includes/miniRt.h"

void		add_object(t_object **objects, t_object *new_object)
{
	t_object	*temp;

	if (!objects)
		return ;
	if (*objects == NULL)
		*objects = new_object;
	else
	{
		temp = get_last_object(*objects);
		temp -> next = new_object;
	}
}

void set_tranform(t_object *object,t_matrices *matrix)
{
    object->transformation = matrix;
	object->inverse_transformation = invert_matrix(matrix);
}

void set_material(t_object *object , t_material material)
{
    object ->material = material;
}

t_object	*get_last_object(t_object *objects)
{
	t_object	*temp;

	if (!objects)
		return (NULL);
	temp = objects;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	return (temp);
}

void init_object_attr(int	type_object,t_object *obj)
{
	void		*object;
	t_matrices *transform;
	t_material	material;

	transform = NULL;
	object = obj ->object;
	if (type_object == SPHERE)
	{
		t_sphere *sphere = (t_sphere *)object;
		transform = sphere->transformation;
		material  = sphere ->material;
		obj->local_normal_at = normal_at_sphere;
		obj->local_intersect = intersect_sphere;
	}
	else if (type_object == PLANE)
	{
		t_plane *plane = (t_plane *)object;
		transform = plane->transformation;
		material  = plane ->material;
		obj->local_normal_at = normal_at_plane;
		obj->local_intersect = intersect_plane;
	}
	set_tranform(obj, transform);
	set_material(obj, material);
}

t_object	*create_object(int type_object, void *object)
{
	t_object	*node;

	node = malloc(sizeof(t_object));
	if (!node)
		return (NULL);
	node -> type_object = type_object;
	node ->object = object;
	init_object_attr(type_object, node);
	node -> next = NULL;
	return (node);
}

int			 get_number_objects(t_object *objects)
{
	t_object	*temp;
	int		countnode;

	countnode = 0;
	temp = objects;
	while (temp)
	{
		temp = temp -> next;
		countnode += 1;
	}
	return (countnode);
}

t_tuple		normal_at(t_object *shape,t_tuple world_point)
{
    t_tuple object_point = multiply_matrix_tuple(*shape->inverse_transformation,world_point);
    t_tuple object_normal = shape->local_normal_at(shape, object_point);
    t_tuple world_normal =  multiply_matrix_tuple(*transpose_matrix(shape->inverse_transformation),object_normal);
    world_normal.w = 0;
    return  tuple_normalize(world_normal);
}
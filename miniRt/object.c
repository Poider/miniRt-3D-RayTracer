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

t_object	*get_last_object(t_object *objects)
{
	t_object	*temp;

	if (!objects)
		return (NULL);
	temp = objects;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}

t_object	*create_object(int type_object, void *object)
{
	t_object	*node;

	node = malloc(sizeof(t_object));
	if (!node)
		return (NULL);
	node -> type_object = type_object;
	node ->object = object;
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

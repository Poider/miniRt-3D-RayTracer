#include "./includes/miniRt.h"

void	add_intersection(t_intersections **intersections, t_intersections *new_intersection)
{
	t_intersections	*temp;

	if (!intersections)
		return ;
	if (*intersections == NULL)
		*intersections = new_intersection;
	else
	{
		temp = get_last_intersection(*intersections);
		temp -> next = new_intersection;
	}
}
t_intersections	*get_last_intersection(t_intersections *intersections)
{
	t_intersections	*temp;

	if (!intersections)
		return (NULL);
	temp = intersections;
	while (temp -> next)
		temp = temp -> next;
	return (temp);
}

t_intersections	*get_new_intetsection(float t, t_object *shape)
{
	t_intersections	*node;

	node = malloc(sizeof(t_intersections));
	if (!node)
		return (NULL);
	node -> t = t;
	node ->object = shape;
	node -> next = NULL;
	return (node);
}

void sort_intersectios(t_intersections *list_intersections)
{
	t_intersections *curr;
	t_intersections *next_node;
	curr = list_intersections;
	while(curr)
	{
		next_node = curr ->next;
		while (next_node)
		{
			if (is_greater(curr ->t, next_node ->t))
			{
				t_object *obj_tmp = curr ->object;
				float tmp = curr->t;
				curr ->t = next_node -> t;
				curr ->object = next_node ->object;
				next_node ->t = tmp;
				next_node->object = obj_tmp;
			}
			next_node = next_node ->next;
		}
		curr = curr ->next;
	}
}


t_intersections *intersect_word(t_world world, t_ray ray)
{
	t_intersections	*list_intersections = NULL;
	t_ray			transformed_ray;
	t_object 		*object_iter = world.objects;;
	while (object_iter)
	{
    	transformed_ray = transform_ray(ray,*object_iter->inverse_transformation);
		if (list_intersections == NULL)
			list_intersections = object_iter->local_intersect(object_iter, transformed_ray);
		else
			add_intersection(&list_intersections, object_iter->local_intersect(object_iter,transformed_ray));
		object_iter = object_iter->next;
	}
	sort_intersectios(list_intersections);
	return (list_intersections);
}


void free_list_intersection(t_intersections *list_intersections)
{
	t_intersections *tmp;

	tmp = list_intersections;
	while (tmp ->next)
	{
		list_intersections = tmp ->next;
		free(tmp);
		tmp = list_intersections;
	}
}

int	get_size_intersections(t_intersections *intersections)
{
	t_intersections	*temp;
	int		countnode;

	countnode = 0;
	temp = intersections;
	while (temp)
	{
		temp = temp -> next;
		countnode += 1;
	}
	return (countnode);
}



t_intersections *intersection(float t, t_object *shape)
{
    return (get_new_intetsection(t,shape));
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
    while(l_intersections)
    {
        if (l_intersections->t >= 0)
           return (l_intersections);
        l_intersections =l_intersections ->next;
    }
    return (0);
}

//sort_intersections(t_ray *ray)


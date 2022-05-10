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

t_intersections	*get_new_intetsection(float t, void *object)
{
	t_intersections	*node;

	node = malloc(sizeof(t_intersections));
	if (!node)
		return (NULL);
	node -> t = t;
	node ->object = object;
	node -> next = NULL;
	return (node);
}

void sort_intersectios(t_intersections *list_intersections)
{
	t_intersections *curr;
	t_intersections *prev;

	curr = list_intersections;
	prev = curr;
	while(curr)
	{
		if (is_greater(prev ->t, curr ->t))
		{
			float tmp = curr->t;
			curr ->t = prev -> t;
			prev ->t = tmp;
		}
		prev = curr;
		curr = curr ->next;
	}
}


t_intersections *intersect_word(t_world world, t_ray ray)
{
	t_intersections	*list_intersections = NULL;
	t_object 		*object_iter = world.objects;;
	while (object_iter)
	{
		if (list_intersections == NULL)
			list_intersections = intersect(object_iter ->object,ray);
		else
			add_intersection(&list_intersections,intersect(object_iter ->object,ray));
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



t_intersections *intersection(float t, void *object)
{
    return (get_new_intetsection(t,object));
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


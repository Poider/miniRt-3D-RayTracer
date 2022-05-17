#include "miniRt.h"

#define SPHERE 1

typedef struct	s_object
{
	int				type_object;
	void			*object;
	struct s_object *next;
}				t_object;


t_object	*get_last_object(t_object *objects);
void		add_object(t_object **objects, t_object *new_object);
t_object	*create_object(int type_object, void *object);
int			get_number_objects(t_object *objects);
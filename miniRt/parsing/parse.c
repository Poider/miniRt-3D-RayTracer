
#include "./../includes/miniRt.h"

//send in the initial value there in case line is "NULL" so u return it

//make it so when parsing done it prints it

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2 && n != 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && i < n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

//there should be an order to each and in case its not there it should have "NULL" written

//returns object type + the object address in obj

void plane_settings(int fd,t_plane *shape,char *line)
{
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line);
    line = get_next_line(fd);
    orientation_vector_set(shape->transformation, line);
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material, line);
    line = get_next_line(fd);
    shape->material.specular = specular_set(shape->material.specular, line);
    line = get_next_line(fd);
    shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
}
void cylinder_settings(int fd,t_cylinder *shape,char *line)
{   
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line);
    line = get_next_line(fd);
    orientation_vector_set(shape->transformation, line);
    line = get_next_line(fd);
    shape->transformation = diameter_set(shape->transformation,line);
    line = get_next_line(fd);
    height_set(&shape->min,&shape->max, line);
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material, line);
    line = get_next_line(fd);
    shape->material.specular = specular_set(shape->material.specular, line);
    line = get_next_line(fd);
    shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
    line = get_next_line(fd);
    shape->closed = close_set(line);
}
void cone_settings(int fd,t_cone *shape,char *line)
{   
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line);
    line = get_next_line(fd);
    orientation_vector_set(shape->transformation, line);
    line = get_next_line(fd);
    shape->transformation = diameter_set(shape->transformation,line);
    line = get_next_line(fd);
    height_set(&shape->min,&shape->max, line);
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material,line);
    line = get_next_line(fd);
    shape->material.specular = specular_set(shape->material.specular, line);
    line = get_next_line(fd);
    shape->material.diffuse = diffuse_set(shape->material.diffuse,line);
    line = get_next_line(fd);
    shape->closed = close_set(line);
}
void sphere_settings(int fd,t_sphere *shape,char *line)
{   
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line);
    line = get_next_line(fd);
    shape->transformation = diameter_set(shape->transformation,line);
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material, line);
    line = get_next_line(fd);
    shape->material.specular = specular_set(shape->material.specular, line);
    line = get_next_line(fd);
    shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
}

t_object *sphere_make(int fd)
{
    char *line;
    t_sphere *shape;

    line = NULL;
    shape = sphere();
    sphere_settings(fd, shape, line);
    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
    return (t_object *)shape;
}

t_object *plane_make(int fd)
{
    char *line;
    t_plane *shape;

    line = NULL;
    shape = plane();
    plane_settings(fd, shape, line);
    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
    return (t_object *)shape;
}

t_object *cylinder_make(int fd)
{
    char *line;
    t_cylinder *shape;

    line = NULL;
    shape = cylinder();
    cylinder_settings(fd, shape, line);
    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }

    return (t_object *)shape;
}

t_object *cone_make(int fd)
{
    char *line;
    t_cone *shape;

    line = NULL;
    shape = cone();
    cone_settings(fd, shape, line);
    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }

    return (t_object *)shape;
}

void ambient_make(int fd)
{
    char *line;
    line = get_next_line(fd);

    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
}

void light_make(int fd)
{// gotta send in light and keep adding more lights to it
    char *line;

    line = get_next_line(fd);
    coordinates =
    while (!ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
}

void camera_make(t_camera *camera,int fd)
{
    char *line;
    t_tuple camera_origin;
    t_tuple up;
    float FOV;

    line = get_next_line(fd);
    camera_origin = tuple_set(line);
    line = get_next_line(fd);
    up = tuple_set(line);//up is a vector
    line = get_next_line(fd);
    FOV = FOV_set(line);
    set_camera_transformation(camera,camera_origin,make_tuple(0, 1, 0,POINT),up);
    camera->FOV = FOV;
    while(!ft_strncmp(line,"END", 3))
    {
        if(line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
}


void parse_file(t_world *world,t_camera *camera,int fd)
{//should I free "shape each time? after creating the obj"
    char *line;
    t_object *objects;
    t_object *shape;

    line = NULL;
	objects = NULL;
    while(1)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        if(ft_strncmp(line,"ambient", 6))
        {

        }
        if(ft_strncmp(line,"light", 5))
        {

        }
        if(ft_strncmp(line,"camera", 6))
        {
            camera_make(camera,fd);
        }
        if(ft_strncmp(line,"sphere", 6))
        {
            shape = sphere_make(fd);
            add_object(&objects, create_object(SPHERE,shape));
        }
        if(ft_strncmp(line,"plane", 5))
        {
            shape = plane_make(fd);
            add_object(&objects, create_object(PLANE,shape));
        }
        if(ft_strncmp(line,"cylinder", 8))
        {
            shape = cylinder_make(fd);
            add_object(&objects, create_object(CYLINDER,shape));
        }
        if(ft_strncmp(line,"cone", 4))
        {
            shape = cone_make(fd);
            add_object(&objects, create_object(CONE,shape));
        }
    }
    world->objects = objects;
}
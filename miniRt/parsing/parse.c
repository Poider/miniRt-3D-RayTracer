
#include "./../includes/miniRt.h"

//make it that if it goes in the while looking for END for around 200 then it says parse error and exits
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



//returns object type + the object address in obj

void plane_settings(int fd,t_plane *shape,char *line)
{
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line,fd);
    // line = get_next_line(fd);
    // orientation_vector_set(shape->transformation, line);
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material, line,fd,TRUE);
    line = get_next_line(fd);
    shape->material.specular = specular_set(shape->material.specular, line);
    line = get_next_line(fd);
    shape->material.diffuse = diffuse_set(shape->material.diffuse, line);
}
void cylinder_settings(int fd,t_cylinder *shape,char *line)
{   
    line = get_next_line(fd);
    shape->transformation = diameter_set(shape->transformation,line,'c');
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line,fd);
    // line = get_next_line(fd);
    // orientation_vector_set(shape->transformation, line);
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
    pattern_set(&shape->material, line,fd,FALSE);
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
    shape->transformation = diameter_set(shape->transformation,line,'c');
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line,fd);
    // line = get_next_line(fd);
    // orientation_vector_set(shape->transformation, line);

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
    pattern_set(&shape->material,line,fd,FALSE);
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
    shape->transformation = diameter_set(shape->transformation,line,'s');
    line = get_next_line(fd);
    shape->transformation = coordinate_set(shape->transformation,line,fd); 
    line = get_next_line(fd);
    shape->material.color = color_set(line);
    line = get_next_line(fd);
    shape->material.reflective = reflection_set(line);
    line = get_next_line(fd);
    shape->material.transparency = transparency_set(line);
    line = get_next_line(fd);
    shape->material.refractive_index = refractive_set(line);
    line = get_next_line(fd);
    pattern_set(&shape->material, line,fd,FALSE);
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
    line = get_next_line(fd);
    while (ft_strncmp(line, "END", 3))
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
    line = get_next_line(fd);
    while (ft_strncmp(line, "END", 3))
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
    line = get_next_line(fd);
    while (ft_strncmp(line, "END", 3))
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
    line = get_next_line(fd);
    while (ft_strncmp(line, "END", 3))
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

void ambient_make(t_world *world,int fd)
{
    char *line;
    float ambient_ratio;

    line = get_next_line(fd);
    ambient_ratio = max(min(float_parse(line),1),0);
    free(line);
    line = get_next_line(fd);
    if(!ft_strncmp(to_upper(line), "NULL",4))
        free(line);
    else
        world->ambient_color = color_set(line);
    world->ambient_ratio = ambient_ratio;
    while (ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
}

t_light *light_make(int fd)
{
    char    *line;
    t_light *light;
    t_tuple coordinates;
    float   brightness;
    t_tuple color;
    line = get_next_line(fd);
    coordinates = tuple_set(line);  

    line = get_next_line(fd);
    brightness = max(min(float_parse(line),1),0);
    free(line);
    line = get_next_line(fd);
    color = color_set(line);
    color = tuple_scalar_multiplication(color,brightness);
    light = make_light(coordinates, color);
    line = get_next_line(fd);
    while (ft_strncmp(line, "END", 3))
    {
        if (line)
        {
            free(line);
            line = 0;
        }
        line = get_next_line(fd);
    }
    return light;
}

void camera_make(t_camera *camera,int fd)
{
    char *line;
    t_tuple camera_origin;
    t_tuple up;
    float fov;

    line = get_next_line(fd);
    camera_origin = tuple_set(line);
    line = get_next_line(fd);
    up = make_tuple(0,1,0,VECTOR);
    if(ft_strncmp(to_upper(line), "NULL",4))
    up = tuple_set(line);//up is a vector
    line = get_next_line(fd);
    fov = fov_set(line);
    *camera = make_camera(WINDOW_WIDTH, WINDOW_HEIGHT,fov);
    set_camera_transformation(camera,camera_origin,make_tuple(0, 1, 0,POINT),up);
    line = get_next_line(fd);
    while(ft_strncmp(line,"END", 3))
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
{//should I free "shape each time? after creating the obj"// check if you need so in add object
    char        *line;
    t_object    *objects;
    t_object    *shape;
    t_light     *lights;
    t_light     *light;

    lights = NULL;
    line = NULL;
	objects = NULL;
    world->ambient_color = make_color(-1,-1,-1);
    while(1)
    {
        line = get_next_line(fd);
        // printf("%s",line);
        if(line == NULL)
            break;
        if(!ft_strncmp(line,"ambient", 6))
        {
            ambient_make(world,fd);
        }
        else if(!ft_strncmp(line,"light", 5))
        {
            light = light_make(fd);
            add_light(&lights,light);
        }
        else if(!ft_strncmp(line,"camera", 6))
        {
            camera_make(camera,fd);
        }
        else if(!ft_strncmp(line,"sphere", 6))
        {
            shape = sphere_make(fd);
            add_object(&objects, create_object(SPHERE,shape));
        }
        else if(!ft_strncmp(line,"plane", 5))
        {
            shape = plane_make(fd);
            add_object(&objects, create_object(PLANE,shape));
        }
        else if(!ft_strncmp(line,"cylinder", 8))
        {
            shape = cylinder_make(fd);
            add_object(&objects, create_object(CYLINDER,shape));
        }
        if(!ft_strncmp(line,"cone", 4))
        {
            shape = cone_make(fd);
            add_object(&objects, create_object(CONE,shape));
        }
    }
    printf("parsing done\n");
    world->objects = objects;
    world->light = lights;
    
    //  while(objects != NULL);
    //     {
    //         printf("_%s\n",objects);
    //         objects = objects->next;
    //     }
}

//functions X_make are parsing ones, make_X are actual code one
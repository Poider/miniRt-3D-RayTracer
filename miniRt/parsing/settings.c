#include "./../includes/miniRt.h"

//parse error function


int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *to_upper(char *line);
float min(float a,float b);
float max(float a,float b);

int len(char **line)
{
    int i;

    i = 0;
    while(line[i])
        i++;
    return i;
}

void parse_error()
{
    printf("parse error\n");
    exit(1);
}

void free_split(char **vector)
{
    int i;

    i = 0;
    while(vector[i])
    {
        free(vector[i]);
        i++;
    }
    free(vector);
}

float degree_to_radian(float angle)
{
    return (angle * (M_PI /180));
}

float float_parse(char *line)
{
    return(atof(line));
}

t_matrices *rotation_make(t_matrices *matrix, char *line, char c)
{
    t_matrices  *transformation;
    t_matrices  *transformed_matrix;
    float angle;
    
    angle = degree_to_radian(float_parse(line));
    if(c == 'x')
    {
        transformation = rotation_x(angle);
        transformed_matrix = multiply_matrices(transformation,matrix);
    }
    else if(c == 'y')
    {
        transformation = rotation_y(angle);
        transformed_matrix = multiply_matrices(transformation,matrix);
    }
    else if(c == 'z')
    {
        transformation = rotation_z(angle);
        transformed_matrix = multiply_matrices(transformation,matrix);
    }
    free(matrix);
    free(transformation);
    return transformed_matrix;
}

t_matrices *translate_scale_make(t_matrices *matrix, char *line, char c)
{
    t_tuple     transformation_vector;
    t_matrices  *transformation;
    t_matrices  *transformed_matrix;

    transformation_vector =tuple_from_line(line);
    if(c == 't')
    {
        transformation = translation(transformation_vector);
        transformed_matrix = multiply_matrices(transformation,matrix);
    }
    else if(c == 's')
    {
        transformation =scaling(transformation_vector);
        transformed_matrix = multiply_matrices(transformation,matrix);
    }
    free(matrix);
    free(transformation);
    return transformed_matrix;
}

t_matrices *shear_make(t_matrices *matrix, char *line)// SHEAR 1,3,4,5,6,7
{
    t_shear sh;
    t_matrices  *transformation;
    t_matrices  *transformed_matrix;
    char **shear;
    int i;

    i = 0;
    shear = ft_split(line,',');
    sh.Hxy = float_parse(shear[0]);
	sh.Hxz = float_parse(shear[1]);
	sh.Hyx = float_parse(shear[2]);
	sh.Hyz = float_parse(shear[3]);
	sh.Hzx = float_parse(shear[4]);
	sh.Hzy = float_parse(shear[5]);
    transformation = shearing(sh);
    transformed_matrix = multiply_matrices(transformation,matrix);
    free_split(shear);
    free(matrix);
    free(transformation);
    return transformed_matrix;
}

t_matrices  *get_transformations(char *line)
{
    char **lines;
    int i;
    t_matrices *transformations;

    transformations = identity_matrix(4);
    i = 0;
    lines = ft_split(line,' ');
    if(len(lines) % 2 != 0)
    parse_error();
    while(lines[i])
    {
        if(!ft_strncmp(to_upper(lines[i]), "ROTX",4))
           transformations = rotation_make(transformations,lines[i + 1],'x');
        else if(!ft_strncmp(to_upper(lines[i]), "ROTY",4))
           transformations = rotation_make(transformations,lines[i + 1],'y');
        else if(!ft_strncmp(to_upper(lines[i]), "ROTZ",4))
           transformations = rotation_make(transformations,lines[i + 1],'z');
        else if(!ft_strncmp(to_upper(lines[i]), "TRANSLATE",4))
           transformations = translate_scale_make(transformations,lines[i + 1],'t');
        else if(!ft_strncmp(to_upper(lines[i]), "SCALE",4))
           transformations = translate_scale_make(transformations,lines[i + 1],'s');
        else if(!ft_strncmp(to_upper(lines[i]), "SHEAR",4))
           transformations = shear_make(transformations,lines[i + 1]);
        i += 2;
    }
    free_split(lines);
    free(line);
    return transformations;
}

t_matrices  *coordinate_set(t_matrices *matrix, char *line, int fd)
{
    t_matrices  *coordinates_matrix;
    t_tuple     translation_vector;
    char        *transformations;
    t_matrices  *transformations_matrix;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (matrix);
    }
    transformations = get_next_line(fd);
    if(!ft_strncmp(to_upper(transformations), "NULL",4))
        free(transformations);
    else
    {
        transformations_matrix = get_transformations(transformations);
        coordinates_matrix = matrix;
        matrix = multiply_matrices(transformations_matrix,matrix);
        free(coordinates_matrix);
        free(transformations_matrix);
        coordinates_matrix = 0;
    }
    translation_vector = tuple_set(line);
    transformations_matrix = translation(translation_vector);
    coordinates_matrix = multiply_matrices(transformations_matrix,matrix);
    free(matrix);
    free(transformations_matrix);
    return(coordinates_matrix);
    
}

// t_matrices  *orientation_vector_set(t_matrices *matrix, char *line)
// {
//     t_matrices *transformed_matrix;
//     if(!ft_strncmp(to_upper(line), "NULL",4))
//     {
//         free(line);
//         // return ();
//     }
//     //TODO :parse vector and wait to know what to do with it
// }

t_tuple color_set_no_free(char *line)
{
    t_tuple color;
    float R;
    float G;
    float B;
    char   **vector;

    vector = ft_split(line,',');
    R = min(max(0,float_parse(vector[0])),255) / 255;
    G = min(max(0,float_parse(vector[1])),255) / 255;
    B = min(max(0,float_parse(vector[2])),255) / 255;
    color = make_color(R,G,B);
    free_split(vector);
    free(line);
    return color;
}

t_tuple color_set(char *line)
{
    t_tuple color;
    float R;
    float G;
    float B;
    char   **vector;
    
    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (make_color(1,0,0));
    }
    vector = ft_split(line,',');
    R = min(max(0,float_parse(vector[0])),255) / 255;
    G = min(max(0,float_parse(vector[1])),255) / 255;
    B = min(max(0,float_parse(vector[2])),255) / 255;
    // printf("%f %f %f\n",R,G,B);
    color = make_color(R,G,B);
    free_split(vector);
    free(line);
    return color;
}

float   reflection_set(char *line)
{
    float reflection;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0);
    }
    reflection = max(min(float_parse(line),1),0);
    free(line);
    return reflection;
}

float   transparency_set(char *line)
{
     float transparency;
     
    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0);
    }
    transparency = max(min(float_parse(line),1),0);
    free(line);
    return transparency;
}

float   refractive_set(char *line)
{
    float refractive;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (1);
    }
    refractive = float_parse(line);
    free(line);
    return refractive;
}

t_matrices *pattern_transformation_set(int fd)
{
    t_matrices *transformed_matrice;
    char *line;

    line = get_next_line(fd);
    transformed_matrice = get_transformations(line);
    return transformed_matrice;
}

void    pattern_set(t_material *material, char *line, int fd, int is_3D)//not finished
{
    int pattern_type;
    t_pattern *pattern;
    char **parameters;
    t_matrices *pattern_transformation;
    
    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ;
    }
    if(!ft_strncmp(to_upper(parameters[0]), "CHECKERBOARD",12))
        pattern_type = CHECKERBORAD_PATTERN;
    else if(!ft_strncmp(to_upper(parameters[0]), "RING",4))
        pattern_type = RING_PATTERN;
    else if(!ft_strncmp(to_upper(parameters[0]), "STRIPE",6))
        pattern_type = STRIPE_PATTERN;
    else if(!ft_strncmp(to_upper(parameters[0]), "GRADIENT",8))
        pattern_type = GRADIENT_PATTERN;
    else
        pattern_type = CHECKERBORAD_PATTERN; 
    pattern_transformation = pattern_transformation_set(fd); // here
    pattern = make_pattern(color_set_no_free(parameters[1]),color_set_no_free(parameters[2]),\
    pattern_type, is_3D);
    set_material_pattern(material,pattern);
	set_transformation_pattern(material->pattern,pattern_transformation);
    free(line);
    free_split(parameters);
    return ;
}

float   specular_set(float default_specular, char *line)
{
     float specular;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0.3);
    }
    specular = max(float_parse(line),0);
    free(line);
    return specular;
}

float   diffuse_set(float default_diffuse, char *line)
{
    float diffuse;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0.7);
    }
    diffuse = max(min(float_parse(line),1),0);
    free(line);
    return diffuse;
}

t_matrices   *diameter_set(t_matrices *matrix, char *line, char c)
{
    t_matrices *transformed_matrix;
    t_matrices *transformation;
    float d;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (matrix);
    }
    d = max(1,float_parse(line));
    if(c == 's')
    transformation = scaling(make_tuple(d,d,d,VECTOR));
    else
    transformation = scaling(make_tuple(d,0,0,VECTOR));
    transformed_matrix = multiply_matrices(transformation, matrix);
    free(transformation);
    free(matrix);
    free(line);
    return(transformed_matrix);
}

void    height_set(float *_min, float *_max, char *line)
{
    char **numbers;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        *_min = 0;
        *_max = 2;
        return ;
    }
    numbers = ft_split(line,' ');
    *_min = float_parse(numbers[0]);
    *_max = *_min + max(float_parse(numbers[1]),0);
    free_split(numbers);
    free(line);
    return ;
    
}

int close_set(char *line)
{
    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (TRUE);
    }
    if(!ft_strncmp(to_upper(line), "TRUE",4))
        return TRUE;
    else
        return FALSE;
}

t_tuple tuple_from_line(char *line)
{
    char   **vector;
    t_tuple _tuple;

    int i = 0;

    vector = ft_split(line,',');
    _tuple.x = float_parse(vector[0]);
    _tuple.y = float_parse(vector[1]);
    _tuple.z = float_parse(vector[2]);
    if(vector[3])
    {
    if(!ft_strncmp(to_upper(vector[3]),"POINT",5))
        _tuple.w = POINT;
    else
        _tuple.w = VECTOR;
    }
    free_split(vector);
    return _tuple;
}

t_tuple tuple_set(char *line)
{
    char   **vector;
    t_tuple _tuple;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (make_tuple(0, 0, 1, 0));
    }
    int i = 0;

    vector = ft_split(line, ',');
    _tuple.x = float_parse(vector[0]);
    _tuple.y = float_parse(vector[1]);
    _tuple.z = float_parse(vector[2]);
    if (vector[3])
    {
        if (!ft_strncmp(to_upper(vector[3]), "POINT", 5))
            _tuple.w = POINT;
        else
            _tuple.w = VECTOR;
    }
    free_split(vector);
    free(line);
    return (_tuple);
}

float   FOV_set(char *line)
{
    float FOV;

    if(!ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (M_PI / 2);
    }
    FOV = degree_to_radian(float_parse(line));
    free(line);
    return FOV;
}
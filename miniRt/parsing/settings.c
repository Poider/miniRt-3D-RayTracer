#include "./../includes/miniRt.h"

//ambient color ratio and ambient color if its not null

//make coordinate last when setting settings so that you get rotation then scale then translating
//coordiante is translate diameter is scaling // translating is last, and transformations come before that and after scaling for diameter and such

//for transformations we make loop until reach transEND applying each of the transformations

//free the line sent in settings

//color return red as default color


//make cone + cylinder close by default?

//when u return a matrice free the ones used to create that one

//for transformations make it split and each one read type of transformation + vector of it
// !!
//^^ return default settings!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//NULL case
//convert ANGLES to radian
//parse error function
//fill returns
// get transformations need to be multiplied by the initial transformation
//color_set will free and if use it elsewhere in settings itll be a doublefree 

//add transformations into "parse"
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *to_upper(char *line);
float min(float a,float b);
float max(float a,float b);
void free_split(float **vector)
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
    
    angle = degree_to_radian(loat_parse(line));
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
    sh.Hxy = float_parse(line[0]);
	sh.Hxz = float_parse(line[1]);
	sh.Hyx = float_parse(line[2]);
	sh.Hyz = float_parse(line[3]);
	sh.Hzx = float_parse(line[4]);
	sh.Hzy = float_parse(line[5]);
    transformation = shearing(sh);
    transformed_matrix = multiply_matrices(transformation,matrix);
    free_split(shear);
    free(matrix);
    free(transformation);
    return transformed_matrix;
}

t_matrices  *get_transformations(char *line)
{//make func thatll get vector and make the right transformation matrix// send it the function it needs
    char **lines;
    //use this in camera all stuff thatll need transformations either in settings or parse
    int i;
    t_matrices *transformations;

    transformations = identity_matrix(4);
    i = 0;
    lines = ft_split(line,' ');
    while(lines[i])
    {
        if(ft_strncmp(to_upper(lines[i]), "ROTX",4))
           transformations = rotation_make(transformations,line[i + 1],'x');
        else if(ft_strncmp(to_upper(lines[i]), "ROTY",4))
           transformations = rotation_make(transformations,line[i + 1],'y');
        else if(ft_strncmp(to_upper(lines[i]), "ROTZ",4))
           transformations = rotation_make(transformations,line[i + 1],'z');
        else if(ft_strncmp(to_upper(lines[i]), "TRANSLATE",4))
           transformations = translate_scale_make(transformations,line[i + 1],'t');
        else if(ft_strncmp(to_upper(lines[i]), "SCALE",4))
           transformations = translate_scale_make(transformations,line[i + 1],'s');
        else if(ft_strncmp(to_upper(lines[i]), "SHEAR",4))
           transformations = shear_make(transformations,line[i + 1]);
        i += 2;
    }
    free_split(lines);
    free(line);
    return transformations;
}

t_matrices  *coordinate_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    t_tuple translation_vector;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (matrix);
    }
    //TODO :atoi it in translation vector
    //tuple_set cus its a vector
    translation_vector = tuple_set(line);
    transformed_matrix = multiply_matrices(translation(translation_vector),matrix);
}

t_matrices  *orientation_vector_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        // return ();
    }
    //TODO :parse vector and wait to know what to do with it
}

t_tuple color_set(char *line)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (make_color(1,0,0));
    }
    //parse a tuple
    // divide on 255 and take max 255 and min 0
}

float   reflection_set(char *line)
{
    float reflection;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0);
    }
    reflection = float_parse(line);
    free(line);
    return reflection;
}

float   transparency_set(char *line)
{
     float transparency;
     
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (0);
    }
    transparency = float_parse(line);
    free(line);
    return transparency;
}

float   refractive_set(char *line)
{
    float refractive;

    if(ft_strncmp(to_upper(line), "NULL",4))
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

void    pattern_set(t_material *material, char *line, int fd)//not finished
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ;
    }
    int pattern_type;
    t_pattern *pattern;
    char **parameters;
    t_matrices *pattern_transformation;
    
    
    if(ft_strncmp(to_upper(parameters[0]), "CHECKERBOARD",12))
        pattern_type = CHECKERBORAD_PATTERN;
    else if(ft_strncmp(to_upper(parameters[0]), "RING",4))
        pattern_type = RING_PATTERN;
    else if(ft_strncmp(to_upper(parameters[0]), "STRIPE",6))
        pattern_type = STRIPE_PATTERN;
    else if(ft_strncmp(to_upper(parameters[0]), "GRADIENT",8))
        pattern_type = GRADIENT_PATTERN;
    else
        pattern_type = CHECKERBORAD_PATTERN; 
    pattern_transformation = pattern_transformation_set(fd); // here
    pattern = make_pattern(color_set(parameters[1]),color_set(parameters[2]),pattern_type, atoi(parameters[3]));
    set_material_pattern(material,pattern);
	set_transformation_pattern(material->pattern,pattern_transformation);
    free(line);
    free_split(parameters);
    return ;
}

float   specular_set(float default_specular, char *line)
{
     float specular;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (default_specular);
    }
    specular = float_parse(line);
    free(line);
    return specular;
}

float   diffuse_set(float default_diffuse, char *line)
{
    float diffuse;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (default_diffuse);
    }
    diffuse = float_parse(line);
    free(line);
    return diffuse;
}

t_matrices   *diameter_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    float d;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (matrix);
    }
    float_parse(line);
    transformed_matrix = multiply_matrices(scaling(make_tuple(d,d,d,VECTOR)),matrix);
    free(matrix);
    free(line);
    return(transformed_matrix);
}

void    height_set(float *_min, float *_max, char *line)
{
    char **numbers;
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        *_min = 0;
        *_max = 2;
        return ;
    }//use max() min 0 in height
    numbers = ft_split(line," ");
    *_min = float_parse(numbers[0]);
    *_max = *_min + max(float_parse(numbers[1]),0);
    free_split(numbers);
    free(line);
    return ;
    
}

int close_set(char *line)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (TRUE);
    }
    if(ft_strncmp(to_upper(line), "TRUE",4))
        return TRUE;
    else
        return FALSE;
}

t_tuple tuple_from_line(char *line)
{
    float   **vector;
    t_tuple _tuple;

    int i = 0;
    int j = 0;
    vector = ft_split(line,',');//free the array later
    //if length of the thing is more than 4 return parse_error
    _tuple.x = float_parse(vector[0]);
    _tuple.y = float_parse(vector[1]);
    _tuple.z = float_parse(vector[2]);
    if(ft_strncmp(ft_toupper(vector[3]),"POINT",5))
        _tuple.w = POINT;
    else
        _tuple.w = VECTOR;
    free_split(vector);
    return _tuple;
}

t_tuple tuple_set(char *line)
{
    float   **vector;
    t_tuple _tuple;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (make_tuple(0,0,1,0));
    }
    int i = 0;
    int j = 0;
    vector = ft_split(line,',');//free the array later
    //if length of the thing is more than 4 return parse_error
    _tuple.x = float_parse(vector[0]);
    _tuple.y = float_parse(vector[1]);
    _tuple.z = float_parse(vector[2]);
    if(ft_strncmp(ft_toupper(vector[3]),"POINT",5))
        _tuple.w = POINT;
    else
        _tuple.w = VECTOR;
    free_split(vector);
    free(line);
    return (_tuple);
//return a default if NULL
}

float   FOV_set(char *line)
{
    float FOV;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return (M_PI / 2);
    }
    FOV = degree_to_radian(float_parse(line));
    free(line);
    return FOV;
}
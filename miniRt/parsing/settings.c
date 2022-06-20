#include "./../includes/miniRt.h"

//ambient color ratio and ambient color if its not null

//make coordinate last when setting settings so that you get rotation then scale then translating
//coordiante is translate diameter is scaling // translating is last, and transformations come before that and after scaling for diameter and such

//for transformations we make loop until reach transEND applying each of the transformations

//free the line sent in settings

//color return red as default color


//make cone + cylinder close by default?

//when u return a matrice free the ones used to create that one

!!
//^^ return default settings!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//NULL case
//convert ANGLES to radian
//parse error function
//fill returns
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *to_upper(char *line);

float degree_to_radian(float angle)
{
    return (angle * (M_PI /180));
}

float float_parse(char *line)
{
    return(atof(line));
}

t_matrices  *coordinate_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    t_tuple translation_vector;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
    //TODO :atoi it in translation vector
    transformed_matrix = multiply_matrices(translation(translation_vector),matrix);
}

t_matrices  *orientation_vector_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
    //TODO :parse vector and wait to know what to do with it
}

t_tuple color_set(char *line)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
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
        return ();
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
        return ();
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
        return ();
    }
    refractive = float_parse(line);
    free(line);
    return refractive;
}

void    pattern_set(t_material *material, char *line)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
}

float   specular_set(float default_specular, char *line)
{
     float specular;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
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
        return ();
    }
    diffuse = float_parse(line);
    free(line);
    return diffuse;
}

t_matrices   *diameter_set(t_matrices *matrix, char *line)
{
    t_matrices *transformed_matrix;
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
}

void    height_set(float *min, float *max)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);  
        return ();
    }
    //get two numbers height + min
}

int close_set(char *line)
{
    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
//parse an int
}

t_tuple tuple_set(char *line)
{
    float   **vector;
    t_tuple tuple;

    if(ft_strncmp(to_upper(line), "NULL",4))
    {
        free(line);
        return ();
    }
    int i = 0;
    int j = 0;
    vector = ft_split(line,',');//free the array later
    //if length of the thing is more than 4 return parse_error
    tuple.x = float_parse(vector[0]);
    tuple.y = = float_parse(vector[1]);
    tuple.z = float_parse(vector[2]);
    if(ft_strncmp(ft_toupper(vector[4])),"POINT");
        tuple.w = POINT;
    else
        tuple.w = VECTOR;
    //free the line at the end before return

    //if read POINT make point if VECTOR make vector
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
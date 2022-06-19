#include "./../includes/miniRt.h"

//make coordinate last when setting settings so that you get rotation then scale then translating
//coordiante is translate diameter is scaling // translating is last, and transformations come before that and after scaling for diameter and such

//for transformations we make loop until reach transEND applying each of the transformations

//free the line sent in settings

//color return red as default color
//^^ return default settings

//make cone + cylinder close by default?

//when u return a matrice free the ones used to create that one
t_matrices  coordinate_set(t_matrices *matrix, char *line)
{

}

t_matrices  orientation_vector_set(t_matrices *matrix, char *line)
{

}

t_tuple color_set(char *line)
{

}

float   reflection_set(char *line)
{

}

float   transparency_set(char *line)
{

}

float   refractive_set(char *line)
{

}

void    pattern_set(t_material *material, char *line)
{

}

float   specular_set(float default_specular, char *line)
{

}

float   diffuse_set(float default_diffuse, char *line)
{

}

t_matrices   diameter_set(t_matrices *matrix, char *line)
{

}

void    height_set(float *min, float *max)
{

}

int close_set(char *line)
{

}

t_tuple tuple_set(char *line)
{
    //if read POINT make point if VECTOR make vector
//return a default if NULL
}

float   FOV_set(char *line)
{

}
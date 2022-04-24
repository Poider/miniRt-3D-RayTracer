#include "miniRt.h"

typedef struct  s_sphere{

    t_tuple origin;
    float radius;
    int object_id;
    t_matrices *transformation;
}               t_sphere;

typedef struct  s_intersections{
    float t;
    void *object;
    struct s_intersections *next;
}               t_intersections;

t_sphere *sphere();
//t_sphere *create_sphere(float radius, t_tuple origin, t_parameters *param);
void set_tranform(t_sphere *s,t_matrices *matrix);


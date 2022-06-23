#include "./../includes/miniRt.h"

void free_split(char **vector);
float degree_to_radian(float angle);
float float_parse(char *line);
t_matrices *rotation_make(t_matrices *matrix, char *line, char c);
t_matrices *translate_scale_make(t_matrices *matrix, char *line, char c);
t_matrices *shear_make(t_matrices *matrix, char *line);
t_matrices  *get_transformations(char *line);
t_matrices  *coordinate_set(t_matrices *matrix, char *line, int fd);
t_tuple color_set_no_free(char *line);
t_tuple color_set(char *line);
float   reflection_set(char *line);
float   transparency_set(char *line);
float   refractive_set(char *line);
t_matrices *pattern_transformation_set(int fd);
void    pattern_set(t_material *material, char *line, int fd, int is_3D);//not finished
float   specular_set(float default_specular, char *line);
float   diffuse_set(float default_diffuse, char *line);
t_matrices   *diameter_set(t_matrices *matrix, char *line, char c);
void    height_set(float *_min, float *_max, char *line);
int close_set(char *line);
t_tuple tuple_from_line(char *line);
t_tuple tuple_set(char *line);
float   FOV_set(char *line);
void parse_error();
int len(char **line);
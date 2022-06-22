
#include "./../includes/miniRt.h"
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void plane_settings(int fd,t_plane *shape,char *line);
void cylinder_settings(int fd,t_cylinder *shape,char *line);
void cone_settings(int fd,t_cone *shape,char *line);
void sphere_settings(int fd,t_sphere *shape,char *line);
t_object *sphere_make(int fd);
t_object *plane_make(int fd);
t_object *cylinder_make(int fd);
t_object *cone_make(int fd);
void ambient_make(t_world *world,int fd);
t_light *light_make(int fd);
void camera_make(t_camera *camera,int fd);
void parse_file(t_world *world,t_camera *camera,int fd);

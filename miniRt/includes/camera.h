#include "miniRt.h"

typedef struct s_camera
{
	int	hsize;
	int vsize;
	float FOV;
	t_matrices *transform;
	t_matrices *inverse_transform;
	float pixel_size;
	float half_width;
	float half_height;

}				t_camera;

t_camera make_camera(float hsize, float vsize, float field_of_view);
t_matrices *view_transformation(t_tuple from,t_tuple to, t_tuple up);
void		set_camera_transformation(t_camera *camera, t_tuple from,t_tuple to, t_tuple up);
t_ray 	ray_for_pixel(t_camera camera, int x, int y);
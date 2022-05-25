#include "miniRt.h"

#define BLACK make_color(0,0,0)
#define WHITE make_color(1,1,1)

t_tuple make_color(float red,float green,float blue);
int     get_color(t_tuple color);
t_tuple multiply_color(t_tuple c1, t_tuple c2);


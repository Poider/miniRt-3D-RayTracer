#include "includes/miniRt.h"

t_tuple make_color(float red,float green,float blue)
{
    t_tuple color;

    color = make_tuple(red,green,blue,POINT);
    return (color);
}
int     get_color(t_tuple color)
{
    int red;
    int green;
    int blue;

    red = max(0,min(255,round(color.x * 255)));
    green = max(0,min(255,round(color.y * 255)));
    blue = max(0,min(255,round(color.z * 255)));
    return (red << 16 | green << 8 | blue);
}



t_tuple multiply_color(t_tuple c1, t_tuple c2)
{
    t_tuple result_color;

    result_color.x = c1.x * c2.x;
    result_color.y = c1.y * c2.y;
    result_color.z = c1.z * c2.z;
    return (result_color);
}
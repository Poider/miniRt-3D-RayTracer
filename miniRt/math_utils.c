#include "./includes/miniRt.h"

int is_greater(float a, float b)
{
    if(a - b >= EPSILON)
        return TRUE;
    return FALSE;
}


float abs_float(float x)
{   
    if(x >= 0)
        return x;
    return -x;
}


float negate_val(float a)
{
	if (is_equal(a, 0))
		return (a);
	return (-a);
}

int is_equal(float a, float b)
{
    if(abs_float(a-b) < EPSILON)
        return TRUE;
    else
        return FALSE;
}

int is_lesser(float a, float b)
{
    if(a - b <= EPSILON)
        return TRUE;
    return FALSE;
}

int is_pos(int a)
{
    if (a >= 0)
        return (1);
    return (0);
}


float min(float a,float b)
{
    if (a < b)
        return (a);
    return (b);
}

float max(float a,float b)
{
    if (a > b)
        return (a);
    return (b);
}
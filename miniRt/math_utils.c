#include "./includes/miniRt.h"

float abs(float x)
{   
    if(x > 0)
        return x;
    else 
        return -x;
}

float is_equal(float a, float b)
{
    if(abs(a-b) < EPSILON)
        return TRUE;
    else
        return FALSE;
}


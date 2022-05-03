#include "includes/miniRt.h"

t_tuple  reflect(t_tuple in, t_tuple normal)
{
    float in_normal_dot = dot_product(in, normal);
    return tuple_normalize((substract_tuple(in,tuple_scalar_multiplication(normal,2 * in_normal_dot))));
}

t_tuple  lighting(t_material material, t_light light, t_tuple point, t_tuple eyev,t_tuple normalv)
{
    t_tuple diffuse,specular;
    t_tuple effective_color = multiply_color(material.color,light.intensity);
    
    // find the direction to the light source 
    t_tuple lightv = tuple_normalize(substract_tuple(light.position,point));
    
    // compute the ambient contribution 
    t_tuple ambient =  tuple_scalar_multiplication(effective_color, material.ambient);
    
    // light_dot_normal represents the cosine of the angle between the 
    // light vector and the normal vector. A negative number means the 
    // light is on the other side of the surface. 
    float light_dot_normal = dot_product(lightv, normalv);
    if (light_dot_normal < 0)
    {
        diffuse = BLACK
        specular = BLACK
    }
    else
    {
        // compute the diffuse contribution 
        diffuse = tuple_scalar_multiplication(tuple_scalar_multiplication(effective_color,material.diffuse),light_dot_normal);
        
        // reflect_dot_eye represents the cosine of the angle between the 
        // reflection vector and the eye vector. A negative number means the 
        // light reflects away from the eye. 
        t_tuple negate_lightv = negate_tuple(lightv);
        t_tuple reflectv = reflect(negate_lightv, normalv);
        float reflect_dot_eye = dot_product(reflectv, eyev);
        if (reflect_dot_eye < 0)
        {
            specular =  BLACK
        }
        else 
        {
            // compute the specular contribution 
            float factor = pow(reflect_dot_eye, material.shininess);
            //printf("%.2f \n",factor);
            t_tuple specular = tuple_scalar_multiplication(light.intensity, material.specular * factor);
        }
    }
    // Add the three contributions together to get the final shading 
    return (add_tuple(add_tuple(ambient, diffuse),specular));
}
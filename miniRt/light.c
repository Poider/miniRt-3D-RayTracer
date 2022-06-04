#include "includes/miniRt.h"

t_light make_light(t_tuple position, t_tuple intensity)
{
    t_light point_light;

    point_light.position = position;
    point_light.intensity = intensity;
    return (point_light);
}

t_tuple  reflect(t_tuple in, t_tuple normal)
{
    float in_normal_dot = dot_product(in, normal);
    return tuple_normalize((substract_tuple(in,tuple_scalar_multiplication(normal,2 * in_normal_dot))));
}

t_tuple  lighting(t_world world, t_precomputed comps, int is_shadow)
{
    t_tuple diffuse,specular;
	t_tuple effective_color;
	t_tuple color;
	if (comps.material.pattern)
		color = pattern_at_shape(comps.object->material.pattern , comps.over_point, comps.object);
	else
		color = comps.material.color;
    effective_color = multiply_color(color,world.light.intensity);
    // find the direction to the light source 
    t_tuple lightv = tuple_normalize(substract_tuple(world.light.position,comps.over_point));
    
    // compute the ambient contribution

    t_tuple ambient =  tuple_scalar_multiplication(effective_color, comps.material.ambient);
    
    // light_dot_normal represents the cosine of the angle between the 
    // light vector and the normal vector. A negative number means the 
    // light is on the other side of the surface. 
    float light_dot_normal = dot_product(lightv, comps.normalv);
	//is_shadow = TRUE;
    if (light_dot_normal < 0 || is_shadow == TRUE)
    {
        diffuse = BLACK;
        specular = BLACK;
    }
    else
    {
        // compute the diffuse contribution 
        diffuse = tuple_scalar_multiplication(tuple_scalar_multiplication(effective_color,comps.material.diffuse),light_dot_normal);
        
        // reflect_dot_eye represents the cosine of the angle between the 
        // reflection vector and the eye vector. A negative number means the 
        // light reflects away from the eye. 
        t_tuple negate_lightv = negate_tuple(lightv);
		//printf("negate  : %.2f %.2f %.2f %.2f\n",negate_lightv.x,negate_lightv.w,negate_lightv.z,negate_lightv.w);
        t_tuple reflectv = reflect(negate_lightv, comps.normalv);
		//printf("reflect  : %.2f %.2f %.2f %.2f\n",reflectv.x,reflectv.w,reflectv.z,reflectv.w);
        float reflect_dot_eye = dot_product(reflectv, comps.eyev);
        if (reflect_dot_eye < 0)
            specular =  BLACK;
        else 
        {
            // compute the specular contribution
            float factor = pow(reflect_dot_eye, comps.material.shininess);
            specular = tuple_scalar_multiplication(world.light.intensity, comps.material.specular * factor);
        }
    }
    // Add the three contributions together to get the final shading 
    return (add_tuple(add_tuple(ambient, diffuse),specular));
}

// color_at --> shade_hit -> reflected_color
// reflected_color  ->color_at
t_tuple color_at(t_world world, t_ray ray, int max_depth)
{
	t_intersections *list_intersections;
	t_intersections *hit_intersection;
	t_precomputed comps;

	list_intersections = intersect_word(world, ray);
	hit_intersection = hit(list_intersections);
	if (hit_intersection)
	{
		comps = prepare_computations(hit_intersection, ray, list_intersections);
		free_list_intersection(list_intersections);
		return (shade_hit(world, comps, max_depth));
	}
	return BLACK;
}

t_tuple	reflected_color(t_world world, t_precomputed comps, int max_depth)
{
	t_ray	reflected_ray;
	t_tuple	color;

	if (is_equal(comps.object->material.reflective, 0.00) || max_depth >= MAX_DEPTH)
		return (BLACK);
	reflected_ray = make_ray(comps.over_point, comps.reflecv);
	color = color_at(world, reflected_ray, max_depth);
	t_tuple res_color = tuple_scalar_multiplication(color, comps.object->material.reflective);
	//printf("%.2f %.2f %.2f %.2f\n",res_color.x,res_color.y,res_color.z,res_color.w);
	return (res_color);
}


t_tuple	refracted_color(t_world world, t_precomputed comps, int max_depth)
{
	t_ray	refracted_ray;
	float	n_ratio;
	t_tuple color;

	if (is_equal(comps.object->material.transparency, 0.00) || max_depth >= MAX_DEPTH)
		return (BLACK);
	n_ratio = comps.n1 / comps.n2;
	float	cos_i = dot_product(comps.eyev, comps.normalv);
	float	sin2_t = (n_ratio * n_ratio) * (1 - cos_i * cos_i);
	if (sin2_t > 1)
		return (BLACK);
	float cos_t = sqrt(1.0 - sin2_t);
	t_tuple direction = substract_tuple(tuple_scalar_multiplication(comps.normalv, (n_ratio * cos_i - cos_t)) ,
										tuple_scalar_multiplication(comps.eyev ,n_ratio)
									);
	refracted_ray = make_ray(comps.under_point, direction);
	color = color_at(world, refracted_ray, max_depth);
	t_tuple res_color = tuple_scalar_multiplication(color, comps.object->material.transparency);
	return (res_color);
}



t_tuple shade_hit(t_world world, t_precomputed comps, int max_depth)
{
	int		is_shadow;
	t_tuple	color_surface;
	t_tuple	color_reflection;
	t_tuple	color_refraction;

	is_shadow = is_shadowed(&world,comps.over_point);
	color_surface = lighting(world, comps, is_shadow);
	color_reflection = reflected_color(world, comps,max_depth + 1);
	color_refraction = refracted_color(world, comps , max_depth + 1);
	return (add_tuple(add_tuple(color_surface, color_reflection), color_refraction));
}

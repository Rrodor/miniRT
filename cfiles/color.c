/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 17:25:51 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "miniRT.h"
#include "ray.h"
#include <stdlib.h>

t_rgb	*init_color(double r, double g, double b)
{
	t_rgb	*color;

	color = (t_rgb *)malloc(sizeof(t_rgb));
	if (!color)
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_rgb	*get_color(t_ray *ray, t_list *objects)
{
	float	t;
	float	t1;
	t_rgb	*color;
	t_sp	*obj;

	t = 1000.0;
	color = NULL;
	while (objects)
	{
		obj = (t_sp *)objects->content;
		if (ft_strncmp(obj->id, "pl", 2) == 0)
		{
			t1 = hit_plane(objects->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				if (color)
					free(color);
				color = color_from_plane(ray, t, obj->color);
			}
		}
		if (ft_strncmp(obj->id, "sp", 2) == 0)
		{
			t1 = hit_sphere(objects->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				if (color)
					free(color);
				color = color_from_sphere(ray, t, obj->color);
			}
		}
		if (ft_strncmp(obj->id, "cy", 2) == 0)
		{
			t1 = hit_cylinder(objects->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				if (color)
					free(color);
				color = color_from_cylinder(ray, t, obj->color);
			}
		}
		objects = objects->next;
	}
	if (t > 0 && t < 1000.0)
		return (color);
	return(init_color(0, 0, 0));
}

int encode_rgb(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}

t_rgb	*lengthToColor(double t, t_rgb	*rgb)
{
	t_rgb	*color;
	double	f;
	double	test;

	if (t <= 0.0)
		return (init_color(0, 0, 0)); // Return ambient color of the object
	if (!rgb)
		return (init_color(0, 0, 0)); // Same as above
	test = t;
	f = (1 / test);
	color = init_color(rgb->r * f, rgb->g * f, rgb->b * f);
	return (color);
}

t_rgb	*color_from_cylinder(t_ray *ray, double t, t_rgb *color)
{
	double	intensity;
	double	diffuse;
	t_vec	*hit_point;
	t_vec	*light_pos;
	t_vec	*light_dir;
	t_vec	*cylinder_pos;
	t_vec	*surface_normal;
	t_vec	*tmp;

	intensity = 1.0; // get_intensity();
	light_pos = vec_new(1, 1, 0); // get_light_pos();
	hit_point = ray_at(ray, t);
	cylinder_pos = vec_new(0, 0, -1.5); // get_cylinder_pos();
	tmp = vec_sub(hit_point, cylinder_pos);
	surface_normal = vec_unit(tmp);
	free(tmp);
	tmp = vec_sub(light_pos, hit_point);
	light_dir = vec_unit(tmp);
	free(tmp);
	free(light_pos);
	free(hit_point);
	free(cylinder_pos);
	diffuse = vec_dot(surface_normal, light_dir) * intensity;
	free(surface_normal);
	free(light_dir);
	double	ambient = 0.1; // get_ambient();
	if (diffuse < ambient)
		diffuse = ambient;
	return (init_color(color->r * diffuse, color->g * diffuse, color->b * diffuse));
}

t_rgb	*color_from_plane(t_ray *ray, double t, t_rgb *color)
{
	double	intensity;
	double	diffuse;
	t_vec	*hit_point;
	t_vec	*light_pos;
	t_vec	*light_dir;
	t_vec	*surface_normal;
	t_vec	*tmp;

	surface_normal = vec_new(0, 1, 0); // get_surface_normal();
	intensity = 1.0; // get_intensity();
	light_pos = vec_new(1, 1, 0); // get_light_pos();
	hit_point = ray_at(ray, t);
	tmp = vec_sub(light_pos, hit_point);
	light_dir = vec_unit(tmp);
	free(tmp);
	free(light_pos);
	free(hit_point);
	diffuse = vec_dot(surface_normal, light_dir) * intensity;
	free(surface_normal);
	free(light_dir);
	double	ambient = 0.1; // get_ambient();
	if (diffuse < ambient)
		diffuse = ambient;
	return (init_color(color->r * diffuse, color->g * diffuse, color->b * diffuse));
}

t_rgb	*color_from_sphere(t_ray *ray, double t, t_rgb *color)
{
	double	intensity;
	double	diffuse;
	t_vec	*hit_point;
	t_vec	*light_pos;
	t_vec	*light_dir;
	t_vec	*sphere_pos;
	t_vec	*surface_normal;
	t_vec	*tmp;

	intensity = 1.0; // get_intensity();
	light_pos = vec_new(1, 1, 0); // get_light_pos();
	hit_point = ray_at(ray, t);
	sphere_pos = vec_new(0, 0, -1.6); // get_sphere_pos();
	tmp = vec_sub(hit_point, sphere_pos);
	surface_normal = vec_unit(tmp);
	free(tmp);
	tmp = vec_sub(light_pos, hit_point);
	light_dir = vec_unit(tmp);
	free(tmp);
	free(light_pos);
	free(hit_point);
	diffuse = vec_dot(surface_normal, light_dir) * intensity;
	free(surface_normal);
	free(sphere_pos);
	free(light_dir);
	double	ambient = 0.1; // get_ambient();
	if (diffuse < ambient)
		diffuse = ambient;
	return (init_color(color->r * diffuse, color->g * diffuse, color->b * diffuse));
}

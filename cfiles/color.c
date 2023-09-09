/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/09/09 18:27:18 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "miniRT.h"
#include "ray.h"
#include <stdlib.h>
#include "lighting.h"

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

t_vec	*calculate_cylinder_normal(t_vec *hit, t_cy *cylinder)
{
	t_vec	*base_to_hit;
	t_vec	*closest_point_on_axis;
	t_vec	*normal;
	double	t;

	base_to_hit = vec_sub(hit, cylinder->pos);
	t = vec_dot(base_to_hit, cylinder->dir);
	closest_point_on_axis = vec_add(cylinder->pos, vec_mult_num(cylinder->dir, t));
	normal = vec_sub(hit, closest_point_on_axis);
	free(closest_point_on_axis);
	free(base_to_hit);
	return (vec_unit(normal));
}

double	find_intersection(t_ray *shadow_ray, t_list **test, t_sp *cur_obj)
{
	double	t;
	double	t1;
	t_list	*all_obj;

	t = 1000.0;
	all_obj = *test;
	while (all_obj)
	{
		if (obj_cmp(cur_obj, all_obj->content) != 0)
		{
			if (ft_strncmp(((t_pl*)all_obj->content)->id, "pl", 2) == 0)
				t1 = hit_plane(all_obj->content, shadow_ray);
			else if (ft_strncmp(((t_sp*)all_obj->content)->id, "sp", 2) == 0)
				t1 = hit_sphere(all_obj->content, shadow_ray);
			else if (ft_strncmp(((t_cy*)all_obj->content)->id, "cy", 2) == 0)
				t1 = hit_cylinder(all_obj->content, shadow_ray);
			if (t1 > 0 && t1 < t)
				return (t1);
		}
		all_obj = all_obj->next;
	}
	return (t);
}

t_rgb	*shading(t_list *all_obj, t_sp *cur_obj, t_vec *hit, t_lighting *light, t_list **test)
{
	t_vec	*normal;
	t_vec	*light_dir;
	double	diffuse;

	light_dir = vec_unit(vec_sub(light->light_pos, hit));
	if (ft_strncmp(((t_pl*)all_obj->content)->id, "pl", 2) == 0)
		normal = vec_unit(((t_pl*)all_obj->content)->dir);
	else if (ft_strncmp(((t_sp*)all_obj->content)->id, "sp", 2) == 0)
		normal = vec_unit(vec_sub(hit, ((t_sp*)all_obj->content)->pos));
	else if (ft_strncmp(((t_cy*)all_obj->content)->id, "cy", 2) == 0)
		normal = calculate_cylinder_normal(hit, ((t_cy*)all_obj->content));

	// Shadow
	t_ray	*shadow_ray;
	t_vec	*hit_point_nudged;
	double	shadow_t;
	double	distance_to_light;
	hit_point_nudged = vec_add(hit, vec_mult_num(normal, 0.001));
	shadow_ray = ray_new(hit_point_nudged, light_dir);
	shadow_t = find_intersection(shadow_ray, test, cur_obj);
	distance_to_light = vec_len(vec_sub(light->light_pos, hit));

	if (shadow_t < distance_to_light)
		diffuse = 0;
	else
	{
		double dot_val = vec_dot(normal, light_dir);
		if (dot_val < 0)
			dot_val = light->ambient_intensity / 2;
		diffuse = dot_val * light->intensity;
	}
	if (diffuse < light->ambient_intensity)
		diffuse = light->ambient_intensity;

	free(normal);
	free(light_dir);
	return (init_color(cur_obj->color->r * diffuse, cur_obj->color->g * diffuse, cur_obj->color->b * diffuse));
}

t_rgb	*get_color(t_lighting *light, t_ray *ray, t_list **objects)
{
	float	t;
	float	t1;
	t_rgb	*color;
	t_sp	*obj;
	t_list	*tmp;

	t = 1000.0;
	tmp = *objects;
	while (tmp)
	{
		obj = (t_sp *)tmp->content;
		if (ft_strncmp(obj->id, "pl", 2) == 0)
		{
			t1 = hit_plane(tmp->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = shading(tmp, obj, ray_at(ray, t), light, objects);
			}
		}
		if (ft_strncmp(obj->id, "sp", 2) == 0)
		{
			t1 = hit_sphere(obj, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = shading(tmp, obj, ray_at(ray, t), light, objects);
			}
		}
		if (ft_strncmp(obj->id, "cy", 2) == 0)
		{
			t1 = hit_cylinder(tmp->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = shading(tmp, obj, ray_at(ray, t), light, objects);
			}
		}
		tmp = tmp->next;
	}
	if (t > 0 && t < 1000.0)
		return (color);
		//return (lengthToColor(t, color));
	return(init_color(0, 0, 0));
}

int encode_rgb(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}

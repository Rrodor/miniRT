/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/09/12 16:05:32 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "miniRT.h"
#include "ray.h"
#include <stdlib.h>
#include "lighting.h"

/*
typdef struct	s_process_params
{
	t_list		*cur_obj;
	t_ray		*ray;
	t_sp		*obj;
	t_lighting	*light;
	t_list		**objects;
}				t_process_params;



t_vec	*get_normal(t_list *all_obj, t_vec *hit)
{
	t_vec	*normal;
	t_vec	*tmp;

	if (ft_strncmp(((t_pl*)all_obj->content)->id, "pl", 2) == 0)
		normal = vec_unit(((t_pl*)all_obj->content)->dir);
	else if (ft_strncmp(((t_sp*)all_obj->content)->id, "sp", 2) == 0)
	{
		tmp = vec_sub(hit, ((t_sp*)all_obj->content)->pos);
		normal = vec_unit(tmp);
		free(tmp);
	}
	else if (ft_strncmp(((t_cy*)all_obj->content)->id, "cy", 2) == 0)
		normal = calculate_cylinder_normal(hit, ((t_cy*)all_obj->content));
	return (normal);
}

t_ray	*prepare_shadow_ray(t_vec *normal, t_vec *hit, t_vec *light_dir)
{
	t_vec	*hit_point_nudged;
	t_vec	*tmp;
	t_vec	*shadow_ray;

	tmp = vec_mult_num(normal, 0.001);
	hit_point_nudged = vec_add(hit, tmp);
	shadow_ray = ray_new(hit_point_nudged, light_dir);
	free(tmp);
	free(hit_point_nudged);
	return (shadow_ray);
}

double	get_diffuse(t_diffuse_params *params)
{
	double	diffuse;

	if (params->shadow_t < params->distance_to_light)
		diffuse = 0;
	else
	{
		double dot_val = vec_dot(params->normal, params->light_dir);
		if (dot_val < 0)
			diffuse = params->light->ambient_intensity / 2;
		diffuse = dot_val * params->light->intensity;
	}
	if (diffuse < params->light->ambient_intensity)
		diffuse = params->light->ambient_intensity;
	return (diffuse);
}

t_rgb	*shading(t_list *all_obj, t_sp *cur_obj, t_vec *hit, t_lighting *light, t_list **test)
{
	t_vec	*normal;
	t_vec	*light_dir;
	double	diffuse;
	t_vec	*tmp;

	tmp = vec_sub(light->light_pos, hit);
	light_dir = vec_unit(tmp);
	free(tmp);
	normal = calculate_normal(all_obj, hit);
	diffuse = calculate_diffuse(normal, light_dir, light);
	free(normal);
	free(light_dir);
	return (init_color(cur_obj->color->r * diffuse, cur_obj->color->g * diffuse, cur_obj->color->b * diffuse));
}

t_rgb	*process_object_hit(t_list *obj, float t1, t_ray *ray, t_lighting *light) */


t_rgb	*shading(t_list *all_obj, t_sp *cur_obj, t_vec *hit, t_lighting *light, t_list **test)
{
	t_vec	*normal;
	t_vec	*light_dir;
	double	diffuse;
	t_vec	*tmp;

	tmp = vec_sub(light->light_pos, hit);
	light_dir = vec_unit(tmp);
	free(tmp);
	if (ft_strncmp(((t_pl*)all_obj->content)->id, "pl", 2) == 0)
		normal = vec_unit(((t_pl*)all_obj->content)->dir);
	else if (ft_strncmp(((t_sp*)all_obj->content)->id, "sp", 2) == 0)
	{
		tmp = vec_sub(hit, ((t_sp*)all_obj->content)->pos);
		normal = vec_unit(tmp);
		free(tmp);
	}
	else if (ft_strncmp(((t_cy*)all_obj->content)->id, "cy", 2) == 0)
		normal = calculate_cylinder_normal(hit, ((t_cy*)all_obj->content));

	// Shadow
	t_ray	*shadow_ray;
	t_vec	*hit_point_nudged;
	double	shadow_t;
	double	distance_to_light;
	tmp = vec_mult_num(normal, 0.001);
	hit_point_nudged = vec_add(hit, tmp);
	free(tmp);
	shadow_ray = ray_new(hit_point_nudged, light_dir);
	shadow_t = find_intersection(shadow_ray, test, cur_obj);
	tmp = vec_sub(light->light_pos, hit);
	distance_to_light = vec_len(tmp);
	free(tmp);

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
	ray_free(shadow_ray);
	free(hit_point_nudged);
	return (init_color(cur_obj->color->r * diffuse, cur_obj->color->g * diffuse, cur_obj->color->b * diffuse));
}

t_rgb	*get_color(t_lighting *light, t_ray *ray, t_list **objects)
{
	float	t;
	float	t1;
	t_rgb	*color;
	t_sp	*obj;
	t_list	*tmp;
	t_vec	*tmpvec;

	t = 1000.0;
	tmp = *objects;
	color = NULL;
	while (tmp)
	{
		obj = (t_sp *)tmp->content;
		if (ft_strncmp(obj->id, "pl", 2) == 0)
		{
			t1 = hit_plane(tmp->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				tmpvec = ray_at(ray, t);
				if (color)
					free(color);
				color = shading(tmp, obj, tmpvec, light, objects);
				free(tmpvec);
			}
		}
		if (ft_strncmp(obj->id, "sp", 2) == 0)
		{
			t1 = hit_sphere(obj, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				tmpvec = ray_at(ray, t);
				if (color)
					free(color);
				color = shading(tmp, obj, tmpvec, light, objects);
				free(tmpvec);
			}
		}
		if (ft_strncmp(obj->id, "cy", 2) == 0)
		{
			t1 = hit_cylinder(tmp->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				tmpvec = ray_at(ray, t);
				if (color)
					free(color);
				color = shading(tmp, obj, tmpvec, light, objects);
				free(tmpvec);
			}
		}
		tmp = tmp->next;
	}
	if (t > 0 && t < 1000.0)
		return (color);
	return(init_color(0, 0, 0));
}

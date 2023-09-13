/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 20:30:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "miniRT.h"
#include "ray.h"
#include <stdlib.h>
#include "lighting.h"

t_vec	*get_normal(t_list *all_obj, t_vec *hit)
{
	t_vec	*normal;
	t_vec	*tmp;

	if (ft_strncmp(((t_pl *)all_obj->content)->id, "pl", 2) == 0)
		normal = vec_unit(((t_pl *)all_obj->content)->dir);
	else if (ft_strncmp(((t_sp *)all_obj->content)->id, "sp", 2) == 0)
	{
		tmp = vec_sub(hit, ((t_sp *)all_obj->content)->pos);
		normal = vec_unit(tmp);
		free(tmp);
	}
	else if (ft_strncmp(((t_cy *)all_obj->content)->id, "cy", 2) == 0)
		normal = calculate_cylinder_normal(hit, ((t_cy *)all_obj->content));
	return (normal);
}

double	get_diffuse(t_vars **vars, t_vec *hit, t_vec *normal, double shadow_t)
{
	t_vec	*tmp;
	double	val;
	double	diffuse;
	t_vec	*light_dir;

	tmp = vec_sub((*vars)->lighting->light_pos, hit);
	light_dir = vec_unit(tmp);
	free(tmp);
	tmp = vec_sub((*vars)->lighting->light_pos, hit);
	val = vec_len(tmp);
	free(tmp);
	if (shadow_t < val)
		diffuse = 0;
	else
	{
		val = vec_dot(normal, light_dir);
		if (val < 0)
			val = (*vars)->lighting->ambient_intensity / 2;
		diffuse = val * (*vars)->lighting->intensity;
	}
	if (diffuse < (*vars)->lighting->ambient_intensity)
		diffuse = (*vars)->lighting->ambient_intensity;
	free(light_dir);
	return (diffuse);
}

t_rgb	*shading(t_list *all_obj, t_sp *cur_obj, t_vec *hit, t_vars **vars)
{
	t_vec	*normal;
	t_vec	*light_dir;
	double	diffuse;
	t_vec	*tmp;

	tmp = vec_sub((*vars)->lighting->light_pos, hit);
	light_dir = vec_unit(tmp);
	free(tmp);
	normal = get_normal(all_obj, hit);
	tmp = vec_mult_num(normal, 0.001);
	diffuse = get_diffuse(vars, hit, normal,
			find_intersection(ray_new(vec_add(hit, tmp), light_dir, 1),
				&(*vars)->objs, cur_obj));
	free(normal);
	free(light_dir);
	free(hit);
	free(tmp);
	return (init_color(cur_obj->color->r * diffuse,
			cur_obj->color->g * diffuse, cur_obj->color->b * diffuse));
}

t_rgb	*get_color(t_vars **vars, t_ray *ray)
{
	float	t;
	float	t1;
	t_rgb	*color;
	t_list	*tmp;

	t1 = -1;
	t = 1000.0;
	tmp = (*vars)->objs;
	color = NULL;
	while (tmp)
	{
		t1 = getcollision(tmp->content, ray);
		if (t1 > 0 && t1 < t)
		{
			t = t1;
			if (color)
				free(color);
			color = shading(tmp, tmp->content, ray_at(ray, t), vars);
		}
		tmp = tmp->next;
	}
	if (t > 0 && t < 1000.0)
		return (color);
	return (init_color(0, 0, 0));
}

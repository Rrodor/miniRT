/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:35:58 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/11 16:31:08 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	t_vec	*tmp;
	double	t;

	base_to_hit = vec_sub(hit, cylinder->pos);
	t = vec_dot(base_to_hit, cylinder->dir);
	tmp = vec_mult_num(cylinder->dir, t);
	closest_point_on_axis = vec_add(cylinder->pos, tmp);
	free(tmp);
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
			if (ft_strncmp(((t_pl *) all_obj->content)->id, "pl", 2) == 0)
				t1 = hit_plane(all_obj->content, shadow_ray);
			else if (ft_strncmp(((t_sp *)all_obj->content)->id, "sp", 2) == 0)
				t1 = hit_sphere(all_obj->content, shadow_ray);
			else if (ft_strncmp(((t_cy *)all_obj->content)->id, "cy", 2) == 0)
				t1 = hit_cylinder(all_obj->content, shadow_ray);
			if (t1 > 0 && t1 < t)
				return (t1);
		}
		all_obj = all_obj->next;
	}
	return (t);
}

int	encode_rgb(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}

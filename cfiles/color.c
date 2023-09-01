/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/08/31 21:21:19 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"
#include "miniRT.h"
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
	while (objects)
	{
		obj = (t_sp *)objects->content;
		if (ft_strncmp(obj->id, "pl", 2) == 0)
		{
			t1 = hit_plane(objects->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = obj->color;
			}
		}
		if (ft_strncmp(obj->id, "sp", 2) == 0)
		{
			t1 = hit_sphere(obj->pos, 0.5, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = obj->color;
			}
		}
		if (ft_strncmp(obj->id, "cy", 2) == 0)
		{
			t1 = hit_cylinder(objects->content, ray);
			if (t1 > 0 && t1 < t)
			{
				t = t1;
				color = obj->color;
			}
		}
		objects = objects->next;
	}
	if (t > 0 && t < 1000.0)
		return (lengthToColor(t, color));
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
		return (init_color(0, 0, 0));
	if (!rgb)
		return (init_color(0, 0, 0));
	test = t;
	f = (1 / test);
	//f *= 1.5;
	color = init_color(rgb->r * f, rgb->g * f, rgb->b * f);
	return (color);
}

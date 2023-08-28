/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/08/27 12:39:56 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ray.h"
#include "miniRT.h"
#include <stdlib.h>

t_rgb	*init_color(int r, int g, int b)
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

t_rgb	*get_color(t_ray *ray)
{
	t_vec	*p_point;
	//t_pl	*plane;
	//int		i;

	//plane = (t_pl *)malloc(sizeof(t_pl));
	//plane->pos = vec_new(5, 5, 5);
	//plane->dir = vec_new(2, 2, 1);
	p_point = vec_new(0, 0, -1);
	//i = hit_plane(plane, ray);
	if (hit_sphere(p_point, 0.5, ray))
		return (init_color(255, 0, 0)); // red
	/*else if (i > 0)
		return (init_color(0, 255 / i, 0)); // green*/
	else
		return (init_color(0, 0, 0)); // black
}

int encode_rgb(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}
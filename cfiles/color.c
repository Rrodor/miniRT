/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 13:33:22 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "position.h"
#include "ray.h"
#include <stdlib.h>

t_rgb   *init_color(int r, int g, int b)
{
    t_rgb   *color;

    color = (t_rgb *)malloc(sizeof(t_rgb));
    if (!color)
        return (NULL);
    color->r = r;
    color->g = g;
    color->b = b;
    return (color);
}

t_rgb    *get_color(t_ray *ray)
{
    t_rgb   *color;
    t_pos   *point;

    point = new_point(0, 0, -1);
    color = init_color(0, 0, 0);
    if (hit_sphere(point, 0.5, ray))
        return (init_color(255, 0, 0)); // red
    else
        return (init_color(0, 0, 0)); // black
}

int encode_rgb(t_rgb *rgb)
{
    return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}
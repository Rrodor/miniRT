/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:23 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 11:51:44 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "position.h"
#include "ray.h"

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
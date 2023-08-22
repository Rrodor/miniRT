/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:27:33 by aramon            #+#    #+#             */
/*   Updated: 2023/08/22 18:20:23 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// This part should move to a calculus / intersection file
// Only here for testing purposes
// Checks if the ray intersects with the sphere
int hit_sphere(t_pos *center, double radius, t_ray *ray)
{
    t_vec   *oc;
    double  a;
    double  b;
    double  c;

    oc = vec_sub(ray->ori, center);
    a = vec_dot(ray->dir, ray->dir);
    b = 2.0 * vec_dot(oc, ray->dir);
    c = vec_dot(oc, oc) - radius * radius;
    if (b * b - 4 * a * c >= 0)
        return (1);
    return (0);
}

void    ray(t_ray *ray)
{
    t_pos   *point;

    point = new_point(0, 0, -1);
    /*if (hit_sphere(point, 0.5, ray))
        printf("Hit\n");
    else
        printf("Miss\n");*/
}
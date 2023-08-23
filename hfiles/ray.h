/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:25:02 by aramon            #+#    #+#             */
/*   Updated: 2023/08/23 12:01:34 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "position.h"

typedef struct	s_ray
{
    t_vec	    *ori;
    t_vec       *dir;
    double      tMax;
}				t_ray;

// ray.c
t_ray   *ray_new(t_vec *origin, t_vec *direction);
void    ray_copy(t_ray *dst, t_ray *src);
void    ray_free(t_ray *ray);
t_vec   *ray_calculate(t_ray *ray, double t);
int     hit_sphere(t_pos *center, double radius, t_ray *ray);

#endif
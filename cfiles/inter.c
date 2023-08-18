/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:38:54 by aramon            #+#    #+#             */
/*   Updated: 2023/08/18 19:18:59 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void    inter_new(t_inter *inter, t_ray *ray)
{
    ray_copy(inter->ray, ray);
    inter->t = ray->tMax;
    // Shape assignment
}

void    inter_copy(t_inter *dst, t_inter *src)
{
    ray_copy(dst->ray, src->ray);
    dst->t = src->t;
    // Shape assignment
}

t_vec   *inter_pos(t_inter *inter)
{
    return (ray_calculate(inter->ray, inter->t));
}
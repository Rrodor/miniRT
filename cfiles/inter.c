/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:38:54 by aramon            #+#    #+#             */
/*   Updated: 2023/09/07 19:30:56 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	inter_new(t_inter *inter, t_ray *ray)
{
	ray_copy(inter->ray, ray);
	inter->t = ray->tmax;
}

void	inter_copy(t_inter *dst, t_inter *src)
{
	ray_copy(dst->ray, src->ray);
	dst->t = src->t;
}

t_vec	*inter_pos(t_inter *inter)
{
	return (ray_calculate(inter->ray, inter->t));
}

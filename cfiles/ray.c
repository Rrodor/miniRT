/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:26:31 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 05:24:29 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

t_ray	*ray_new(t_vec *origin, t_vec *direction, int f)
{
	t_ray	*ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->ori = vec_new(origin->x, origin->y, origin->z);
	ray->dir = vec_new(direction->x, direction->y, direction->z);
	ray->tmax = RAY_MAX;
	if (ray->ori == NULL || ray->dir == NULL)
	{
		ray_free(ray);
		return (NULL);
	}
	if (f == 1)
		free(origin);
	return (ray);
}

void	ray_copy(t_ray *dst, t_ray *src)
{
	if (!dst || !src)
		return ;
	vec_copy(dst->ori, src->ori);
	vec_copy(dst->dir, src->dir);
	dst->tmax = src->tmax;
}

t_vec	*ray_calculate(t_ray *ray, double t)
{
	t_vec	*vec;

	vec = vec_new(ray->ori->x + t * ray->dir->x,
			ray->ori->y + t * ray->dir->y,
			ray->ori->z + t * ray->dir->z);
	return (vec);
}

t_vec	*ray_at(t_ray *ray, double t)
{
	t_vec	*vec;

	vec = vec_new(ray->ori->x + t * ray->dir->x,
			ray->ori->y + t * ray->dir->y,
			ray->ori->z + t * ray->dir->z);
	return (vec);
}

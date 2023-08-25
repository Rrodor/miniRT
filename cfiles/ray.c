/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:26:31 by aramon            #+#    #+#             */
/*   Updated: 2023/08/25 18:52:18 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray   *ray_new(t_vec *origin, t_vec *direction)
{
    t_ray   *ray;

    ray = (t_ray *)malloc(sizeof(t_ray));
    if (!ray)
        return (NULL);
    ray->ori = vec_new(origin->x, origin->y, origin->z);
    ray->dir = vec_new(direction->x, direction->y, direction->z);
    ray->tMax = RAY_MAX;
    if (ray->ori == NULL || ray->dir == NULL)
    {
        ray_free(ray);
        return (NULL);
    }
    return (ray);
}

void    ray_copy(t_ray *dst, t_ray *src)
{
    if (!dst || !src)
        return ;
    vec_copy(dst->ori, src->ori);
    vec_copy(dst->dir, src->dir);
    dst->tMax = src->tMax;
}

void    ray_free(t_ray *ray)
{
    if (!ray)
        return ;
    vec_free(ray->ori);
    vec_free(ray->dir);
}

t_vec   *ray_calculate(t_ray *ray, double t)
{
    t_vec   *vec;

    vec = vec_new(ray->ori->x + t * ray->dir->x,
        ray->ori->y + t * ray->dir->y,
        ray->ori->z + t * ray->dir->z);
    return (vec);
}

// This part should move to a calculus / intersection file
// Only here for testing purposes
// Checks if the ray intersects with the sphere
int hit_sphere(t_pos *center, double radius, t_ray *ray)
{
    t_vec   *oc;
    double  a;
    double  b;
    double  c;

    oc = vec_new(ray->ori->x - center->x, ray->ori->y - center->y, ray->ori->z - center->z);
    a = vec_dot(ray->dir, ray->dir);
    b = 2.0 * vec_dot(oc, ray->dir);
    c = vec_dot(oc, oc) - radius * radius;
    if (b * b - 4 * a * c >= 0)
        return (1);
    return (0);
}

int	hit_plane(t_pl *plane, t_ray *ray)
{
	float	denom;
	float	t;
	t_vec	*ray_o;
	t_vec	*pl_o;

	ray_o = vec_new(ray->ori->x, ray->ori->y, ray->ori->z);
	pl_o = vec_new(plane->pos->x, plane->pos->y, plane->pos->z);

	denom = vec_dot(plane->dir, pl_o);
	if (vec_dot(ray->dir, plane->dir) == 0)
		return (0);
	//t = vec_dot(vec_sub(plane->pos, ray->ori), plane->dir) / denom;
	t = (denom - vec_dot(plane->dir, ray_o)) / vec_dot(plane->dir, ray->dir);
	printf("t = %f\n", t);
	if (t < 0)
		return (0);
	if (t > 100)
		return (0);
	return (t / 10);
}

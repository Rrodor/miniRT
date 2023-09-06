/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:26:31 by aramon            #+#    #+#             */
/*   Updated: 2023/09/05 16:49:41 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

t_ray	*ray_new(t_vec *origin, t_vec *direction)
{
	t_ray	*ray;

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

void	ray_copy(t_ray *dst, t_ray *src)
{
	if (!dst || !src)
		return ;
	vec_copy(dst->ori, src->ori);
	vec_copy(dst->dir, src->dir);
	dst->tMax = src->tMax;
}

void	ray_free(t_ray *ray)
{
	if (!ray)
		return ;
	vec_free(ray->ori);
	vec_free(ray->dir);
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

double	hit_sphere(t_vec *center, double radius, t_ray *ray)
{
	t_vec	*oc;
	double	a;
	double	b;
	double	c;
	double	d;
	float	t;


	oc = vec_new(ray->ori->x - center->x, ray->ori->y - center->y, ray->ori->z - center->z);
	a = vec_dot(ray->dir, ray->dir);
	b = 2.0 * vec_dot(oc, ray->dir);
	c = vec_dot(oc, oc) - radius * radius;
	d = b * b - 4 * a * c;
	if (d > -0.0000001 && d < 0.0000001)
	{
		t = -b / (2.0 * a);
		if (t > 0 && t < 1000.0)
			return (t);
	}
	if (d > 0)
	{
		t = (-b - sqrt(d)) / (2.0 * a);
		if (t > 0 && t < 1000.0)
			return (t);
	}
	return (0);
}

double	hit_plane(t_pl *plane, t_ray *ray)
{
	double denom;
	double	t;

	t = 0;

	denom = vec_dot(plane->dir, plane->pos);
	if (vec_dot(ray->dir, plane->dir) == 0)
		return (0);
	t = (denom - vec_dot(plane->dir, ray->ori)) / vec_dot(plane->dir, ray->dir);
	if (t < 0.0)
		return (0);
	if (t > 1000.0)
		return (0);
	return (t);
}

double	hit_cylinder(t_cy *cyl, t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	t;
	t_pl	*plane;

	a = ray->dir->x * ray->dir->x + ray->dir->z * ray->dir->z;
	b = 2 * (ray->dir->x * (ray->ori->x - cyl->pos->x) + ray->dir->z * (ray->ori->z - cyl->pos->z));
	c = (ray->ori->x - cyl->pos->x) * (ray->ori->x - cyl->pos->x) + (ray->ori->z - cyl->pos->z) * (ray->ori->z - cyl->pos->z) - cyl->radius * cyl->radius;
	d = b * b - 4 * a * c;
	if (d > 0)
	{
		t = (-b - sqrt(d)) / (2.0 * a);
		if (t > 0.0 && t < 1000.0)
		{
			if (cyl->height  + cyl->pos->y > ray->ori->y + t * ray->dir->y && cyl->pos->y - cyl->height < ray->ori->y + t * ray->dir->y)
				return (t);
			else
			{
				t = (-b + sqrt(d)) / (2.0 * a);
				if (cyl->height  + cyl->pos->y > ray->ori->y + t * ray->dir->y && cyl->pos->y - cyl->height < ray->ori->y + t * ray->dir->y)
				{
					plane = (t_pl *)malloc(sizeof(t_pl));
					if (cyl->pos->y - cyl->height < 0)
						plane->pos = vec_new(cyl->pos->x, cyl->pos->y + cyl->height, cyl->pos->z);
					else
						plane->pos = vec_new(cyl->pos->x, cyl->pos->y - cyl->height, cyl->pos->z);
					plane->dir = cyl->dir;
					t = hit_plane(plane, ray);
					if (t > 0 && t < 1000.0)
						return (t);
					//free(plane);
				}
			}
		}
	}
	return (0);
}

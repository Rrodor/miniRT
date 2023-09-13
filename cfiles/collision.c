/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:22:53 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/13 20:32:04 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	hit_sphere(t_sp *sphere, t_ray *ray)
{
	t_vec	*oc;
	double	a;
	double	b;
	double	d;
	float	t;

	oc = vec_new(ray->ori->x - sphere->pos->x, ray->ori->y - sphere->pos->y,
			ray->ori->z - sphere->pos->z);
	a = vec_dot(ray->dir, ray->dir);
	b = 2.0 * vec_dot(oc, ray->dir);
	d = b * b - 4 * a * (vec_dot(oc, oc) - sphere->radius * sphere->radius);
	if (d > 0)
	{
		t = (-b - sqrt(d)) / (2.0 * a);
		if (t > 0 && t < 1000.0)
		{
			free(oc);
			return (t);
		}
	}
	free(oc);
	return (0);
}

double	hit_plane(t_pl *plane, t_ray *ray)
{
	double	denom;
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

double	hit_cylinder2(t_cy *cyl, t_ray *ray, t_vec arg, double t)
{
	t_pl	*plane;

	t = (-arg.y + sqrt(arg.z)) / (2.0 * arg.x);
	if (cyl->height + cyl->pos->y > ray->ori->y + t * ray->dir->y
		&& cyl->pos->y - cyl->height < ray->ori->y + t * ray->dir->y)
	{
		plane = (t_pl *)malloc(sizeof(t_pl));
		if (ray->dir->y * t + ray->ori->y > cyl->pos->y)
			plane->pos = vec_new(cyl->pos->x, cyl->pos->y
					+ cyl->height, cyl->pos->z);
		else
			plane->pos = vec_new(cyl->pos->x, cyl->pos->y
					- cyl->height, cyl->pos->z);
		plane->dir = cyl->dir;
		t = hit_plane(plane, ray);
		if (t > 0 && t < 1000.0)
			return (t);
		free(plane);
	}
	return (0);
}

double	hit_cylinder(t_cy *cyl, t_ray *ray)
{
	double	c;
	double	t;
	t_vec	arg;

	arg.x = ray->dir->x * ray->dir->x + ray->dir->z * ray->dir->z;
	arg.y = 2 * (ray->dir->x * (ray->ori->x - cyl->pos->x) + ray->dir->z
			* (ray->ori->z - cyl->pos->z));
	c = (ray->ori->x - cyl->pos->x) * (ray->ori->x - cyl->pos->x)
		+ (ray->ori->z - cyl->pos->z) * (ray->ori->z - cyl->pos->z)
		- cyl->radius * cyl->radius;
	arg.z = arg.y * arg.y - 4 * arg.x * c;
	if (arg.z > 0)
	{
		t = (-arg.y - sqrt(arg.z)) / (2.0 * arg.x);
		if (t > 0.0 && t < 1000.0)
		{
			if (cyl->height + cyl->pos->y > ray->ori->y + t * ray->dir->y
				&& cyl->pos->y - cyl->height < ray->ori->y + t * ray->dir->y)
				return (t);
			else
				t = hit_cylinder2(cyl, ray, arg, t);
			return (t);
		}
	}
	return (0);
}

float	getcollision(t_sp *obj, t_ray *ray)
{
	if (ft_strncmp(obj->id, "pl", 2) == 0)
		return (hit_plane((void *)obj, ray));
	else if (ft_strncmp(obj->id, "sp", 2) == 0)
		return (hit_sphere(obj, ray));
	else if (ft_strncmp(obj->id, "cy", 2) == 0)
		return (hit_cylinder((void *)obj, ray));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:25:02 by aramon            #+#    #+#             */
/*   Updated: 2023/09/13 20:29:22 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"
# include "color.h"

typedef struct s_sp		t_sp;
typedef struct s_pl		t_pl;
typedef struct s_cy		t_cy;
typedef struct s_rgb	t_rgb;

typedef struct s_ray
{
	t_vec		*ori;
	t_vec		*dir;
	double		tmax;
}				t_ray;

// ray.c
t_ray	*ray_new(t_vec *origin, t_vec *direction, int f);
void	ray_copy(t_ray *dst, t_ray *src);
void	ray_free(t_ray *ray);
t_vec	*ray_calculate(t_ray *ray, double t);
t_vec	*ray_at(t_ray *ray, double t);
float	getcollision(t_sp *obj, t_ray *ray);
double	hit_sphere(t_sp *sphere, t_ray *ray);
double	hit_plane(t_pl *plane, t_ray *ray);
double	hit_cylinder(t_cy *cylinder, t_ray *ray);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramon <aramon@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:11:50 by aramon            #+#    #+#             */
/*   Updated: 2023/09/05 17:22:29 by aramon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H

# define COLOR_H

#include "libft.h"

typedef struct s_ray t_ray;

typedef struct	s_rgb
{
    int			r;
    int			g;
    int			b;
}				t_rgb;

t_rgb			*init_color(double r, double g, double b);
t_rgb			*get_color(t_ray *ray, t_list *objects);
int				encode_rgb(t_rgb *rgb);
t_rgb			*lengthToColor(double t, t_rgb	*rgb);
t_rgb			*color_from_sphere(t_ray *ray, double t, t_rgb *color);
t_rgb			*color_from_plane(t_ray *ray, double t, t_rgb *color);
t_rgb			*color_from_cylinder(t_ray *ray, double t, t_rgb *color);

#endif
